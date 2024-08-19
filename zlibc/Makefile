# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/08 15:41:48 by myousaf           #+#    #+#              #
#    Updated: 2024/05/06 10:55:01 by myousaf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	libft.a
CC		:=	cc
CFLAGS	:=	-Wall -Wextra -Werror -g3 -O2 -fsanitize=address
# LDFLAGS	:=	-g3 -O2 -fsanitize=address
ifeq ($(shell uname -s), Linux)
	CFLAGS += -D LINUX -Wno-unused-result
endif

FR		+=	$(asciidir:%.dSYM)
FR		+=	$(ft_isdir:%.dSYM)
FR		+=	$(ft_printfdir:%.dSYM)
FR		+=	$(memdir:%.dSYM)
FR		+=	$(stringdir:%.dSYM)
FR		+=	$(stringsdir:%.dSYM)

RM		:=	rm -fr

asciidir		:=	./ascii
ft_isdir		:=	./ft_is
ft_printfdir	:=	./ft_printf
memdir			:=	./mem
stringdir		:=	./string
stringsdir		:=	./strings

CFILES			:=	$(asciidir)/atoll.c \
					$(asciidir)/ft_atoi.c \
					$(asciidir)/ft_itoa.c \
					$(ft_isdir)/ft_isalnum.c \
					$(ft_isdir)/ft_isalpha.c \
					$(ft_isdir)/ft_isascii.c \
					$(ft_isdir)/ft_isdigit.c \
					$(ft_isdir)/ft_isprint.c \
					$(ft_printfdir)/ft_char.c \
					$(ft_printfdir)/ft_hexa.c \
					$(ft_printfdir)/ft_nbr.c \
					$(ft_printfdir)/ft_perr.c \
					$(ft_printfdir)/ft_printf.c \
					$(ft_printfdir)/ft_ptr.c \
					$(ft_printfdir)/ft_putchar_fd.c \
					$(ft_printfdir)/ft_putendl_fd.c \
					$(ft_printfdir)/ft_putnbr_fd.c \
					$(ft_printfdir)/ft_putstr_fd.c \
					$(memdir)/ft_bzero.c \
					$(memdir)/ft_calloc.c \
					$(memdir)/ft_memchr.c \
					$(memdir)/ft_memcmp.c \
					$(memdir)/ft_memcpy.c \
					$(memdir)/ft_memmove.c \
					$(memdir)/ft_memset.c \
					$(stringdir)/ft_split.c \
					$(stringdir)/ft_strchr.c \
					$(stringdir)/ft_strdup.c \
					$(stringdir)/ft_striteri.c \
					$(stringdir)/ft_strjoin.c \
					$(stringdir)/ft_strlcat.c \
					$(stringdir)/ft_strlcpy.c \
					$(stringdir)/ft_strlen.c \
					$(stringdir)/ft_strmapi.c \
					$(stringdir)/ft_strncmp.c \
					$(stringdir)/ft_strnstr.c \
					$(stringdir)/ft_strrchr.c \
					$(stringdir)/ft_strtrim.c \
					$(stringdir)/ft_substr.c \
					$(stringdir)/ft_tolower.c \
					$(stringdir)/ft_toupper.c \
					$(stringdir)/strcmp_sst.c

ODIR	:=	zobjdir
OBJS	:=	$(CFILES:%.c=$(ODIR)/%.o)

.PHONY: all clean fclean re

ifeq ($(UNAME), Linux)
	NUMPROC := $(shell grep -c ^processor /proc/cpuinfo)
else ifeq ($(UNAME), Darwin)
	NUMPROC := $(shell sysctl -n hw.ncpu)
endif

all: 
	@$(MAKE) -j$(NUMPROC) $(NAME)

$(ODIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(ODIR)
	ar -rcs $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(ODIR) $(NAME) $(FR)

re: fclean all

$(NAME): $(CFILES)

$(OFILES): $(CFILES)

$(RM): $(OFILES)

info: MAKEFLAGS	+=	-j$(NUMPROC)
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
	@printf "SRC:\n	$(shell ls ./*)\n"
	@printf "OBJ:\n	$(OBJ)\n"
	@printf "# ------------------------------------------------------------ #\n"
