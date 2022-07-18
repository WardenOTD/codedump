/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:32:35 by jteoh             #+#    #+#             */
/*   Updated: 2022/06/09 10:44:29 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	find_null(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		continue ;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	j = 0;
	i = find_null(dest);
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
