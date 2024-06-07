/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:27:32 by bmunoz-c          #+#    #+#             */
/*   Updated: 2024/05/24 15:35:28 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
//# include "../libft/inc/libft.h"
//# include "../libft/inc/ft_printf.h"
# include <stdlib.h>
# include <stddef.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*set_target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack_node;

//---ARGUMENTS---//
int				check_args(int ac, char **av);
int				isnum(char *s);
void			limits(long n);
int				isduplicate(int i, char **av);
void			ft_error(void);
//---Utils---//
long			ft_atol(char *s);
int				ft_strlen(char *s);

//---STACK & NODE CREATION---//
void			create_node(t_stack_node **stack, int n);
void			init_stack(t_stack_node **a, char **av);
//---Utils---//
int				stack_len(t_stack_node *stack);
t_stack_node	*find_small(t_stack_node *stack);
t_stack_node	*return_cheapest(t_stack_node *stack);
t_stack_node	*find_big(t_stack_node *stack);
t_stack_node	*ft_last_node(t_stack_node *head);
//void			print_stack(t_stack_node *stack);

//---COMMANDS---//
//swap
//void			swap_cmd(t_stack_node **head);
void			sa(t_stack_node **a, bool flag);
void			sb(t_stack_node **b, bool flag);
void			ss(t_stack_node **a, t_stack_node **b, bool flag);
//rotate
//void			rotate_cmd(t_stack_node **stack);
void			ra(t_stack_node **a, bool flag);
void			rb(t_stack_node **b, bool flag);
void			rr(t_stack_node **a, t_stack_node **b, bool flag);
//reverse rotate
//void			reverse_rotate_cmd(t_stack_node **stack);
void			rra(t_stack_node **a, bool flag);
void			rrb(t_stack_node **b, bool flag);
void			rrr(t_stack_node **a, t_stack_node **b, bool flag);
//push
//void			push_cmd(t_stack_node **dst, t_stack_node **src);
void			pa(t_stack_node **a, t_stack_node **b, bool flag);
void			pb(t_stack_node **b, t_stack_node **a, bool flag);

//---ALGORYTHM---//
bool			stack_sorted(t_stack_node *stack);
void			sort_three(t_stack_node **a);
//void			set_target_node(t_stack_node *a, t_stack_node *b);
void			sort_five(t_stack_node **a, t_stack_node **b);
//---Utils---//
void			set_cost(t_stack_node *a, t_stack_node *b);
void			set_index(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
void			init_node(t_stack_node *a, t_stack_node *b);

//---PUSH SWAP COMMANDS---//
void			push_swap(t_stack_node **a, t_stack_node **b);
//void			move_nodes(t_stack_node **a, t_stack_node **b);
//void			rotate_both(t_stack_node **a, t_stack_node **b,
//					t_stack_node *cheapest);
//void			reverse_rotate_both(t_stack_node **a, t_stack_node **b,
//					t_stack_node *cheapest);
void			prep_4push(t_stack_node **stack, t_stack_node *head_node,
					char stack_name);

//---FREE---//
void			ft_error(void);
void			free_stack(t_stack_node **stack);

//---MAIN FUNCTION---//
//int	main(int ac, char **av);

#endif
