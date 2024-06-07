/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 21:53:24 by bmunoz-c          #+#    #+#             */
/*   Updated: 2024/05/23 23:42:43 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Push node to the top from src to dst.
static void	push_cmd(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*n_topush;

	if (*src == NULL)
		return ;
	n_topush = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	n_topush->prev = NULL;
	if (*dst == NULL)
	{
		*dst = n_topush;
		n_topush->next = NULL;
	}
	else
	{
		n_topush->next = *dst;
		n_topush->next->prev = n_topush;
		*dst = n_topush;
	}
}

//Stack a - Push node to the top from src to dst.
void	pa(t_stack_node **a, t_stack_node **b, bool flag)
{
	push_cmd(a, b);
	if (!flag)
		write (1, "pa\n", 3);
}

//Stack b - Push node to the top from src to dst.
void	pb(t_stack_node **b, t_stack_node **a, bool flag)
{
	push_cmd(b, a);
	if (!flag)
		write(1, "pb\n", 3);
}

/*
- Actualiza los punteros prev y next del nodo que se está moviendo desde la
pila de origen (src) a la pila de destino (dst). Si la pila de destino no está
vacía, se actualiza el puntero prev del primer nodo de la pila de destino para
que apunte al nodo que se está moviendo.

	(*src)->prev = NULL;
	(*src)->next = *dst;
	if (*dst)
		(*dst)->prev = *src;
	*dst = *src;
*/
