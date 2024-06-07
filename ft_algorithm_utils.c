/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:49:58 by bmunoz-c          #+#    #+#             */
/*   Updated: 2024/05/23 23:32:33 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Current position in stack.
void	set_index(t_stack_node *stack)
{
	int	i;
	int	equador;

	i = 0;
	while (!stack)
		return ;
	equador = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= equador)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

//Nodes target from stack b to stack a.
static void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match_idx;

	while (b)
	{
		best_match_idx = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nbr > b->nbr && current_a->nbr < best_match_idx)
			{
				best_match_idx = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_idx == LONG_MAX)
			b->set_target_node = find_small(a);
		else
			b->set_target_node = target_node;
		b = b->next;
	}
}

//Moves cost.
void	set_cost(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->push_cost = b->index;
		if (!(b->above_median))
			b->push_cost = len_b - (b->index);
		if (b->set_target_node->above_median)
			b->push_cost += b->set_target_node->index;
		else
			b->push_cost += len_a - (b->set_target_node->index);
		b = b->next;
	}
}

//Cheapest move.
void	set_cheapest(t_stack_node *b)
{
	long			cheapest_nbr;
	t_stack_node	*cheapest_node;

	if (!b)
		return ;
	cheapest_nbr = LONG_MAX;
	while (b)
	{
		if (b->push_cost < cheapest_nbr)
		{
			cheapest_nbr = b->push_cost;
			cheapest_node = b;
		}
		b = b->next;
	}
	cheapest_node->cheapest = true;
}

void	init_node(t_stack_node *a, t_stack_node *b)
{
	set_index(a);
	set_index(b);
	set_target_node(a, b);
	set_cost(a, b);
	set_cheapest(b);
}
