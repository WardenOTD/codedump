/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteoh <jteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:59:22 by jteoh             #+#    #+#             */
/*   Updated: 2023/05/25 12:15:27 by jteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_bonus bonus;

	if (argc == 2)
	{
		innit_1(argv[1], &bonus);
		if (create_stack_1(argv[1], &bonus) == 0)
			dead(&bonus);
		return (0);
	}
	else if (argc > 2)
	{
		stack.size = argc - 1;
		innit_2(&bonus);
		if (create_stack_2(argv, &bonus) == 0)
			dead(&bonus);
		return (0);
	}
	return (0);
}
