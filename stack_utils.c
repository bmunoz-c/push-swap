/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 22:29:35 by bmunoz-c          #+#    #+#             */
/*   Updated: 2024/05/24 15:34:44 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Fin last node.
t_stack_node	*ft_last_node(t_stack_node *head)
{
	while (head)
	{
		if (!head->next)
			return (head);
		head = head->next;
	}
	return (head);
}

//Len stack.
int	stack_len(t_stack_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

//Smallest nbr.
t_stack_node	*find_small(t_stack_node *stack)
{
	long			min;
	t_stack_node	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < min)
		{
			min = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

//Cheapest nbr.
t_stack_node	*return_cheapest(t_stack_node *stack)
{
	if (NULL == stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
/*
void	print_stack(t_stack_node *stack)
{
	t_stack_node	*tmp;
	int				i;

	tmp = stack;
	i = 0;
	printf("********------STACK------*******\n");
	while (tmp)
	{
		printf("%d = %d \n", i, tmp->nbr);
		tmp = tmp->next;
		i++;
	}
}*/
