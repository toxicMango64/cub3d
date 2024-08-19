#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_unsignednbr(unsigned int n);
int		ft_lilx(unsigned int num);
int		ft_bigx(unsigned int num);
int		ft_ptrx(unsigned long num);
void	ft_border(size_t i);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/* -- Error and Debug finctions -- */

/**
 * border function used by perr and mperr to
 * out line the borders of the error
 * message printed.
*/
void	ft_border(size_t i);

/**
 * writes an error message sent as parameters
 * exits with error code int_status.
*/
void	perr(char *str, int int_status);

/**
 * writes an error message sent as parameters
 * with a meme of your choice.
 * exits with error code 1.
*/
void	mperr(char *str);

/**
 * writes an error message sent as parameters
 * exits with error code 1.
*/
void	ft_error(char *str);

#endif
