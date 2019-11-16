/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 20:25:21 by ommadhi           #+#    #+#             */
/*   Updated: 2019/11/16 12:28:03 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int 	ft_check_excist(char *rpath)
{
	struct stat data;

	if (lstat(rpath, &data) < 0) 
		return (0);
	return (1);
}

char	*check_path(char **envp)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (&envp[i][5]);
		i++;
	}
	return (NULL);
}

char	*ft_joinpath(char **envp, char *cmd)
{
	char	*tmp;
	char	*ptr;
	char	**tabpath;
	int 	i;
	char	*rpath;

	i = 0;
	if (ft_check_excist(cmd) == 1)
		return (ft_strdup(cmd));
	tmp = check_path(envp);
	if (tmp == NULL)
		ft_put4str("minishell: command not found: ", cmd, "", "\n");
	tabpath = ft_strsplit(tmp, ':');
	while (tabpath[i])
	{
		ptr = ft_strjoin(tabpath[i], "/");
		rpath = ft_strjoin(ptr, cmd);
		free(ptr);
		if (ft_check_excist(rpath) == 1)
		{
			ft_free_tab(tabpath);
			return (rpath);
		}
		free(rpath);
		i++;
	}
	ft_free_tab(tabpath);
	return (NULL);
}
