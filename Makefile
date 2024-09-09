# **************************************************************************** #
# Makefile builtin approach
# **************************************************************************** #
UNAME	=	$(shell uname -s)
NAME	=	cub3d
RM		=	rm -fr
CFLAGS	+=	-Wall -Wextra -Werror -Ofast -Iinc
OBS		+=	cub3d.dSYM	\
			.DS_Store \
			.vscode

ifeq ($(UNAME), Darwin) # mac
	CC	:= cc
else ifeq ($(UNAME), FreeBSD) # FreeBSD
	CC	:= clang
else # linux or others
	CC		:=	gcc -M
	LDFLAGS	+=	-lbsd
endif

# **************************************************************************** #
#   SYSTEM SPECIFIC SETTINGS
# **************************************************************************** #
ifeq ($(UNAME), Linux)
	LIBX_DIR	+=	minilibx/linux
	CPPFLAGS	+=	-D LINUX -Wno-unused-result
	NUMPROC		:=	$(shell grep -c ^processor /proc/cpuinfo)
else ifeq ($(UNAME), Darwin)
	LIBX_DIR	+=	minilibx/opengl
	NUMPROC		:= $(shell sysctl -n hw.ncpu)
endif

# **************************************************************************** #
#   Project based configuration
# **************************************************************************** #
CPPFLAGS	+=	-g3 -fsanitize=address
LDFLAGS		+=	-L$(LIBC_DIR) -lft

LIBC_DIR	=	zlibc
LIBC		=	$(LIBC_DIR)/libft.a \
				utils/utils.a
LIBX		=	$(LIBX_DIR)/libmlx.a

TEXTTURE_DIR	=	texture
TEXTTURE_FILES	=	$(TEXTTURE_DIR)/east_texture \
					$(TEXTTURE_DIR)/north_texture \
					$(TEXTTURE_DIR)/south_texture \
					$(TEXTTURE_DIR)/west_texture

SRCDIR		=	src
GFXDIR		=	$(SRCDIR)/gfx
UTILSDIR	=	$(SRCDIR)/utils
DEBUGDIR	=	$(SRCDIR)/debug
PARSEDIR	=	$(SRCDIR)/parse

# Source files
SRC			=	$(SRCDIR)/cub3d.c \
				$(PARSEDIR)/parse.c \
				$(UTILSDIR)/init_cub3d.c \
				$(DEBUGDIR)/print_debug.c
#				$(GFXDIR)/gfx.c
#				$(UTILSDIR)/utils.c

