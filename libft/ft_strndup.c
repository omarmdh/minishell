/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 18:56:44 by ommadhi           #+#    #+#             */
/*   Updated: 2019/10/16 19:07:58 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strndup(const char *s, int size)
{
	int     i;
	char    *str;
	char    *src;

	src = (char*)s;
	if (!(str = (char*)malloc(size * sizeof(char))))
		return (NULL);
	i = 0;
	while (src[i] && i < size)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
