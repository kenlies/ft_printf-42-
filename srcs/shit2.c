#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *str, ...);

typedef struct s_data
{
	va_list	args;
	int		width;
	int		pnt;
	int		precision;
	int		zero;
	int		dash;
	int		tl;
	int		plus;
	int		is_zero;
	int		percent;
	int		space;
	int     hash;
}	t_data;

t_data	*initialise_tab(t_data *tab)
{
	tab->width = 0;
	tab->pnt = 0;
	tab->precision = 0;
	tab->zero = 0;
	tab->dash = 0;
	tab->tl = 0;
	tab->plus = 0;
	tab->is_zero = 0;
	tab->percent = 0;
	tab->space = 0;
	tab->hash = 0;
	return (tab);
}

void    ft_print_pr(t_data *tab)
{
    char c;
    
    c = '%';
	write(1, &c, 1);
	tab->tl += 1;
}

char	ft_choose_mps(char c)
{
	if (c == '-')
		return ('-');
	else if (c == '+')
		return ('+');
	else
		return (' ');
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		c = c - 32;
	}
	return (c);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	not_type(char c)
{
	char	*types;
	int		i;

	i = 0;
	types = "csdiupxX%";
	while (types[i] != '\0')
		if (types[i++] == c)
			return (0);
	return (1);
}

void	ft_update_tab(t_data *tab, int i)
{
	tab->space = tab->width - i;
}

void	ft_print_spaces(int nb)
{
	int i;
	char b;

	b = ' ';
	i = 0;
	while (i < nb)
	{
		write(1, &b, 1);
		i++;
	}
}

int	abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

int	count_length(unsigned long long nb)
{
	size_t	i;

	i = 0;
	while (nb)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (len >= ft_strlen(s))
		len = ft_strlen(s);
	if (!s)
		return (NULL);
	i = 0;
	sub = (char *)(malloc(sizeof(char) * len + 1));
	if (!sub)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		sub[i] = '\0';
		return (sub);
	}
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_ulitoa_hex(unsigned long long nb)
{
	char	*str;
	char	*tab;
	int		size;

	size = 0;
	tab = "0123456789abcdef";
	size = count_length(nb);
	if (nb == 0)
		size++;
	str = (char *)malloc(sizeof(char) * size + 1);
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = tab[abs(nb % 16)];
		size--;
		nb = nb / 16;
	}
	return (str);
}

