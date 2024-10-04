# **************************************************************************** #
#  Makefile builtin approach
# **************************************************************************** #
UNAME	=	$(shell uname -s)
NAME	=	cub3D
RM		=	rm -fr
CFLAGS	+=	-Wall -Wextra -Werror -Iinc #-g3# -fsanitize=address
CC		=	cc
MLXFLG	+=  -Lminilibx/opengl -lmlx
MLXFLG	:=  -framework OpenGL -framework Appkit
CPPFLAGS	+=  -DSTRINGPUTX11
LIBX_DIR	+=  minilibx/opengl

OBS		+=	cub3d.dSYM	\
			.DS_Store \
			.vscode

# **************************************************************************** #
#  Project based configuration
# **************************************************************************** #
LIBC_DIR	=	zlibc
LIBC		=	$(LIBC_DIR)/libft.a
LIBX		=	$(LIBX_DIR)/libmlx.a
LDFLAGS		+=	-L$(LIBC_DIR)

# --------------------------------------------------------------------------- #"

# Source files
SRCDIR		:=	src
cleanupdir	:=	$(SRCDIR)/cleanup
debugdir	:=	$(SRCDIR)/debug
gfxdir		:=	$(SRCDIR)/gfx
parsedir	:=	$(SRCDIR)/parse
utilsdir	:=	$(SRCDIR)/utils
validdir	:=	$(SRCDIR)/validation
gfxdir		:=  $(SRCDIR)/gfx

SRC	:=	$(SRCDIR)/cub3d.c \
		$(debugdir)/debug.c \
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

ODIR	:=	obj
OBJ		:=	$(SRC:%.c=$(ODIR)/%.o)

all: $(NAME)

$(LIBX):
	@$(MAKE) -C $(LIBX_DIR)

$(LIBC):
	@$(MAKE) -C $(LIBC_DIR)

$(NAME): $(OBJ) | $(LIBC) $(LIBX)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(MLXFLG) $(OBJ) -o $(NAME) $(LIBC) $(LIBX)

$(ODIR)/%.o : %.c
	@mkdir -p $(dir $@)
	@$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

clean:
	@$(MAKE) clean -C $(LIBC_DIR)
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME) $(ODIR) $(DEBUGODIR) $(OBS)
	@$(MAKE) fclean -C $(LIBC_DIR)
	@$(MAKE) clean -C $(LIBX_DIR)

re: fclean all

.PHONY: all clean fclean re

# NO ./texture/north-StoneUWcrossL.xpm
# SO ./texture/south-StoneUWflagL.xpm
# WE ./texture/west-StoneUWHitlerD.xpm
# EA ./texture/east-StoneUWD.xpm
