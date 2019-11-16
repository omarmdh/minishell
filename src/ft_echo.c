/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 22:21:18 by ommadhi           #+#    #+#             */
/*   Updated: 2019/11/03 21:08:46 by ommadhi          ###   ########.fr       */
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

/*void    ft_puts(char *str, char c, char *str2)
{
	ft_putstr(str);
	ft_putchar(c);
	ft_putstr(str2);
}

int     ft_erro(int p)
{
	if (p == 1)
		ft_puts("Unmatched ", 34, ".\n");
	if (p == 2)
		ft_puts("Unmatched ", 39, ".\n");
	return (0);
}

int     ft_quote1(char   **arg)
{
	int i;
	int j;
	int q;

	q = 0;
	j = 0;
	while (arg[j])
	{
		i = 0;
		while (arg[j][i])
		{
			if (arg[j][i] == 39)
				q++;
			i++;
		}
		j++;
	}
	return (q);
}

int     ft_quote2(char   **arg)
{
	int i;
	int j;
	int q;

	q = 0;
	j = 0;
	while (arg[j])
	{
		i = 0;
		while (arg[j][i])
		{
			if (arg[j][i] == 34)
				q++;
			i++;
		}
		j++;
	}
	return (q);
}

int		ft_echo(char **av, t_nod *n)
{
	int i;
	t_nod *nd;
	int er;

	i = 0;
	if ((ft_quote2(&av[1]) % 2) != 0 && ft_erro(1) == 0)
		return (1);
	if ((ft_quote1(&av[1]) % 2) != 0 && ft_erro(2) == 0)
		return (1);
	while (av[++i])
	{
		er = 0;
		nd = n;
		while (nd)
		{
			(av[i][0] == '~') ? av[i] = ft_strdup("$HOME") : 0 ;
			if (av[i][0] == '$' && ft_strcmp(&av[i][1], nd->data) == 0)
			{
				er = 1;
				ft_putstr(nd->value);
			}
			nd = nd->next;
		}
		(er == 0) ? ft_putstr(av[i]) : 0;
		(av[i + 1] != NULL) ? ft_putchar(' ') : 0;
	}
	ft_putchar('\n');
	return (1);
}*/
