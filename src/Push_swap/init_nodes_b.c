/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farhan <farhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 19:16:51 by farhan            #+#    #+#             */
/*   Updated: 2025/11/16 19:19:00 by farhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void init_nodes_b(t_stack_node *a, t_stack_node *b)
{
    t_stack_node    *current;

    current = b;
    ft_current_index(a);
    ft_current_index(b);
    ft_set_median_info(a);
    ft_set_median_info(b);
    while (b)
    {
        current->target_node = ft_find_target_node(a, current->value);
        current = current->next;
    }
}
