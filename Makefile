# **************************************************************************** #
#  Makefile builtin approach
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
	CC	:=	clang
else ifeq ($(UNAME), Linux) # linux or others
#	CC	:=	gcc
	CC	:=	clang-18
endif

# **************************************************************************** #
#  SYSTEM SPECIFIC SETTINGS
# **************************************************************************** #
ifeq ($(UNAME), Linux)
	LIBX_DIR	+=	minilibx/linux
	MLXFLG		:=	-lXext -lX11
	CPPFLAGS	+=	-D LINUX -Wno-unused-result
	NUMPROC		:=	$(shell grep -c ^processor /proc/cpuinfo)
else ifeq ($(UNAME), Darwin)
	LIBX_DIR	+=	minilibx/opengl
	MLXFLG		+=	-Lminilibx/opengl -lmlx
	MLXFLG		:=	-framework OpenGL -framework Appkit
	CPPFLAGS	+=	-DSTRINGPUTX11
	NUMPROC		:= $(shell sysctl -n hw.ncpu)
endif

# **************************************************************************** #
#  Project based configuration
# **************************************************************************** #
LDFLAGS		+=	-L$(LIBC_DIR) -lft

LIBC_DIR	=	zlibc
LIBC		=	$(LIBC_DIR)/libft.a \
				utils/utils.a
LIBX		=	$(LIBX_DIR)/libmlx.a

# Source files
ifeq ($(UNAME), Linux)
	SRC		:=	${shell find . -regex '.+\.c$$' | grep "src"}
else ifeq ($(UNAME), Darwin)
	SRC		:=	${shell find -E . -regex '.+\.c' | grep "src"}
endif

