/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:27:34 by nkim              #+#    #+#             */
/*   Updated: 2022/06/28 20:14:39 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

int	redirect_in_file(char *file_path);
int	redirect_out_file(char *file_path);
int	redirect_append_file(char *file_path);
int	redirect_heredoc(char *end_text);
int	backup_std_fd(int std_fd[3]);
int	reset_std_fd(int std_fd[3]);

#endif