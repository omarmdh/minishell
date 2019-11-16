/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:08:45 by ommadhi           #+#    #+#             */
/*   Updated: 2019/11/16 13:07:07 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_clear(char *buff, char **tab)
{
	ft_strclr(buff);
	ft_free_tab(tab);
}

void    ft_free_tab(char **tab)
{
	int i;

	i = 0;
	if (*tab != NULL)
	{
		while (tab[i])
		{
			ft_strdel(&tab[i]);
			i++;
		}
		free(tab);
		tab = NULL;
	}
}

void	ft_destroy_all(char ***tab, char ***tab1, char ***tab2, char *buff)
{
	ft_strclr(buff);
	ft_free_tab(*tab);
	ft_free_tab(*tab1);
	ft_free_tab(*tab2);
}

void	ft_freelist(t_nod **n)
{
	t_nod *nd;
	t_nod *tmp;

	nd = *n;
	while (nd)
	{
		tmp = nd->next;
		ft_strdel(&nd->data);
		ft_strdel(&nd->value);
		free(nd);
		nd = tmp;
	}
}

void	ft_free_exit(char **tab,char **tab1, t_nod **nd)
{
	ft_freelist(nd);
	ft_free_tab(tab1);
	ft_free_tab(tab);
	exit(0);
}
