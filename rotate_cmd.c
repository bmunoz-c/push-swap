/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 21:53:51 by bmunoz-c          #+#    #+#             */
/*   Updated: 2024/05/23 23:42:23 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Top to Bottom position.
static void	rotate_cmd(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (*stack == NULL || stack == NULL)
		return ;
	last_node = ft_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

//Stack a - Top to Bottom.
void	ra(t_stack_node **a, bool flag)
{
	rotate_cmd(a);
	if (!flag)
		write(1, "ra\n", 3);
}

//Stack b - Top to Bottom.
void	rb(t_stack_node **b, bool flag)
{
	rotate_cmd(b);
	if (!flag)
		write(1, "rb\n", 3);
}

//Stack a&b - Top to Bottom.
void	rr(t_stack_node **a, t_stack_node **b, bool flag)
{
	rotate_cmd(a);
	rotate_cmd(b);
	if (!flag)
		write(1, "rr\n", 3);
}

/*
- Conecta el último nodo encontrado con el primer nodo de la pila.
	last_node->next = *stack;

- Mueve el puntero stack al siguiente nodo en la pila y establece el 
puntero prev del nuevo primer nodo como nulo.
	*stack = (*stack)->next;
	(*stack)->prev = NULL;

- Actualiza los punteros prev y next del nodo que ahora está al frente
de la pila para que sea el último nodo y rompe la conexión para evitar ciclos.
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
*/
