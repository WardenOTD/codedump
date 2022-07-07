/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:15:04 by jteoh             #+#    #+#             */
/*   Updated: 2022/07/07 10:35:11 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t	*arr;
	size_t	i;

	i = 0;
	arr = (void *)malloc(count * size);
	if (!arr)
		return (0);
	while (arr[i])
	{
		arr[i] = 0;
		i++;
	}
	return ((void *)arr);
}
