/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 02:38:41 by hannkim           #+#    #+#             */
/*   Updated: 2022/07/01 15:46:41 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	bs_strcmp(char *s1, char *s2)
{
	size_t	n;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s1_len > s2_len)
		n = s1_len;
	else
		n = s2_len;
	return (ft_strncmp(s1, s2, n));
}
