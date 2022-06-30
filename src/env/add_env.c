/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:38:53 by nkim              #+#    #+#             */
/*   Updated: 2022/06/30 18:20:18 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_env(char *name, char *value)
{
	t_env	*ptr;
	t_env	*new;

	ptr = g_manager.env;
	new = (t_env *)bs_calloc(1, sizeof(t_env));
	if (!new)
		exit(EXIT_FAILURE);
	new->name = name;
	new->value = value;
	new->next = NULL;
	if (!g_manager.env)
	{
		g_manager.env = new;
		return ;
	}
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
}
