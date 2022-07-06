/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:15:04 by jteoh             #+#    #+#             */
/*   Updated: 2022/07/06 14:37:26 by jteoh            ###   ########.fr       */
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
	while (arr[i])
	{
		arr[i] = 0;
		i++;
	}
	return ((void *)arr);
}
