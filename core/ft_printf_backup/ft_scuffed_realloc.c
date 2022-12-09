/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scuffed_realloc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:49:53 by jteoh             #+#    #+#             */
/*   Updated: 2022/12/09 12:56:10 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	scuffed_realloc_plus(t_flags *flag)
{
	char	*tmp;
	int		i;
	int		j;
	int		space;

	if (flag->neg)
		return (scuffed_realloc_plus_neg(flag));
	i = ft_strlen(flag->output);
	space = 1;
	if (flag->output[0] == ' ')
		space = 0;
	j = i + space;
	tmp = (char *)malloc((j + 1) * sizeof(char));
	if (!tmp)
		return (0);
	tmp[j] = 0;
	while (i > 0)
		tmp[--j] = flag->output[--i];
	while (!ft_isdigit(tmp[j]))
		j++;
	tmp[--j] = '+';
	free(flag->output);
	flag->output = ft_strdup(tmp);
	free(tmp);
	return (1);
}

int	scuffed_realloc_plus_neg(t_flags *flag)
{
	char	*tmp;
	int		i;
	int		j;
	int		space;

	i = ft_strlen(flag->output);
	space = 1;
	if (flag->output[i - 1] == ' ')
		space = 0;
	j = i + space;
	tmp = (char *)malloc((j + 1) * sizeof(char));
	if (!tmp)
		return (0);
	tmp[j] = 0;
	if (space == 0)
		i--;
	while (i > 0)
		tmp[--j] = flag->output[--i];
	while (!ft_isdigit(tmp[j]))
		j++;
	tmp[--j] = '+';
	free(flag->output);
	flag->output = ft_strdup(tmp);
	free(tmp);
	return (1);
}

int	scuffed_realloc_0x(t_flags *flag, t_specifier *spc)
{
	char	*tmp;
	int		i;
	int		j;
	int		space;

	if (flag->neg)
		return (scuffed_realloc_0x_neg(flag, spc));
	i = ft_strlen(flag->output);
	space = 2;
	if (flag->output[0] == ' ')
		space = 0;
	j = i + space;
	tmp = (char *)malloc((j + 1) * sizeof(char));
	if (!tmp)
		return (0);
	tmp[j] = 0;
	while (i > 0)
		tmp[--j] = flag->output[--i];
	while (!ft_isalnum(tmp[j]))
		j++;
	append_0x(tmp, j, spc);
	free(flag->output);
	flag->output = ft_strdup(tmp);
	free(tmp);
	return (1);
}

int	scuffed_realloc_0x_neg(t_flags *flag, t_specifier *spc)
{
	char	*tmp;
	int		i;
	int		j;
	int		space;

	i = ft_strlen(flag->output);
	space = 2;
	if (flag->output[i - 2] == ' ')
		space = 0;
	j = i + space;
	tmp = (char *)malloc((j + 1) * sizeof(char));
	if (!tmp)
		return (0);
	tmp[j] = 0;
	if (space == 0)
		i -= 2;
	while (i > 0)
		tmp[--j] = flag->output[--i];
	while (!ft_isalnum(tmp[j]))
		j++;
	append_0x(tmp, j, spc);
	free(flag->output);
	flag->output = ft_strdup(tmp);
	free(tmp);
	return (1);
}

void	append_0x(char *tmp, int j, t_specifier *spc)
{
	tmp[j - 2] = '0';
	if (spc->x || spc->p)
		tmp[j - 1] = 'x';
	if (spc->upperx)
		tmp[j - 1] = 'X';
}
