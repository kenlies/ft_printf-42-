/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 04:36:45 by aotsala           #+#    #+#             */
/*   Updated: 2022/11/25 00:52:38 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*ft_print_nil(t_data *tab, char *a)
{
	char	*anew;

	anew = (char *)malloc(sizeof(char) * 6);
	if(!anew)
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

void	ft_print_pr(t_data *tab)
{
	char c;

	c = '%';
	write(1, &c, 1);
	tab->tl += 1;
}


void	ft_print_spaces(int nb)
{
	int		i;
	char	b;

	b = ' ';
	i = 0;
	while (i < nb)
	{
		write(1, &b, 1);
		i++;
	}
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
	while (a[j])
		anew[i++] = a[j++];
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
