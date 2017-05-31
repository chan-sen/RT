/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getword.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:59:42 by chansen           #+#    #+#             */
/*   Updated: 2016/11/28 18:00:31 by chansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_getword(char *str, int *i)
{
	char	*ret;
	int		a;

	a = (*i);
	while (str[a] != ' ' && str[a] != '\0')
		a++;
	ret = (char *)malloc(sizeof(char) * (a - (*i)));
	a = 0;
	while (str[(*i)] != ' ' && str[(*i)] != '\0')
		ret[a++] = str[(*i)++];
	return (ret);
}
