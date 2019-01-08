#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "libft.h"
# include <stdarg.h>

// typedef struct 	s_data
// {
// 	char *data;
// 	char min;
// 	char plus;
// 	char flag;
// 	char type;
// }				t_data;
char	*ft_itoa_li(long int value, int base);
char	*ft_itoa_lli(long long int value, int base);
char	*ft_itoa_uli(unsigned long int value, int base);
char	*ft_itoa_ulli(unsigned long long int value, int base);

typedef struct 	d_fill
{
	char *zero_prec;
	char *space_width;
	char *znak;
}				t_fill;

typedef struct 	s_data
{
	char *data;
    char *flag;
    char *width;
    char *prec;
    char *spec;
	char type;
	char *output;
	char *result;
	int memory;
	t_fill dfill;
	//va_list list;
	char	*buff;
	int 	printf_size;
}				t_data;

int		ft_printf(const char *format, ...);

void obnull_dfill(t_data  *f);
void empty_struct(t_data *f);
void free_fill_mem(t_data  *f);
void free_all_mem(t_data  *f);

void fill__dfill(t_data  *f);
void fill__sfill(t_data  *f);

int     validinput(const char *s);
int     check_data(const char *s, int *cnt_i, t_data *f);
int 	check_type(char c, t_data *f);
int 	check_flags(char c);

void	def_all(t_data *f);

void    def_type(va_list list, t_data *i);
char	*create_char(int n);

int		print_res(t_data *f);

int		cnt_mem_d(t_data *f);
int	    cnt_mem_s(t_data *f);
//обработка 
int d_treat(t_data  *f);
int s_treat(t_data  *f);

char *creat_s_prec(t_data  *f, char symb);
char *creat_s_width(t_data  *f, char symb);

void join_data_v1(t_data  *f);
void join_data_v2(t_data  *f);
void rev_j_data_space(t_data  *f);
void rev_join_data_v2(t_data  *f);
char *str_creat_s_width(t_data  *f, int q);
void join_data_s(t_data  *f);
void r_join_data_s(t_data  *f);

#endif