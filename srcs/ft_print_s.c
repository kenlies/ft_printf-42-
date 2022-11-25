/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:29:38 by aotsala           #+#    #+#             */
/*   Updated: 2022/11/24 08:39:31 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_print_s2(t_data *tab, char *a)
{
	char	*anew;
	int		i;

	if (tab->precision)
		anew = ft_substr(a, 0, tab->precision);
	else
	{
		anew = (char *)malloc(sizeof(char) * 1);
		anew[0] = '\0';
	}
	ft_update_tab(tab, ft_strlen(anew));
	if (tab->width && !tab->dash)
		ft_print_spaces(tab->space);
	i = 0;
	while (anew[i])
		tab->tl += write(1, &anew[i++], 1);
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
		tab->tl += write(1, &a[i++], 1);
	if (tab->width && tab->dash)
		ft_print_spaces(tab->space);
	if (tab->space > 0)
		tab->tl += tab->space;
}
