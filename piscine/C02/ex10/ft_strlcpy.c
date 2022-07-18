/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:04:47 by jteoh             #+#    #+#             */
/*   Updated: 2022/06/02 17:31:39 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (ft_strlen(dest) >= (size - 1))
	{
		while (i < size && src[i] != '\0' && j < size)
		{
			dest[j] = src[i];
			j++;
			i++;
		}
	}
	else if (ft_strlen(dest) < (size - 1))
		return (0);
	dest[j] = '\0';
	return (ft_strlen(src));
}
