/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_env_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:37:01 by nkim              #+#    #+#             */
/*   Updated: 2022/07/03 18:19:05 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	valid_env_name(char *identifier)
{
	char	*ptr;

	ptr = identifier;
	if (((*identifier < 'a' || *identifier > 'z') && (*identifier < 'A'
				|| *identifier > 'Z')) && *identifier != '_')
		return (EXIT_FAILURE);
	while (*ptr && *ptr != '=')
	{
		if (((*ptr < 'a' || *ptr > 'z') && (*ptr < 'A' || *ptr > 'Z'))
			&& (*ptr != '_') && ((*ptr < '0' || *ptr > '9')))
			return (EXIT_FAILURE);
		ptr++;
	}
	return (EXIT_SUCCESS);
}
