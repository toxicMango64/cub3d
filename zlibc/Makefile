# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/08 15:41:48 by myousaf           #+#    #+#              #
#    Updated: 2024/10/03 21:16:35 by myousaf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	libft.a
CC		:=	cc
CFLAGS	:=	-Wall -Wextra -Werror -O3

FR		+=	$(asciidir:%.dSYM)
FR		+=	$(isdir:%.dSYM)
FR		+=	$(memdir:%.dSYM)
FR		+=	$(stringdir:%.dSYM)
FR		+=	$(stringsdir:%.dSYM)
FR		+=	$(printf:%.dSYM)
FR		+=	$(gnl:%.dSYM)

RM		:=	rm -fr

asciidir	:=	ascii
isdir		:=	ft_is
memdir		:=	mem
stringdir	:=	string
stringsdir	:=	strings
lstdir		:=	lst
utilsdir	:=	utils
printf		:=	ft_printf
gnl			:=	gnl

CFILES	:=	$(asciidir)/atoll.c \
			$(asciidir)/ft_atoi.c \
			$(asciidir)/ft_itoa.c \
			$(isdir)/ft_isalnum.c \
			$(isdir)/ft_isalpha.c \
			$(isdir)/ft_isascii.c \
			$(isdir)/ft_isdigit.c \
			$(isdir)/ft_isprint.c \
			$(isdir)/ft_isspace.c \
			$(memdir)/ft_bzero.c \
			$(memdir)/ft_calloc.c \
			$(memdir)/ft_memchr.c \
			$(memdir)/ft_memcmp.c \
			$(memdir)/ft_memcpy.c \
			$(memdir)/ft_memmove.c \
			$(memdir)/ft_memset.c \
			$(memdir)/freearr.c \
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
			$(stringdir)/strcmp_sst.c \
			$(lstdir)/ft_lstadd_back.c \
			$(lstdir)/ft_lstadd_front.c \
			$(lstdir)/ft_lstclear.c \
			$(lstdir)/ft_lstdelone.c \
			$(lstdir)/ft_lstiter.c \
			$(lstdir)/ft_lstlast.c \
			$(lstdir)/ft_lstmap.c \
			$(lstdir)/ft_lstnew.c \
			$(lstdir)/ft_lstsize.c \
			$(utilsdir)/array_size.c \
			$(utilsdir)/ft_tabdup.c

CFILES	+=	$(printf)/ft_char.c \
			$(printf)/ft_hexa.c \
			$(printf)/ft_nbr.c \
			$(printf)/ft_perr.c \
			$(printf)/ft_printf.c \
			$(printf)/ft_ptr.c \
			$(printf)/ft_putchar_fd.c \
			$(printf)/ft_putendl_fd.c \
			$(printf)/ft_putnbr_fd.c \
			$(printf)/ft_putstr_fd.c

CFILES	+=	$(gnl)/get_next_line.c \
			$(gnl)/get_next_line_utils.c

ODIR	:=	zobjdir
OBJS	:=	$(CFILES:%.c=$(ODIR)/%.o)

all:: $(NAME)

$(ODIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(ODIR)
	@ar -rcs $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(ODIR) $(NAME) $(FR)

re: fclean all

.PHONY: all clean fclean re