static int	ft_ulen(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_uitoa(unsigned int nb)
{
	char	*str;
	int		len;
    int     nb2;
    
    nb2 = nb;
	len = ft_ulen(nb);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (nb > 0)
	{
		str[len - 1] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
	if (nb2 == 0)
	    str[0] = '0';
	return (str);
}

static char	*ft_strrev(char *str, int len)
{
	int		i;
	char	tmp;

	i = 0;
	while (i < len--)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
	}
	return (str);
}

static int	ft_length(long int num, int length)
{
	while (num)
	{
		num = num / 10;
		length++;
	}
	return (length);
}

static char	*ft_itoa_helper(char *str, long int num, int index, int len)
{
	int	i;

	i = 0;
	if (num == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (index < 0)
	{
		str[len -1] = '-';
	}
	while (num > 0)
	{
		str[i] = '0' + (num % 10);
		num = num / 10;
		i++;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int			length;
	char		*str;
	int			index;
	long int	num;

	num = n;
	index = 1;
	length = 0;
	if (num <= 0)
	{
		length++;
		num = num * (-1);
		index = -1;
	}
	length = ft_length(num, length);
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	str = ft_itoa_helper(str, num, index, length);
	str = ft_strrev(str, length);
	str[length] = '\0';
	return (str);
}

char	*ft_to_upper_x(char	*a)
{
	int		i;
	char	*anew;

	anew = (char *)malloc(sizeof(char) * ft_strlen(a) + 1);
	i = 0;
	while (a[i] != '\0')
	{
		anew[i] = ft_toupper(a[i]);
		i++;
	}
	anew[i] = '\0';
	free(a);
	return (anew);
}

char	*ft_fuck_this_stupid_rule(t_data *tab, char *anew, char *a)
{
	int i;
	int j;

	anew = (char *)malloc(sizeof(char) * ft_strlen(a) + 2);
	if (!anew)
		return (NULL);
	if (tab->plus)
		anew[0] = '+';
	else if (tab->space)
		anew[0] = ' ';
	i = 1;
	j = 0;
	while (a[j] != '\0')
	{
		anew[i] = a[j];
		i++;
		j++;
	}
	anew[i] = '\0';
	return (anew);
}

char	*ft_add_ps(t_data *tab, char *a)
{	
	char	*anew;

	if (a[0] == '0' && tab->pnt && tab->precision == 0)
	{
		if (tab->plus)
			a[0] = '+';
		else if (tab->space)
			a[0] = ' ';
		return (a);
	}
	anew = ft_fuck_this_stupid_rule(tab, anew, a);
	free(a);
	return (anew);
}

char	*ft_add_zeros(t_data *tab, char *a, char *anew)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlen(a);
	if (a[0] == '-' || a[0] == '+' || a[0] == ' ')
	{
		i++;
		j++;
		len--;
		tab->precision++;
	}
	while (i < tab->precision)
	{
		if (i < tab->precision - len)
			anew[i] = '0';
		else
			anew[i] = a[j++];
		i++;
	}
	anew[i] = '\0';
	return (anew);
}

char	*ft_malloc_for_zeros(t_data *tab, char *a)
{
	char	*anew;

	if (a[0] == '-' || a[0] == '+' || a[0] == ' ')
	{
		anew = (char *)malloc(sizeof(char) * tab->precision + 2);
		if (!anew)
			return (NULL);
		if (a[0] == '-')
			anew[0] = '-';
		else if (a[0] == '+')
			anew[0] = '+';
		else
			anew[0] = ' ';
	}
	else
	{
		anew = (char *)malloc(sizeof(char) * tab->precision + 1);
		if (!anew)
			return (NULL);
	}
	ft_add_zeros(tab, a, anew);
	free(a);
	return (anew);
}

char	*ft_add_zeros_flag(t_data *tab, char *a, char *anew)
{
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(a);
	if (a[0] == '-' || a[0] == '+' || a[0] == ' ')
	{
		anew[0] = ft_choose_mps(a[0]);
		i++;
		j++;
		len--;
	}
	while (i < tab->width)
	{
		if (i < tab->width - len)
			anew[i] = '0';
		else
			anew[i] = a[j++];
		i++;
	}
	anew[i] = '\0';
	return (anew);
}

char	*ft_malloc_zero_flag(t_data *tab, char *a)
{
	char	*anew;

	anew = (char *)malloc(sizeof(char) * tab->width + 1);
	if (!anew)
		return (NULL);
	ft_add_zeros_flag(tab, a, anew);
	free(a);
	return (anew);
}


char	*ft_add_prefix(char	*a)
{
	char	*anew;
	int		i;
	int		j; 

	anew = (char *)malloc(sizeof(char) * ft_strlen(a) + 3);
	if (!anew)
		return (NULL);
	anew[0] = '0';
	anew[1] = 'x';
	j = 2;
	i = 0;
	while (a[i] != '\0')
	{
		anew[j] = a[i];
		i++;
		j++;
	}
	anew[j] = '\0';
	free(a);
	return (anew);
}

char	*ft_zeros_p(t_data *tab, char *a)
{
	char	*anew;
	int 	amount;
	int		i;
	int 	j;
	
	amount = tab->precision - ft_strlen(a); 
	anew = (char *)malloc(sizeof(char) * tab->precision + 1);
	if (!anew)
		return (NULL);
	i = 0;
	while(amount > 0)
	{
		anew[i++] = '0';
		amount--;
	}
	j = 0;
	while (a[j] != '\0')
		anew[i++] = a[j++];
	anew[i] = '\0';
	free(a);
	anew = ft_add_prefix(anew);
	return (anew);
}

char	*ft_zero_flag_p_add(t_data *tab, char *a)
{	
	char	*anew;
	int		amount;
	int		i;
	int		j;

	amount = tab->width - (ft_strlen(a) + 2);
	anew = (char *)malloc(sizeof(char) * tab->width - 1);
	if (!anew)
		return (NULL);
	i = 0;
	while(amount > 0)
	{
		anew[i++] = '0';
		amount--;
	}
	j = 0;
	while (a[j] != '\0')
		anew[i++] = a[j++];
	anew[i] = '\0';
	free(a);
	anew = ft_add_prefix(anew);
	return (anew);
}

char	*ft_zero_flag_p(t_data *tab, char *a)
{
	char	*anew;

	if ((tab->width > ft_strlen(a) + 2) && !tab->dash)
		anew = ft_zero_flag_p_add(tab, a);
	else
		anew = ft_add_prefix(a);
	return (anew);
}

char    *ft_print_nil(t_data *tab, char *a)
{
    char    *anew;
    
    anew = (char *)malloc(sizeof(char) * 6);
    if (!anew)
        return (NULL);
    anew[0] = '(';
    anew[1] = 'n';
    anew[2] = 'i';
    anew[3] = 'l';
    anew[4] = ')';
    anew[5] = '\0';
    free(a);
    return (anew);
}

void	ft_print_c(t_data *tab)
{
	char	a;

	a = va_arg(tab->args, int);
	tab->space = tab->width - 1;
	if (tab->width && !tab->dash)
		ft_print_spaces(tab->space);
	tab->tl+= write(1, &a, 1);
	if (tab->width && tab->dash)
		ft_print_spaces(tab->space);
	if (tab->space > 0)
		tab->tl += tab->space;
}

void	ft_print_s2(t_data *tab, char *a)
{
	char	*anew;
	int 	i;
	if (tab->precision)
		anew = ft_substr(a, 0, tab->precision);
	else
	{
		anew = (char *)malloc(sizeof(char) * 1);
		anew[0] = '\0';
	}
	tab->space = tab->width - ft_strlen(anew);
	if (tab->width && !tab->dash)
		ft_print_spaces(tab->space);
	i = 0;
	while (anew[i])
		tab->tl+= write(1, &anew[i++], 1);
	if (tab->width && tab->dash)
		ft_print_spaces(tab->space);
	if (tab->space > 0)
		tab->tl += tab->space;
}

void	ft_print_s(t_data *tab)
{
	char	*a;
	int		i;

	a = va_arg(tab->args, char *);
	if (tab->pnt)
	{
		ft_print_s2(tab, a);
		return ;
	}
	tab->space = tab->width - ft_strlen(a);
	if (tab->width && !tab->dash)
		ft_print_spaces(tab->space);
	i = 0;
	while (a[i])
		tab->tl+= write(1, &a[i++], 1);
	if (tab->width && tab->dash)
		ft_print_spaces(tab->space);
	if (tab->space > 0)
		tab->tl += tab->space;
}

void	ft_print_d(t_data *tab)
{
	char	*a;
	int		i;

	a = ft_itoa(va_arg(tab->args, int));

	if (a[0] != '-' && (tab->plus || tab->space))
		a = ft_add_ps(tab, a);
	if (a[0] == '0' && tab->pnt && tab->precision == 0)
		a[0] = '\0';
	else if (tab->precision >= ft_strlen(a))
		a = ft_malloc_for_zeros(tab, a);
	else if (tab->zero && tab->width > ft_strlen(a) && !tab->dash && !tab->pnt)
		a = ft_malloc_zero_flag(tab, a);

		
	tab->space = tab->width - ft_strlen(a);
	if (tab->width && !tab->dash)
		ft_print_spaces(tab->space);
	i = 0;
	while (a[i])
		tab->tl+= write(1, &a[i++], 1);
	if (tab->width && tab->dash)
		ft_print_spaces(tab->space);
	if (tab->space > 0)
		tab->tl += tab->space;
}

char	*ft_mega_iq_func(t_data *tab, char *a)
{
	if (tab->precision > ft_strlen(a))
		a = ft_zeros_p(tab, a);
	else if (tab->zero)
		a = ft_zero_flag_p(tab, a);
	else
		a = ft_add_prefix(a);
	return (a);
}

void	ft_print_p(t_data *tab)
{
	char	*a;
	int		i;

	a = ft_ulitoa_hex((unsigned long long)va_arg(tab->args, void *));
	if (a[0] == '0')
        a = ft_print_nil(tab, a);
    else
	    a = ft_mega_iq_func(tab, a);
	tab->space = tab->width - ft_strlen(a);
	if (tab->width && !tab->dash)
		ft_print_spaces(tab->space);
	i = 0;
	while (a[i])
		tab->tl+= write(1, &a[i++], 1);
	if (tab->width && tab->dash)
		ft_print_spaces(tab->space);
	if (tab->space > 0)
		tab->tl += tab->space;
}

void	ft_print_u(t_data *tab)
{
	char	*a;
	int		i;

	a = ft_uitoa(va_arg(tab->args, unsigned int));

	if (a[0] == '0' && tab->pnt && tab->precision == 0)
		a = NULL;
	else if (tab->precision >= ft_strlen(a))
		a = ft_malloc_for_zeros(tab, a);
	else if (tab->zero && tab->width > ft_strlen(a) && !tab->dash)
		a = ft_malloc_zero_flag(tab, a);


	tab->space = tab->width - ft_strlen(a);
	if (tab->width && !tab->dash)
		ft_print_spaces(tab->space);
	i = 0;
	while (a[i])
		tab->tl+= write(1, &a[i++], 1);
	if (tab->width && tab->dash)
		ft_print_spaces(tab->space);
	if (tab->space > 0)
		tab->tl += tab->space;
}

void	ft_print_x(t_data *tab, int upper_yes)
{
	char	*a;
	int		i;

	a = ft_ulitoa_hex(va_arg(tab->args, unsigned int));
	if (upper_yes)
		a = ft_to_upper_x(a);
	if (a[0] == '0' && tab->pnt && tab->precision == 0)
		a = NULL;
	else if (tab->hash && a[0] != '0')
		a = ft_mega_iq_func(tab, a);
	else if (tab->precision >= ft_strlen(a))
		a = ft_malloc_for_zeros(tab, a);
	else if (tab->zero && tab->width > ft_strlen(a) && !tab->dash)
		a = ft_malloc_zero_flag(tab, a);

	tab->space = tab->width - ft_strlen(a);
	if (tab->width && !tab->dash)
		ft_print_spaces(tab->space);
	i = 0;
	while (a[i])
		tab->tl+= write(1, &a[i++], 1);
	if (tab->width && tab->dash)
		ft_print_spaces(tab->space);
	if (tab->space > 0)
		tab->tl += tab->space;
}

void	doer(t_data *tab, const char *str, int i)
{
	if (str[i] == 'x')
		ft_print_x(tab, 0);
	else if (str[i] == 'X')
		ft_print_x(tab, 1);
	else if (str[i] == 'u')
		ft_print_u(tab);
	else if (str[i] == 'p')
		ft_print_p(tab);
	else if (str[i] == 'd' || str[i] == 'i')
		ft_print_d(tab);
	else if (str[i] == 's')
		ft_print_s(tab);
	else if (str[i] == 'c')
		ft_print_c(tab);
	else if (str[i] == '%')
		ft_print_pr(tab);
}

int	formatter(t_data *tab, const char *str, int i)
{
	while (not_type(str[i]))
	{
	    if (tab->pnt && ft_isdigit(str[i]))
			tab->precision = (tab->precision * 10) + (str[i] - '0');
	    else if (str[i] == '0' && tab->width == 0)
			tab->zero = 1;
		else if (ft_isdigit(str[i]))
			tab->width = (tab->width * 10) + (str[i] - '0');
		else if (str[i] == '.')
			tab->pnt = 1;
		else if (str[i] == '-')
			tab->dash = 1;
		else if (str[i] == '+')
			tab->plus = 1;
		else if (str[i] == ' ')
			tab->space = 1;
		else if (str[i] == '#')
			tab->hash = 1;
		i++;
	}
	doer(tab, str, i);
	return (i + 1);
}

int	printter(const char *str, t_data *tab)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i = formatter(tab, str, i + 1);
			len += tab->tl;
			initialise_tab(tab);
			continue ;
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	free(tab);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	t_data	*tab;
	int		len;

	if (str == NULL)
		return (0);
	tab = (t_data *)malloc(sizeof(t_data));
	if (!tab)
		return (-1);
	initialise_tab(tab);
	va_start(tab->args, str);
	len = printter(str, tab);
	va_end(tab->args);
	return (len);
}

int main() {
  int len1;
  int len2;

  unsigned int u = 1;
  char *str = "sadsad";
  char c = 'c';
  int i = -20;
  int *p = NULL;
  
  len1 = ft_printf("||%-8p||", p);
  ft_printf("\n");
  len2 = printf("||%-8p||", p);
  //len1 = printf("\n||%020p||", p);
  
  //unsigned int y = 65465654;
  /*
  len1 = ft_printf("||%5c %.5s %09.4d %08u %-25.20p||", c, str, i, u, p);
  ft_printf("\n");
  len2 = printf("||%5c %.5s %09.4d %08u %-25.20p||", c, str, i, u, p);
  */
  printf("\n%d\n%d", len1 - 4, len2 - 4);
  
  return 0;
}