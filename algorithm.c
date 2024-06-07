/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:48:35 by bmunoz-c          #+#    #+#             */
/*   Updated: 2024/05/23 20:39:07 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Sort nbr in stack.
bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

//Biggest nbr.
t_stack_node	*find_big(t_stack_node *stack)
{
	long			biggest;
	t_stack_node	*big_node;

	if (!stack)
		return (NULL);
	biggest = LONG_MIN;
	while (stack)
	{
		if (stack->nbr > biggest)
		{
			biggest = stack->nbr;
			big_node = stack;
		}
		stack = stack->next;
	}
	return (big_node);
}

//Sort nbr in stack when we ve only 3.
void	sort_three(t_stack_node	**a)
{
	t_stack_node	*big_node;

	big_node = find_big(*a);
	if (big_node == *a)
		ra(a, false);
	else if ((*a)->next == big_node)
		rra (a, false);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, false);
}

//Sort nbr in stack when we ve only 5.
void	sort_five(t_stack_node **a, t_stack_node **b)
{
	while (stack_len(*a) > 3)
	{
		init_node(*a, *b);
		prep_4push(a, find_small(*a), 'a');
		pb(b, a, false);
	}
}
