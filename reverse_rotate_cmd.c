/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 21:52:35 by bmunoz-c          #+#    #+#             */
/*   Updated: 2024/05/23 23:42:02 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Bottom to top.
static void	reverse_rotate_cmd(t_stack_node **stack)
{
	t_stack_node	*last;

	if (*stack == NULL || stack == NULL)
		return ;
	last = ft_last_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

//Stack a - Bottom to top.
void	rra(t_stack_node **a, bool flag)
{
	reverse_rotate_cmd(a);
	if (!flag)
		write(1, "rra\n", 4);
}

//Stack b - Bottom to top.
void	rrb(t_stack_node **b, bool flag)
{
	reverse_rotate_cmd(b);
	if (!flag)
		write(1, "rrb\n", 4);
}

//Stack a&b - Bottom to top.
void	rrr(t_stack_node **a, t_stack_node **b, bool flag)
{
	reverse_rotate_cmd(a);
	reverse_rotate_cmd(b);
	if (!flag)
		write(1, "rrr\n", 4);
}

/*
- Rompe la conexión entre el último y el penúltimo nodo, estableciendo
el puntero next del nodo penúltimo como nulo.
	last->prev->next = NULL;

- Conecta el último nodo al frente de la pila, estableciendo el puntero
next del último nodo como el primer nodo y su puntero prev como nulo.
	last->next = *stack;
	last->prev = NULL;

- Mueve el puntero stack al último nodo y ajusta el puntero prev del nuevo
primer nodo para que apunte al último nodo.
	*stack = last;
	last->next->prev = last;
*/
