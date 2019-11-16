/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 11:44:46 by ommadhi           #+#    #+#             */
/*   Updated: 2019/11/16 11:44:49 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

static int		count(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (space(str[i - 1]) && !space(str[i]))
			count++;
		i++;
	}
	if (!space(str[i - 1]))
		count++;
	return (count);
}

static int		len(char *str)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (!space(str[i]))
			i++;
		else
			break ;
	}
	return (i);
}

char	**ft_spl_whitespaces(char *str)
{
	int		i;
	int		s;
	int		o;
	char	**big_arr;

	o = 0;
	i = 0;
	big_arr = (char**)malloc((count(str) + 1) * sizeof(char*));
	if (big_arr == NULL)
		return (0);
	while (str[i] && o < count(str))
	{
		s = 0;
		big_arr[o] = (char*)malloc(sizeof(char) * (len(str) + 1));
		if (big_arr == NULL)
			return (0);
		while (space(str[i]))
			i++;
		while (!space(str[i]) && str[i] != '\0')
			big_arr[o][s++] = str[i++];
		big_arr[o][s] = '\0';
		o++;
	}
	big_arr[o] = NULL;
	return (big_arr);
}
