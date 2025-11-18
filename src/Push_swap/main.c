/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farhan <farhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 19:31:03 by farhan            #+#    #+#             */
/*   Updated: 2025/11/18 07:08:11 by farhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    main(int argc, char **argv)
{
    t_stack_node    *a;
    t_stack_node    *b;

    a = NULL;
    b = NULL;
    if (argc < 2)
        return (0);
    ft_parsing(&a, argc, argv);
    if (ft_is_sorted(a))
    {
        ft_free_stack(&a);
        return (0);
    }
    ft_sort_stacks(&a, &b);
    ft_free_stack(&a);
    ft_free_stack(&b);
    return (0);
}