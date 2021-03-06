/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:40:11 by nkim              #+#    #+#             */
/*   Updated: 2022/07/01 16:16:33 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# define TMPENV "TMPDIR"
# define TMPKEY "blackhole-"
# define TMPDIR "/tmp/"
# define PATHENV "PATH"

# include "error.h"

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}					t_env;

t_env				*get_env(char *identifier);
int					valid_env_name(char *identifier);
char				*get_env_name(char *argv);
char				*get_env_value(char *argv);
void				add_env(char *name, char *value);
void				remove_env(t_env *target);
void				free_env(void);

#endif