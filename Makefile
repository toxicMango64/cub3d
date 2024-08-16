# **************************************************************************** #
# Makefile builtin approach
# **************************************************************************** #
UNAME		:=	$(shell uname -s)
NAME		=	cub3d
CFLAGS		+=	-Wall -Wextra -Werror -Ofast -Iinc -g3
LDFLAGS		+=	-L$(LIBFT_DIR) -lft

# **************************************************************************** #
#   SYSTEM SPECIFIC SETTINGS                                                   #
# **************************************************************************** #
ifeq ($(UNAME), Linux)
	CC		=	gcc
	CFLAGS	+=	-D LINUX -Wno-unused-result
	NUMPROC	:=	$(shell grep -c ^processor /proc/cpuinfo)
else ifeq ($(UNAME), Darwin)
	CC		=	cc
	NUMPROC := $(shell sysctl -n hw.ncpu)
endif

LIBFT_DIR	=	zlibft
LIBFT		=	$(LIBFT_DIR)/libft.a
RM			=	rm -f

SRCDIR		=	src
PARSEDIR	=	$(SRCDIR)/parse
UTILSDIR	=	$(SRCDIR)/utils
DEBUGDIR	=	$(SRCDIR)/debug

# Source files
SRCS		=	$(SRCDIR)/cub3d.c \
				$(PARSEDIR)/parse.c \
				$(UTILSDIR)/utils.c \
				$(DEBUGDIR)/debug.c

# Object files
# OBJS		=	$(SRCS:.c=.o)

.PHONY: all clean fclean re info update_makefile

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

all: MAKEFLAGS	+=	-j$(NUMPROC)
all: $(NAME)

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

# Self-modifying rule
update_makefile:
# 	@find $(SRCDIR) -name "*.c" | sort > new_files.txt
# 	@grep -oE '\b\w+\.c\b' Makefile | sort > existing_files.txt
# 	@comm -23 new_files.txt existing_files.txt > new_files_to_add.txt
# 	while read file; do \
# 		echo "SRCS += $$file" >> Makefile; \
# 		echo "OBJS += $${file/.c/.o}" >> Makefile; \
# 	done < new_files_to_add.txt
# 	@rm new_files.txt existing_files.txt new_files_to_add.txt

# SRCS += src/cub3d.c
# SRCS += src/cub3d.c
# SRCS += src/cub3d.c
