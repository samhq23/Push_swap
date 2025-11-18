/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farhan <farhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 05:34:56 by farhan            #+#    #+#             */
/*   Updated: 2025/11/18 07:12:29 by farhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

/* ************************************************************************** */
/*                              STRUCT DEFINITION                             */
/* ************************************************************************** */

typedef struct s_stack_node
{
	int					value;
	int					current_index;
	int					cost_a;
	int					cost_b;
	int					total_cost;
	int					above_median;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

/* ************************************************************************** */
/*                           COMMAND OPERATIONS                               */
/* ************************************************************************** */

// Push operations
void			pa(t_stack_node **stack_b, t_stack_node **stack_a);
void			pb(t_stack_node **stack_a, t_stack_node **stack_b);

// Swap operations
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);

// Rotate operations
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);

// Reverse rotate operations
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

/* ************************************************************************** */
/*                           SORTING FUNCTIONS                                */
/* ************************************************************************** */

void			ft_sort_stacks(t_stack_node **a, t_stack_node **b);
void			ft_sort_three(t_stack_node **a);

/* ************************************************************************** */
/*                           HELPER FUNCTIONS                                 */
/* ************************************************************************** */

// Stack utilities
int				ft_stack_len(t_stack_node *s);
int				ft_is_sorted(t_stack_node *s);
t_stack_node	*ft_find_end(t_stack_node **s);
t_stack_node	*ft_find_min(t_stack_node *s);
t_stack_node	*ft_find_max(t_stack_node *s);

// Node initialization and preparation
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
void			ft_current_index(t_stack_node *s);
void			ft_prep_for_push(t_stack_node **s, t_stack_node *node,
					char stack_name);

// Cost calculation and target finding
void			ft_set_cost(t_stack_node *a, t_stack_node *b);
t_stack_node	*ft_find_cheapest_node(t_stack_node *s);
t_stack_node	*ft_find_target_node(t_stack_node *a, int b_value);

// Math utilities
int				ft_abs(int n);

/* ************************************************************************** */
/*                        PARSING AND ERROR HANDLING                          */
/* ************************************************************************** */

void			ft_parsing(t_stack_node **a, int argc, char **argv);
int				error_syntax(char *str);
int				error_duplicate(t_stack_node *a, int value);

/* ************************************************************************** */
/*                          MEMORY MANAGEMENT                                 */
/* ************************************************************************** */

void			ft_free_stack(t_stack_node **stack);
void			free_error(t_stack_node **a);

/* ************************************************************************** */
/*                          EXTERNAL FUNCTIONS                                */
/* ************************************************************************** */

// If you're using ft_printf from your libft
int				ft_printf(const char *format, ...);

#endif
