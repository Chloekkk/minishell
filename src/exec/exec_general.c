/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:00:00 by nkim              #+#    #+#             */
/*   Updated: 2022/06/30 18:20:43 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_count(void)
{
	t_env	*ptr;
	int		count;

	ptr = g_manager.env;
	count = 0;
	while (ptr)
	{
		count++;
		ptr = ptr->next;
	}
	return (count);
}

/* env list -> char ** */
static char	**get_string_env(void)
{
	t_env	*ptr;
	char	**ret;
	char	*tmp;
	int		count;
	int		i;

	ptr = g_manager.env;
	count = get_count();
	ret = (char **)bs_calloc(count + 1, sizeof(char *));
	if (!ret)
		exit(EXIT_FAILURE);
	i = 0;
	while (ptr)
	{
		tmp = ft_strjoin(ptr->name, "=");
		ret[i] = ft_strjoin(tmp, ptr->value);
		free(tmp);
		ptr = ptr->next;
		i++;
	}
	return (ret);
}

/* find and return file's path (filename) */
static char	*find_file(char *cmd, char **path)
{
	char		*filename;
	char		*tmp;
	struct stat	buf;
	int			i;

	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		filename = ft_strjoin(tmp, cmd);
		free(tmp);
		if (stat(filename, &buf) != -1)
			return (filename);
		free(filename);
		i++;
	}
	return (ft_strdup(cmd));
}

static int	error_execve(char *argv)
{
	int	exit_code;

	exit_code = EXIT_FAILURE;
	if (errno == ENOENT)
	{
		exit_code = EXIT_ENOENT;
		throw_error(argv, NULL, "command not found");
	}
	else if (errno == EACCES)
	{
		exit_code = EXIT_EACCES;
		throw_error(argv, NULL, strerror(errno));
	}
	return (exit_code);
}

/* error -> envp, filename free? -> exit? */
int	exec_general(char **argv)
{
	char	**envp;
	char	**path;
	char	*filename;
	int		i;

	if (get_env(PATHENV))
		path = ft_split(get_env(PATHENV)->value, ':');
	else
	{
		path = (char **)bs_calloc(2, sizeof(char *));
		*path = ft_strdup(".");
	}
	filename = find_file(*argv, path);
	envp = get_string_env();
	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
	execve(filename, argv, envp);
	return (error_execve(*argv));
}