# **************************************************************************** #
# Define the colors
# **************************************************************************** #
GB				:=	\033[42m
RESET			:=	\033[0m
RED				:=	\033[0;31m
WHITE			:=	\033[0;97m
BLUE			:=	\033[0;34m
GRAY			:=	\033[0;90m
CYAN			:=	\033[0;36m
BLACK			:=	\033[0;30m
GREEN			:=	\033[0;32m
YELLOW			:=	\033[0;33m
MAGENTA			:=	\033[0;35m
BLUE			:=	\033[0;36m
LIGHT_RED		:=	\033[0;91m
LIGHT_GRAY		:=	\033[0;37m
LIGHT_BLUE		:=	\033[0;94m
LIGHT_CYAN		:=	\033[0;96m
LIGHT_GREEN		:=	\033[0;92m
LIGHT_YELLOW	:=	\033[0;93m
LIGHT_MAGENTA	:=	\033[0;95m

# --------------------------------------------------------------------------- #"

.PHONY: all clean fclean re info debug scan help checktexture

all:: MAKEFLAGS	+=	-j$(NUMPROC) ## builds the project
all:: $(checktexture) $(NAME) info

# Define a pattern rule that compiles every .c file into a .o file
# Ex 1: .o files depend on .c files. Though we don't actually make the .o file.
%.o : %.c
	@echo "target: $@\t\tprereq: $<"
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

# Object files
OBJ		=	$(SRC:.c=.o)

$(LIBX):
	@$(MAKE) -sC $(LIBX_DIR)

$(LIBC):
	@$(MAKE) -sC utils
	@$(MAKE) -sC $(LIBC_DIR)

$(NAME): $(OBJ) $(LIBC)
	@echo "build cflags: $(CFLAGS)"
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LIBC) $(OBJ) -o $(NAME)

TEXTURES = east north south west

checktexture:
	@for texture in $(TEXTURES); do \
		if [ ! -f $(TEXTTURE_DIR)/$$texture\_texture ]; then \
			echo "$$texture texture does not exist"; \
		fi; \
	done
	@echo "texture exist 🎊";

clean: ## cleans all the obj files
	@$(MAKE) clean -C $(LIBC_DIR)
	$(RM) $(OBJ)

fclean: clean ## uses the rule clean and removes the obsolete files
	$(RM) $(NAME) $(OBS)
	@$(MAKE) fclean -C $(LIBC_DIR)
	@$(MAKE) clean -C $(LIBX_DIR)

re: fclean all ## does fclean and all

info: ## prints project based info
	@echo "${LIGHT_CYAN}# ---------------------------------------------------------------- #$(RESET)"
	@echo "${LIGHT_GREEN}NAME${RESET}		:	${LIGHT_MAGENTA}${NAME}${RESET}"
	@echo "${LIGHT_GREEN}CC${RESET}		:	${LIGHT_MAGENTA}${CC}${RESET}"
	@echo "${LIGHT_GREEN}CFLAGS${RESET}		:	${LIGHT_MAGENTA}${CFLAGS}${RESET}"
	@echo "${LIGHT_GREEN}LDFLAGS${RESET}		:	${LIGHT_MAGENTA}${LDFLAGS}${RESET}"
	@echo "${LIGHT_GREEN}CPPFLAGS${RESET}	:	${LIGHT_MAGENTA}${CPPFLAGS}${RESET}"
	@echo "${LIGHT_GREEN}LIBX${RESET}		:	${LIGHT_MAGENTA}${LIBX}${RESET}"
	@echo "${LIGHT_GREEN}UNAME${RESET}		:	${LIGHT_MAGENTA}${UNAME}${RESET}"
	@echo "${LIGHT_GREEN}NUMPROC${RESET}		:	${LIGHT_MAGENTA}${NUMPROC}${RESET}"
	@echo "${LIGHT_GREEN}MAKEFLAGS${RESET}	:	${LIGHT_MAGENTA}${MAKEFLAGS}${RESET}"
	@echo "${LIGHT_GREEN}texture files${RESET}	:\n	${LIGHT_BLUE}${TEXTTURE_FILES}${RESET}"
	@echo "${LIGHT_GREEN}SRC${RESET}		:\n	${LIGHT_BLUE}${SRC}${RESET}"
	@echo "${LIGHT_CYAN}# ---------------------------------------------------------------- #$(RESET)"

debug: ## add your debug flags before calling all rule
	CFLAGS	+=	-g3 -fsanitize=address --analyzer

scan: ## uses scan-build on make all (prerequisite clan-18)
	@$(shell scan-build-18 $(MAKE))

run: ## runs a test case for you "./cub3D maps/map.cub"
	@$(shell ./cub3D maps/map.cub)

help: ## prints a list of the possible commands
	@echo "${LIGHT_CYAN}# ---------------------------------------------------------------- #$(RESET)"
	@echo "${LIGHT_MAGENTA}Usage:${RESET}"
#	@sed -n 's/^##//p' ${MAKEFILE_LIST} | column -t -s ':' | sed -e 's/^/-/'
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; \
	{printf "${LIGHT_GREEN}%-20s ${LIGHT_BLUE}%s${RESET}\n", $$1, $$2}'
	@echo "${LIGHT_CYAN}# ---------------------------------------------------------------- #$(RESET)"
