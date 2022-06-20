/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:20:19 by hannkim           #+#    #+#             */
/*   Updated: 2022/06/19 22:30:53 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_env(void)
{
	t_env *ptr;

	ptr = manager.env;
	while (ptr)
	{
		ft_putstr_fd(ptr->name, STDOUT_FILENO);
		write(STDOUT_FILENO, "=", 1);
		ft_putstr_fd(ptr->value, STDOUT_FILENO);
		write(STDOUT_FILENO, "\n", 1);
		ptr = ptr->next;
	}
}
