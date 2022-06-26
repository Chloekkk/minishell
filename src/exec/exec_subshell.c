/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_subshell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 21:18:05 by nkim              #+#    #+#             */
/*   Updated: 2022/06/26 21:33:53 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// 2개이상의 pipe 가 있는 명령어 실행하는 함수
int	exec_subshell(t_pipe_line *pipe_line)
{
	pid_t	pid;

	pid = create_subshell(pipe_line);
	if (pid == ERROR_FLAG)
		return (ERROR_FLAG);
	if (pipe_line->pipe_line && pipe_line->pipe_line->type == AST_PIPELINE)
		exec_subshell(pipe_line->pipe_line->data);
	else
		wait_subshell(pid);
	return (SUCCESS_FLAG);
}