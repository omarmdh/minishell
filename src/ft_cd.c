/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:54:33 by ommadhi           #+#    #+#             */
/*   Updated: 2019/10/19 17:48:31 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_cd(int ac, char **av, char *home)
{
	if (av[1] != NULL && av[1][0] == '~' && av[1][1] == '\0')
		av[1] = ft_strdup(&home[5]);
	ac = 0;
	while (av[ac])
		ac++;
	if (ac > 2)
	{
		ft_put4str("cd: string not in pwd: ", av[1], "", "\n");
		return (0);
	}
	if (ac == 1)
	{
		chdir(&home[5]);
		return (0);
	}
	if (chdir(av[1]) == -1)
		ft_put4str("cd: string not in pwd: ", av[1], "", "\n");
	return (0);
}
