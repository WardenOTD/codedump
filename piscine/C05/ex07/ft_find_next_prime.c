/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:38:25 by jteoh             #+#    #+#             */
/*   Updated: 2022/06/07 11:58:31 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	else if (nb > 1)
	{
		while (nb / nb == 1 || nb / 1 == nb)
		{
			if (i == nb)
				return (1);
			else if (nb % i == 0)
				return (0);
			i++;
		}
	}
	return (0);
}

int	ft_find_next_prime(int nb)
{
	if (nb >= 2147483647)
		return (0);
	else if (nb <= -2147483648)
		return (0);
	while (ft_is_prime(nb) == 0)
		nb++;
	return (nb);
}
