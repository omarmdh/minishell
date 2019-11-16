/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 00:38:01 by ommadhi           #+#    #+#             */
/*   Updated: 2019/11/16 12:53:29 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_error(char **tab, char *cmd)
{
	free(cmd);
	ft_put4str("minishell", ": command not found: ", tab[0], "\n");
	ft_free_tab(tab);
	exit(0);
}

void	ft_free_cmd_tab(char *cmd, char **tab)
{
	free(cmd);
	ft_free_tab(tab);
}
