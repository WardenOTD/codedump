/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:58:21 by jteoh             #+#    #+#             */
/*   Updated: 2022/12/09 13:01:43 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	cnc(const char *str, t_specifier *spc, t_flags *flag)
{
	int	i;
	int	q;
	int	j;

	q = 0;
	j = 0;
	i = findspc(str, spc);
	if (i == 0)
		return (0);
	flag->extract = (char *)malloc((sizeof(char) * (i + 1)));
	if (!(flag->extract))
		return (0);
	flag->extract[i] = 0;
	while (i-- > 0)
		flag->extract[q++] = str[j++];
	neg(flag);
	hard_set(spc, flag);
	flag->extract_size = ft_strlen(flag->extract);
	return (1);
}

void	hard_set(t_specifier *spc, t_flags *flag)
{
	if (spc->di == 0)
		flag->pos = 0;
	if (!spc->x && !spc->upperx)
		flag->hash = 0;
}
