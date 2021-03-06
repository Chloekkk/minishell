/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:00:23 by nkim              #+#    #+#             */
/*   Updated: 2022/07/01 16:05:14 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bs_signal.h"

/* rl_replace_line : buffer flush */
static void	handle_sigint(int signum)
{
	if (signum != SIGINT)
		return ;
	write(1, "\n", 1);
	rl_replace_line("", 1);
	rl_on_new_line();
	rl_redisplay();
	g_manager.exit_code = 1;
}

/* SIGINT : ctrl + c, SIGQUIT : ctrl + \ */
void	init_signal(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
}
