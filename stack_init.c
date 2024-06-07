/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 21:54:23 by bmunoz-c          #+#    #+#             */
/*   Updated: 2024/06/07 16:11:54 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Calculate max len (11).
int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

//Ascii to Long && eliminate '0' --> s[0].
long	ft_atol(char *s)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (s[i] == '0')
		i++;
	if (ft_strlen(&s[i]) > 11)
		ft_error();
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i])
	{
		res = (res * 10) + (s[i] - 48);
		i++;
	}
	return (res * sign);
}

//Creation of node.
void	create_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (NULL == stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		exit(EXIT_FAILURE);
	node->next = NULL;
	node->nbr = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = ft_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

//Creation of stack a.
void	init_stack(t_stack_node **a, char **av)
{
	int				i;
	long			n;
	t_stack_node	*tmp;

	i = 0;
	while (av[i])
	{
		n = ft_atol(av[i]);
		create_node(a, (int)n);
		i++;
	}
	tmp = *a;
	(void)tmp;
}
