/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:20:15 by ommadhi           #+#    #+#             */
/*   Updated: 2019/11/15 22:30:44 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int     ft_if_fun(char **tab, t_nod **nd, char **envp, char **path)
{
	int i;

	i = 0;
//	(ft_strcmp("exit", tab[0]) == 0) ? ft_freelist(nd) : 0;
	if (ft_strcmp(tab[0], "echo") == 0)
	{
		echoo(tab, *nd);
		i++;
	}
	(ft_strcmp(tab[0], "unsetenv") == 0 && ft_unsetenv(nd, tab) == 1) ? i++ : 0;
	if (ft_strcmp(tab[0], "cd") == 0 )
	{
		ft_cd(tab, path, nd);
		i++;
	}
	(ft_strcmp(tab[0], "setenv") == 0 && ft_setenv(nd, tab) == 0) ? i++ : 0;
	(ft_strcmp(tab[0], "env") == 0 && ft_env(nd) == 0) ? i++ : 0;
	return (i);
}
