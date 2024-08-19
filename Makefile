# **************************************************************************** #
# Makefile builtin approach
# **************************************************************************** #
UNAME	:=	$(shell uname -s)
NAME	=	cub3d
RM		=	rm -fr

ifeq ($(UNAME), Darwin) # mac
	CC	= cc
else ifeq ($(UNAME), FreeBSD) # FreeBSD
	CC	= clang
else # linux or others
	CC		=	gcc -M
	LDFLAGS	+=	-lbsd
endif

# **************************************************************************** #
#   SYSTEM SPECIFIC SETTINGS
# **************************************************************************** #
ifeq ($(UNAME), Linux)
	LIBX_DIR	+=	minilibx/linux
	CFLAGS		+=	-D LINUX -Wno-unused-result
	NUMPROC		:=	$(shell grep -c ^processor /proc/cpuinfo)
else ifeq ($(UNAME), Darwin)
	LIBX_DIR	+=	minilibx/opengl
	NUMPROC		:= $(shell sysctl -n hw.ncpu)
endif

# **************************************************************************** #
#   Project based configuration
# **************************************************************************** #
CFLAGS		+=	-Wall -Wextra -Werror -Ofast -Iinc
CFLAGS		+=	-g3 -fsanitize=address
LDFLAGS		+=	-L$(LIBC_DIR) -lft

LIBC_DIR	=	zlibc
LIBC		=	$(LIBC_DIR)/libft.a
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
				$(PARSEDIR)/parse.c
#				$(DEBUGDIR)/print_debug.c
#				$(GFXDIR)/gfx.c
#				$(UTILSDIR)/utils.c

# --------------------------------------------------------------------------- #"

.PHONY: all clean fclean re info debug

all: MAKEFLAGS	+=	-j$(NUMPROC)
all: $(NAME) info
## all: builds the project

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Object files
OBJ		=	$(SRC:.c=.o)

$(LIBX):
	@make -sC $(LIBX_DIR)

$(LIBC):
	@make -sC utils
	@make -sC $(LIBC_DIR)

$(NAME): $(OBJ) $(LIBC)
	@echo "build cflags: $(CFLAGS)"
	$(CC) $(CFLAGS) $(LDFLAGS) $(LIBC) utils/utils.a $(OBJ) -o $(NAME)

clean:
## clean: cleans all the obj files
	$(RM) $(OBJ)

fclean: clean
## fclean: uses the rule clean and removes the obsolete files
	$(RM) $(NAME)
	@make -C $(LIBC_DIR) fclean
	@make -C $(LIBX_DIR) clean

re: fclean all
## re: does fclean and all

info:
## info: prints project based info
	@printf "# ------------------------------------------------------------ #\n"
	@printf "UNAME		:	$(UNAME)\n"
	@printf "NUMPROC		:	$(NUMPROC)\n"
	@printf "MAKEFLAGS	:	$(MAKEFLAGS)\n"
	@printf "NAME		:	$(NAME)\n"
	@printf "CC		:	$(CC)\n"
	@printf "CFLAGS		:	$(CFLAGS)\n"
	@printf "LDFLAGS		:	$(LDFLAGS)\n"
	@printf "LIBX		:	$(LIBX)\n"
	@printf "texture files	:\n	$(TEXTTURE_FILES)\n"
	@printf "SRC:\n	$(SRC)\n"
	@printf "# ------------------------------------------------------------ #\n"

debug:

scan:
	@$(shell scan-build make)

help:
## help: prints a list of the possible commands
	@echo "Usage: \n"
	@sed -n 's/^##//p' ${MAKEFILE_LIST} | column -t -s ':' | sed -e 's/^/-/'
