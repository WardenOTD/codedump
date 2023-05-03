/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:16:01 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/03 19:18:36 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_map_format(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != '\n')
		{
			if (data->map[i][j] != 'P' && data->map[i][j] != 'C'
				&& data->map[i][j] != 'E' && data->map[i][j] != '1'
				&& data->map[i][j] != '0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	validity_helper(t_data *data, int i)
{
	int	j;

	j = 0;
	while (data->map[i][j] != '\n')
	{
		if (data->map[i][j] != '1')
			return (0);
		j++;
	}
	return (--j);
}

int	validity(t_data *data)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = validity_helper(data, i);
	if (j == 0)
		return (0);
	while (data->map[i] != NULL)
	{
		tmp = ft_strlen(data->map[i]) - 2;
		if (j != tmp)
			return (0);
		if (data->map[i][0] != '1' || data->map[i][j] != '1')
			return (0);
		i++;
	}
	j = validity_helper(data, --i);
	if (j == 0)
		return (0);
	return (1);
}
