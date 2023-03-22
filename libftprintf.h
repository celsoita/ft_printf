#ifndef	LIBFTPRINTF_H 
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printstring(char *str);
int		ft_printfchar(int k);
int		ft_print_d(int n);
int		ft_print_x(unsigned int n, char check);
int		ft_printf(const char *str, ...);
int		ft_printfu(unsigned int n);
int		ft_printfp(unsigned long int n);

#endif