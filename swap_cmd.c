/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 21:53:59 by bmunoz-c          #+#    #+#             */
/*   Updated: 2024/06/07 16:18:25 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Only with 2 nodes - Swap 1st & 2nd node.
static void	swap_cmd(t_stack_node **head)
{
//	int	len;

//	len = stack_len(*head);
	if (*head == NULL || head == NULL)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

//Stack a - Swap 1st & 2nd node.
void	sa(t_stack_node **a, bool flag)
{
	swap_cmd(a);
	if (!flag)
		write(1, "sa\n", 3);
}

//Stack b - Swap 1st & 2nd node.
void	sb(t_stack_node **b, bool flag)
{
	swap_cmd(b);
	if (!flag)
		write (1, "sb\n", 3);
}

//Stack a&b - Swap 1st & 2nd node.
void	ss(t_stack_node **a, t_stack_node **b, bool flag)
{
	swap_cmd(a);
	swap_cmd(b);
	if (!flag)
		write(1, "ss\n", 3);
}

/*
int	main(void)
{
	t_stack_node	*a;
	int				i;

	i = 0;
	a = NULL;
	create_node(&a, -5);
	create_node(&a, 10);
	create_node(&a, 42);

	t_stack_node	*ca = a;
	while (i < 10)
	{
		while (ca)
		{
			printf("Node &d\n", ca->nbr);
			printf("Prev &d\n", ca->prev);
			printf("Next &d\n", ca->next);
			write(1, "********************\n", 21);
			ca = ca->next;
		}
		ra(&a, 0);
		i++;
	}
	return (0);
}
*/

/*
- Declara un puntero doble head que inicialmente apunta al puntero del
primer nodo de la pila.

- Mueve el puntero head al siguiente nodo en la pila y actualiza los punteros
prev y next de los nodos adyacentes al nodo actualizado para mantener la
coherencia de la estructura de la pila.
 	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;

- Verifica si hay un nodo siguiente al nodo actual y, si es así, actualiza el
puntero prev del nodo siguiente para que apunte al nodo anterior al nodo actual.
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;

- Intercambia los punteros prev y next del nodo actual, lo que efectivamente
invierte la dirección del nodo en la pila.
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
*/
