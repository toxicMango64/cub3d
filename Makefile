# **************************************************************************** #
#  Makefile builtin approachs
# **************************************************************************** #
UNAME	=	$(shell uname -s)
NAME	=	cub3D
CC		:=	cc
CFLAGS	+=	-Wall -Wextra -Werror -Iinc
RM		=	rm -fr

OBS		+=	cub3d.dSYM	\
			.DS_Store \
			.vscode

# **************************************************************************** #
#  SYSTEM SPECIFIC SETTINGS
# **************************************************************************** #
NUMPROC		:=  $(shell sysctl -n hw.ncpu)
MLXFLG		+=  -Lopengl -lmlx
MLXFLG		:=  -framework OpenGL -framework Appkit
CPPFLAGS	+=  -DSTRINGPUTX11
LIBX_DIR	+=  opengl

# **************************************************************************** #
#  Project based configuration
# **************************************************************************** #
LIBC_DIR	=	zlibc
LIBC		=	$(LIBC_DIR)/libft.a
LIBX		=	$(LIBX_DIR)/libmlx.a
LDFLAGS		+=	-L$(LIBC_DIR)

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
C			:=	\033[38;5;
O			:=	72
L			:=	m

# --------------------------------------------------------------------------- #"

# Source files
SRCDIR		:=	src
cleanupdir	:=	$(SRCDIR)/cleanup
gfxdir		:=	$(SRCDIR)/gfx
parsedir	:=	$(SRCDIR)/parse
utilsdir	:=	$(SRCDIR)/utils
validdir	:=	$(SRCDIR)/validation
gfxdir		:=  $(SRCDIR)/gfx

SRC	:=	$(SRCDIR)/cub3d.c \
		$(utilsdir)/cleanup.c \
		$(utilsdir)/init_cub3d.c \
		$(utilsdir)/gfx_cleanup.c \
		$(utilsdir)/utils.c \
		$(parsedir)/parse.c \
		$(parsedir)/parse_utils.c \
		$(validdir)/valid_map.c \
		$(validdir)/map_utils.c \
		$(validdir)/map_closed.c \
		$(gfxdir)/init_gfx.c \
		$(gfxdir)/gfx_init_utils.c \
		$(gfxdir)/init_xpm.c \
		$(gfxdir)/direction.c \
		$(gfxdir)/raycast.c \
		$(gfxdir)/draw_utils.c \
		$(gfxdir)/gfx_utils.c \
		$(gfxdir)/draw_wall.c \
		$(gfxdir)/keymap.c \
		$(gfxdir)/movement.c \
		$(gfxdir)/wallcolli.c

# Object files
ODIR	:=	obj
OBJ		:=	$(SRC:%.c=$(ODIR)/%.o)

PHONY	+= all clean cubED
all: $(NAME) cubED ## builds the project

# non-phony targets
$(LIBX):
	@$(MAKE) -sC $(LIBX_DIR)

$(LIBC):
	@$(MAKE) -sC $(LIBC_DIR)

$(NAME): $(LIBC) $(LIBX) $(OBJ)
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(MLXFLG) $(OBJ) -o $(NAME) $(LIBC) $(LIBX)

PHONY	+= build_info
$(ODIR)/%.o : %.c | build_info
	@mkdir -p $(dir $@)
	@printf "${L_BLUE}[prereq]: ${L_GREEN}%-30s ${L_BLUE}[target]: ${L_GREEN}%s${RESET}\n" "$<" "$@"
	@$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

build_info:
	@echo "${L_CYAN}[compiler info]: ${L_MAGENTA}$(CC) -c $(CFLAGS) $(CPPFLAGS)${RESET}"

PHONY	+= clean
clean: ## cleans all the obj files
	@$(MAKE) clean -C $(LIBC_DIR)
	@$(RM) $(OBJ)

PHONY	+= fclean
fclean: clean ## uses the rule clean and removes the obsolete files
	@$(RM) $(NAME) $(ODIR) $(OBS)
	@$(MAKE) fclean -C $(LIBC_DIR)
	@$(MAKE) clean -C $(LIBX_DIR)

PHONY	+= re
re: fclean all ## does fclean and all

PHONY	+= norm
norm: ## norm for .c/.h files excluding mlx files
	@norminette $(SRC) $(INC)
	@echo "all good soilder!"

PHONY	+= libx
libx: ## rebuilds the minilibx directory for the OS
	@$(MAKE) re -sC $(LIBX_DIR)

PHONY	+=	cubEd
SHIFT	=	$(eval O=$(shell echo $$((($(O)%15)+1))))
cubED: ## prints a fun little CUB3D ASCII art
	@echo "$(C)$(O)$(L)# -------------------------------------------------------------------------------- #$(RESET)"
	@echo "$(C)$(O)$(L) ______     __  __     ______     ______     _____    ";
	@echo "$(C)$(O)$(L)/\  ___\   /\ \/\ \   /\  == \   /\___  \   /\  __ \  ";
	$(SHIFT)
	@echo "$(C)$(O)$(L)\ \ \____  \ \ \_\ \  \ \  __<   \/_\___ \  \ \ \_\ \ ";
	@echo "$(C)$(O)$(L) \ \_____\  \ \_____\  \ \_____\  /\______\  \ \____/ ";
	$(SHIFT)
	@echo "$(C)$(O)$(L)  \/_____/   \/_____/   \/_____/  \/______/   \/____/ ";
	@echo "$(C)$(O)$(L)                                                      ";
	@echo "$(C)$(O)$(L)# -------------------------------------------------------------------------------- #$(RESET)"

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
	@echo "${L_GREEN}BUILD MODE${RESET}	:	${L_MAGENTA}${mode}${RESET}"
	@echo "${L_GREEN}SRC${RESET}		:\n	${L_BLUE}${SRC}${RESET}"
	@echo "${L_CYAN}# -------------------------------------------------------------------------------- #$(RESET)"

PHONY	+= help
help: ## prints a list of the possible commands
	@echo "${L_CYAN}# ---------------------------------------------------------------- #$(RESET)"
	@printf "${L_MAGENTA}%-15s ${RESET}${L_BLUE}make [<option>...]${RESET}\n\n" "Usage:"
	@printf "${L_MAGENTA}Option:${RESET}\n"
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; \
	{printf "${L_GREEN}%-15s ${L_BLUE}%s${RESET}\n", $$1, $$2}'
	@printf "%-15s ${L_BLUE}This MAKE has Super Cow Powers.${RESET}\n"
	@echo "${L_CYAN}# ---------------------------------------------------------------- #$(RESET)"

.DEFAULT:
	@echo "${L_RED}[Error]${RESET}: ${L_BLUE}\tUnknown target '${L_RED}$@${L_BLUE}'.${RESET}"
	@${MAKE} -s help

.PHONY: $(PHONY)
