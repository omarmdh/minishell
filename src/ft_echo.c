/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 22:21:18 by ommadhi           #+#    #+#             */
/*   Updated: 2019/10/17 22:45:28 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_lent(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int		ft_echo(char **av, t_nod *n)
{
	int i;
	t_nod *nd;
	int er;

	i = 0;
	while (av[++i])
	{
		er = 0;
		nd = n;
		while (nd)
		{
			if (av[i][0] == '~')
				av[i] = "$HOME";
			if (av[i][0] == '$' && ft_strcmp(&av[i][1], nd->data) == 0)
			{
				er = 1;
				ft_putstr(nd->value);
			}
			nd = nd->next;
		}
		if (er == 0)
			ft_putstr(av[i]);
		if (av[i + 1] != NULL)
			ft_putchar(' ');
	}
	ft_putchar('\n');
	return (1);
}
