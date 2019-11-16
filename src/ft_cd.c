/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:54:33 by ommadhi           #+#    #+#             */
/*   Updated: 2019/11/05 20:34:47 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			ft_cd(char **av, char **home, t_nod **nd)
{
	int		ac;

	ac = 0;
	ft_oldpwd(nd);
	while (av[ac])
		ac++;
	(av[1] != NULL && av[1][0] == '~' && av[1][1] == '\0') ? av[1] = home[1] : 0;
	(ac == 1) ? chdir(home[1]) : 0;
	(av[1] != NULL && av[1][0] == '-' && av[1][1] == '\0') ? chdir(home[0]) : 0;
	if (ac > 2)
	{
		ft_put4str("cd: string not in pwd: ", av[1], "", "\n");
		return (0);
	}
	if (ac == 1)
	{
		chdir(home[1]);
		return (0);
	}
	if (chdir(av[1]) == -1 && av[1][0] != '-')
	{
		if (ft_check_excist(av[1]) == 0)
			ft_put4str("cd: string not in pwd: ", av[1], "", "\n");
		else
			ft_put4str("cd: permission denied: ", av[1], "", "\n");
	}
	return (0);
}
