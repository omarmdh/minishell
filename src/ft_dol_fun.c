/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dol_fun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 23:22:43 by ommadhi           #+#    #+#             */
/*   Updated: 2019/11/10 23:35:31 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_dol_fun(t_nod	*env, char **cm)
{
	int i;
	char *cmd;

	cmd = *cm;
	i = 0;
	while (env)
	{
		if (ft_strcmp(env->data, &cmd[1]) == 0)
		{
			free(cmd);
			cmd = ft_strdup(env->value);
			i = 1;
		}
		env = env->next;
	}
	return (i);
}
