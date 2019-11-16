/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_git.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:00:05 by ommadhi           #+#    #+#             */
/*   Updated: 2019/10/23 17:19:30 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_git(char	*path)
{
	DIR *rep;
	struct	dirent *data;

	rep = opendir(path);
	while ((data = readdir(rep)) != NULL)
	{
		if (ft_strcmp(data->d_name, ".git") == 0)
		{
			closedir(rep);
			return (1);
		}
	}
	return (0);
}
