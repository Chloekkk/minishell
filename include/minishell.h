/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:35:25 by hannkim           #+#    #+#             */
/*   Updated: 2022/07/05 18:12:15 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* CUSTOM HEADER FILE */
# include "ast.h"
# include "env.h"
# include "error.h"
# include "exec.h"
# include "parser.h"
# include "redirect.h"
# include "bs_signal.h"
# include "subshell.h"
# include "utils.h"
# include "libft.h"

/* BUILTIN HEADER FILE */
# include <stdio.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <string.h>
# include <sys/errno.h>

# define SPLASHTEXT "\n\
██████╗*██╗******█████╗**██████╗██╗**██╗\n\
██╔══██╗██║*****██╔══██╗██╔════╝██║*██╔╝\n\
██████╔╝██║*****███████║██║*****█████╔╝*\n\
██╔══██╗██║*****██╔══██║██║*****██╔═██╗*\n\
██████╔╝███████╗██║**██║╚██████╗██║**██╗\n\
╚═════╝*╚══════╝╚═╝**╚═╝*╚═════╝╚═╝**╚═╝\n\
****************************************\n\
****██╗**██╗*██████╗*██╗*****███████╗***\n\
****██║**██║██╔═══██╗██║*****██╔════╝***\n\
****███████║██║***██║██║*****█████╗*****\n\
****██╔══██║██║***██║██║*****██╔══╝*****\n\
****██║**██║╚██████╔╝███████╗███████╗***\n\
****╚═╝**╚═╝*╚═════╝*╚══════╝╚══════╝***\n\
****************************************\n\
███████╗██╗**██╗███████╗██╗*****██╗*****\n\
██╔════╝██║**██║██╔════╝██║*****██║*****\n\
███████╗███████║█████╗**██║*****██║*****\n\
╚════██║██╔══██║██╔══╝**██║*****██║*****\n\
███████║██║**██║███████╗███████╗███████╗\n\
╚══════╝╚═╝**╚═╝╚══════╝╚══════╝╚══════╝\n\
****************************************\n\
\n"

/* MACRO VARIABLES */
# define TRUE 1
# define FALSE 0

# define PS1 "\e[38;5;63m\e[48;5;231m ✦ \e[0m\e[0m\
\e[38;5;231m\e[48;5;63m\uE0B0\e[0m\e[0m\
\e[48;5;63m blackhole-shell \e[0m\e[38;5;63m\uE0B0 \e[0m"

# define PS2 "> "

/* STRUCTURE */
typedef struct s_env	t_env;
typedef struct s_manager
{
	t_env				*env;
	char				*command_line;
	int					rc;
	int					quote_error;
	int					exit_code;
}						t_manager;

extern t_manager		g_manager;

#endif
