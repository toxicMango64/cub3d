.DEFAULT_GOAL = utils.a
NAME = utils.a

CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs

OBJDIR = objects

INC	=	ft_printf/ft_printf.h gnl/get_next_line.h
SRC	=	$(addprefix ft_printf/, ft_hexa.c ft_nbr.c ft_perr.c ft_char.c ft_ptr.c \
		ft_printf.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_putstr_fd.c) \
		$(addprefix gnl/, get_next_line.c get_next_line_utils.c)

OBJ = $(patsubst %.c, $(OBJDIR)/%.o, $(notdir $(SRC)))

$(OBJDIR)/%.o : ft_printf/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/%.o : gnl/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(NAME) : $(OBJ)
	@$(AR) $(NAME) $(OBJ)

all: $(NAME)

clean:
	@$(RM)r $(OBJDIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

# .DEFAULT_GOAL = utils.a
# NAME = utils.a

# CC = cc
# AR = ar rcs
# CFLAGS = -Wall -Werror -Wextra

# OBJDIR = objects

# INC	=	ft_printf/ft_printf.h gnl/get_next_line.h
# SRC	=	$(addprefix ft_printf/, ft_hexa.c ft_nbr.c ft_perr.c ft_char.c ft_ptr.c \
# 		ft_printf.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
# 		ft_putstr_fd.c) \
# 		$(addprefix gnl/, get_next_line.c get_next_line_utils.c)

# OBJ = $(patsubst %.c, $(OBJDIR)/%.o, $(notdir $(SRC)))

# $(OBJDIR)/%.o : ft_printf/%.c | $(OBJDIR)
# 	@$(CC) $(CFLAGS) -c -o $@ $<

# $(OBJDIR)/%.o : gnl/%.c | $(OBJDIR)
# 	@$(CC) $(CFLAGS) -c -o $@ $<

# $(OBJDIR):
# 	@mkdir -p $(OBJDIR)

# $(NAME) : $(OBJ)
# 	@$(AR) $(NAME) $(OBJ)

# all: $(NAME)

# clean:
# 	@$(RM)r $(OBJDIR)

# fclean: clean
# 	@$(RM) $(NAME)

# re: fclean all

# .PHONY: all clean fclean re








#research pupose!
# NAME = utils.a

# CC = cc
# AR = ar rcs
# CFLAGS = -Wall -Werror -Wextra

# PRINTF = printf/
# GNIGGN = gnl/
# OBJDIR = objects/

# INC = $(PRINTF)ft_printf.h $(GNIGGN)get_next_line.h
# SRC = $(addprefix $(PRINTF), ft_hexa.c ft_nbr.c ft_perr.c ft_printf.c \
# 		ft_ptr.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c) \
# 		$(addprefix $(GNIGGN), get_next_line.c get_next_line_utils.c)

# OBJ = $(patsubst %.c, $(OBJDIR)%.o, $(notdir $(SRC)))

# $(OBJDIR)%.o : $(PRINTF)%.c Makefile $(INC) | $(OBJDIR)
# 	$(CC) $(CFLAGS) -c -o $@ $<

# $(OBJDIR)%.o : $(GNIGGN)%.c Makefile $(INC) | $(OBJDIR)
# 	$(CC) $(CFLAGS) -c -o $@ $<

# $(OBJDIR):
# 	mkdir -p $(OBJDIR)

# $(NAME) : $(OBJ)
# 	$(AR) $(NAME) $(OBJ)
# 	mv $(NAME) ..

# all: $(NAME)

# clean:
# 	$(RM) $(OBJ)

# fclean: clean
# 	$(RM) ../$(NAME)

# re: fclean all

# .PHONY: all clean fclean re