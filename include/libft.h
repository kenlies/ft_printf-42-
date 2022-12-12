/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:31:21 by aotsala           #+#    #+#             */
/*   Updated: 2022/11/27 11:22:35 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

int		ft_toupper(int c);
int		ft_isdigit(int c);
int		ft_strlen(const char *str);
int		ft_atoi(const char *str);
char	*ft_substr(char *s, int start, int len, int p_null);
char	*ft_itoa(int n);
char	*ft_itoa_hex(int nb);
char	*ft_uitoa(unsigned int nb);
char	*ft_ulitoa_hex(unsigned long long nb);

#endif
