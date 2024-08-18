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

.PHONY: all clean fclean re info debug

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Object files
OBJ		=	$(SRC:.c=.o)

$(LIBX):
	@make -C $(LIBX_DIR)

$(LIBC):
	@make -C $(LIBC_DIR)

$(NAME): $(OBJ) $(LIBC)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LIBC) $(OBJ) -o $(NAME)

all: MAKEFLAGS	+=	-j$(NUMPROC)
all: $(NAME) info

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	@make -C $(LIBC_DIR) fclean
	@make -C $(LIBX_DIR) clean

re: fclean all

info:
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
#	@printf "OBJ:\n	$(OBJ)\n"
	@printf "# ------------------------------------------------------------ #\n"

debug:

scan:
	@$(shell scan-build make)
