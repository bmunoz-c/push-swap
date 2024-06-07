/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:08:02 by bmunoz-c          #+#    #+#             */
/*   Updated: 2024/05/24 16:07:49 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Check if isnum (+) || (-).
int	isnum(char *s)
{
	int	i;

	i = 0;
	if ((s[i] == '-' || s[i] == '+') && (s[i + 1] == '\0'))
		ft_error();
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			i++;
		else
			ft_error();
	}
	return (1);
}

//Check max int && min int.
void	limits(long n)
{
	int	max;
	int	min;

	max = 2147483647;
	min = -2147483648;
	if (n > max)
		ft_error();
	else if (n < min)
		ft_error();
}

//Check number repeat
int	isduplicate(int i, char **av)
{
	int	j;

	j = 1;
	while (j < i)
	{
		if (ft_atol(av[j]) == ft_atol(av[i]))
			ft_error();
		j++;
	}
	return (1);
}

//Main function.
int	check_args(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '\0')
			ft_error();
		isnum(av[i]);
		limits(ft_atol(av[i]));
		isduplicate(i, av);
		i++;
	}
	return (0);
}
