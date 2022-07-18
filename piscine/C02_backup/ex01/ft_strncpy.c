/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:55:55 by jteoh             #+#    #+#             */
/*   Updated: 2022/06/02 16:28:40 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	while (i < n)
	{
		if (i == n || j == n)
			break ;
		else if (src[i] != '\0')
		{
			dest[j] = src[i];
			i++;
			j++;
		}
		else if (src[i] == '\0' && j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (dest);
}