# **************************************************************************** #
# Define the colors
# **************************************************************************** #
GB			:=	\033[42m
RESET		:=	\033[0m
RED			:=	\033[0;31m
WHITE		:=	\033[0;97m
BLUE		:=	\033[0;34m
GRAY		:=	\033[0;90m
CYAN		:=	\033[0;36m
BLACK		:=	\033[0;30m
GREEN		:=	\033[0;32m
YELLOW		:=	\033[0;33m
MAGENTA		:=	\033[0;35m
BLUE		:=	\033[0;36m
L_RED		:=	\033[0;91m
L_GRAY		:=	\033[0;37m
L_BLUE		:=	\033[0;94m
L_CYAN		:=	\033[0;96m
L_GREEN		:=	\033[0;92m
L_YELLOW	:=	\033[0;93m
L_MAGENTA	:=	\033[0;95m

# --------------------------------------------------------------------------- #"

PHONY	+= all
all:: MAKEFLAGS	+=	-j$(NUMPROC) ## builds the project
# all:: checktexture $(NAME) info # uncomment when subbmiting
all:: $(NAME) info

PHONY	+= debug
# debug:: $(TARGET_DEBUG)
debug:: CFLAGS	+=	-g3 -fsanitize=address ## add your debug flags before calling all rule
debug:: $(NAME)

# non-phony targets
# Object files
OBJ		=	$(SRC:.c=.o)
OBJ_DEBUG	=	$(SRC:.c=.o)

$(LIBX):
	@$(MAKE) -sC $(LIBX_DIR)

$(LIBC):
	@$(MAKE) -sC utils
	@$(MAKE) -sC $(LIBC_DIR)

$(NAME): $(LIBC) $(OBJ)
#	@echo "build cflags: $(CFLAGS)"
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(MLXFLG) $(OBJ) $(LIBC) $(LIBX) -o $(NAME)

$(TARGET_DEBUG): $(LIBC) $(OBJ_DEBUG)
#	@echo "build cflags: $(CFLAGS)"
	@$(CC) $(DBGFLAGS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(MLXFLG) $(OBJ_DEBUG) $(LIBC) $(LIBX) -o $(NAME)

PHONY	+= compiler_info
# Define a pattern rule that compiles every .c file into a .o file
# Ex 1: .o files depend on .c files. Though we don't actually make the .o file.
%.o : %.c | compiler_info
	@printf "${L_BLUE}[prereq]: ${L_GREEN}%-30s ${L_BLUE}[target]: ${L_GREEN}%s${RESET}\n" "$<" "$@"
	@$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

compiler_info:
	@echo "${L_CYAN}[compiler info]: ${L_MAGENTA}$(CC) -c $(CFLAGS) $(CPPFLAGS)${RESET}"

PHONY	+= checktexture

TEXTURES = east north south west
checktexture:
	@for texture in $(TEXTURES); do \
		if [ ! -f $(TEXTTURE_DIR)/$$texture\_texture ]; then \
			echo "$$texture texture does not exist"; \
		fi; \
	done
	@echo "texture exist 🎊";

PHONY	+= clean
clean: ## cleans all the obj files
	@$(MAKE) clean -C $(LIBC_DIR)
	@$(RM) $(OBJ)

PHONY	+= fclean
fclean: clean ## uses the rule clean and removes the obsolete files
	@$(RM) $(NAME) $(OBS)
	@$(MAKE) fclean -C $(LIBC_DIR)
#	@$(MAKE) clean -C $(LIBX_DIR)

PHONY	+= re
re: fclean all ## does fclean and all

PHONY	+= norm
norm: ## norm for .c/.h files excluding mlx files
	@norminette -d $(SRC)
	@echo "all good soilder!"

PHONY	+= info
info: ## prints project based info
	@echo "${L_CYAN}# -------------------------------------------------------------------------------- #$(RESET)"
	@echo "${L_GREEN}NAME${RESET}		:	${L_MAGENTA}${NAME}${RESET}"
	@echo "${L_GREEN}UNAME${RESET}		:	${L_MAGENTA}${UNAME}${RESET}"
	@echo "${L_GREEN}NUMPROC${RESET}		:	${L_MAGENTA}${NUMPROC}${RESET}"
	@echo "${L_GREEN}CC${RESET}		:	${L_MAGENTA}${CC}${RESET}"
	@echo "${L_GREEN}CFLAGS${RESET}		:	${L_MAGENTA}${CFLAGS}${RESET}"
	@echo "${L_GREEN}LDFLAGS${RESET}		:	${L_MAGENTA}${LDFLAGS}${RESET}"
	@echo "${L_GREEN}CPPFLAGS${RESET}	:	${L_MAGENTA}${CPPFLAGS}${RESET}"
	@echo "${L_GREEN}MAKEFLAGS${RESET}	:	${L_MAGENTA}${MAKEFLAGS}${RESET}"
	@echo "${L_GREEN}LIBX${RESET}		:	${L_MAGENTA}${LIBX}${RESET}"
	@echo "${L_GREEN}texture files${RESET}	:\n	${L_BLUE}${TEXTURE_FILES}${RESET}"
	@echo "${L_GREEN}SRC${RESET}		:\n	${L_BLUE}${SRC}${RESET}"
	@echo "${L_CYAN}# -------------------------------------------------------------------------------- #$(RESET)"

PHONY	+= scan
scan: ## uses scan-build on make all (prerequisite clan-18)
	@$(shell scan-build-18 $(MAKE))

PHONY	+= run
run: ## runs a test case for you "./cub3D maps/map.cub"
	@$(shell ./cub3D maps/map.cub)

PHONY	+= help
help: ## prints a list of the possible commands
	@echo "${L_CYAN}# ---------------------------------------------------------------- #$(RESET)"
	@echo "${L_MAGENTA}Usage:${RESET}"
#	@sed -n 's/^##//p' ${MAKEFILE_LIST} | column -t -s ':' | sed -e 's/^/-/'
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; \
	{printf "${L_GREEN}%-20s ${L_BLUE}%s${RESET}\n", $$1, $$2}'
	@echo "${L_CYAN}# ---------------------------------------------------------------- #$(RESET)"

.DEFAULT:
	@echo "${L_CYAN}# ---------------------------------------------------------------- #$(RESET)"
	@echo "${L_RED}[Error]:${RESET} ${L_BLUE}\tUnknown target '$@'."
	@echo ""
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; \
	{printf "${L_GREEN}%-15s ${L_BLUE}%s${RESET}\n", $$1, $$2}'
	@echo "${L_CYAN}# ---------------------------------------------------------------- #$(RESET)"

.PHONY: $(PHONY)
