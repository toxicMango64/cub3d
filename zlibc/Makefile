# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myousaf <myousaf@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/08 15:41:48 by myousaf           #+#    #+#              #
#    Updated: 2024/09/21 21:27:40 by myousaf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

NAME	:=	libft.a
CC		:=	cc
CFLAGS	:=	-Wall -Wextra -Werror -O3
# LDFLAGS	:=	-g3 -O2 -fsanitize=address
ifeq ($(shell uname -s), Linux)
	CFLAGS += -D LINUX -Wno-unused-result
endif

FR		+=	$(asciidir:%.dSYM)
FR		+=	$(isdir:%.dSYM)
FR		+=	$(printf:%.dSYM)
FR		+=	$(memdir:%.dSYM)
FR		+=	$(stringdir:%.dSYM)
FR		+=	$(stringsdir:%.dSYM)

RM		:=	rm -fr

asciidir	:=	./ascii
isdir		:=	./ft_is
printf		:=	./ft_printf
memdir		:=	./mem
stringdir	:=	./string
stringsdir	:=	./strings
lstdir		:=	./lst

CFILES	:=	$(asciidir)/atoll.c \
			$(asciidir)/ft_atoi.c \
			$(asciidir)/ft_itoa.c \
			$(isdir)/ft_isalnum.c \
			$(isdir)/ft_isalpha.c \
			$(isdir)/ft_isascii.c \
			$(isdir)/ft_isdigit.c \
			$(isdir)/ft_isprint.c \
			$(printf)/ft_char.c \
			$(printf)/ft_hexa.c \
			$(printf)/ft_nbr.c \
			$(printf)/ft_perr.c \
			$(printf)/ft_printf.c \
			$(printf)/ft_ptr.c \
			$(printf)/ft_putchar_fd.c \
			$(printf)/ft_putendl_fd.c \
			$(printf)/ft_putnbr_fd.c \
			$(printf)/ft_putstr_fd.c \
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
			$(lstdir)/ft_lstsize.c

ODIR	:=	zobjdir
OBJS	:=	$(CFILES:%.c=$(ODIR)/%.o)

.PHONY: all clean fclean re

ifeq ($(UNAME), Linux)
	NUMPROC := $(shell grep -c ^processor /proc/cpuinfo)
	@echo $(NUMPROC)
else ifeq ($(UNAME), Darwin)
	NUMPROC := $(shell sysctl -n hw.ncpu)
	@echo $(NUMPROC)
endif

all:: MAKEFLAGS	+=	-j$(NUMPROC) ## builds the project
all:: $(NAME)


# Ex 1: .o files depend on .c files. Though we don't actually make the .o file.
$(ODIR)/%.o: %.c
	@mkdir -p $(dir $@)
#	@printf "${L_BLUE}prereq: ${L_GREEN}%-30s ${L_BLUE}target: ${L_GREEN}%s${RESET}\n" "$<" "$@"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(ODIR)
	@ar -rcs $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(ODIR) $(NAME) $(FR)

re: fclean all

# info: MAKEFLAGS	+=	-j$(NUMPROC)
info:
	@echo "# ---------------------------------------------------------------- #"
	@echo "UNAME		:	${UNAME}"
	@echo "NUMPROC		:	${NUMPROC}"
	@echo "MAKEFLAGS	:	${MAKEFLAGS}"
	@echo "NAME		:	${NAME}"
	@echo "CC		:	${CC}"
	@echo "CFLAGS		:	${CFLAGS}"
	@echo "LDFLAGS		:	${LDFLAGS}"
	@echo "LIBX		:	${LIBX}"
	@echo "texture files	:\n	${TEXTTURE_FILES}"
	@echo "SRC:\n	${CFILES}"
	@echo "# ---------------------------------------------------------------- #"
