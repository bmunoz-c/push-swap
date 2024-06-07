/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmds.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:22:27 by bmunoz-c          #+#    #+#             */
/*   Updated: 2024/05/24 16:08:43 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack_node **a, t_stack_node **b,
			t_stack_node *cheapest)
{
	while (*a != cheapest->set_target_node && *b != cheapest)
		rr(a, b, false);
	set_index(*a);
	set_index(*b);
}

static void	reverse_rotate_both(t_stack_node **a,
			t_stack_node **b, t_stack_node *cheapest)
{
	while (*a != cheapest->set_target_node && *b != cheapest)
		rrr(a, b, false);
	set_index(*a);
	set_index(*b);
}

//Finish rotation & ready to push.
void	prep_4push(t_stack_node **stack,
		t_stack_node *head_node, char stack_name)
{
	while (*stack != head_node)
	{
		if (stack_name == 'a')
		{
			if (head_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (head_node->above_median)
			{
				rb(stack, false);
			}
			else
				rrb(stack, false);
		}
	}
}

//Move the node b to a.
static void	move_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = return_cheapest(*b);
	if (cheapest_node->above_median
		&& cheapest_node->set_target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->set_target_node->above_median))
		reverse_rotate_both(a, b, cheapest_node);
	prep_4push(b, cheapest_node, 'b');
	prep_4push(a, cheapest_node->set_target_node, 'a');
	pa(a, b, false);
}

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*smallest;
	int				len_a;

	len_a = stack_len(*a);
	if (len_a == 5)
		sort_five(a, b);
	else
	{
		while (len_a-- > 3)
			pb(b, a, false);
	}
	sort_three(a);
	while (*b)
	{
		init_node(*a, *b);
		move_nodes(a, b);
	}
	set_index(*a);
	smallest = find_small(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a, false);
	else
		while (*a != smallest)
			rra(a, false);
}
