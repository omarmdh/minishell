/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 12:30:19 by ommadhi           #+#    #+#             */
/*   Updated: 2019/11/01 20:48:10 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	ft_puts(char *str, char c, char *str2)
{
	ft_putstr(str);
	ft_putchar(c);
	ft_putstr(str2);
}

int		ft_erro(int p)
{
	if (p == 1)
		ft_puts("Unmatched ", 34, ".\n");
	if (p == 2)
		ft_puts("Unmatched ", 39, ".\n");
	return (0);
}

int		ft_quote(char	**arg)
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

int		ft_checkdolar(char *arg)
{
	int i;
	int d;

	d = 0;
	i = 0;
	while (arg[i])
	{
		if (arg[i] == '$')
			d++;
		i++;
	}
	return (d);
}

int 	ft_echo(char **av, t_nod *nd)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if ((ft_quote(av) % 2) != 0 && ft_erro(1) == 0)
		return (0);
	while ()
	return (0);
}

int main(int ac, char **av, char **envp)
{
	ft_echo(&av[1], envp);
	return (0);
}
