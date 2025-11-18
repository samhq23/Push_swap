/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoque <shoque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 06:49:26 by farhan            #+#    #+#             */
/*   Updated: 2025/11/18 17:06:52 by shoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static long	ft_atoi(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

static void	ft_append_node(t_stack_node **stack, int value)
{
	t_stack_node	*new_node;
	t_stack_node	*last;

	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = NULL;
	if (!*stack)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last = ft_find_end(stack);
		last->next = new_node;
		new_node->prev = last;
	}
}

static void	free_split(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static void	ft_parse_arg(t_stack_node **a, char *arg)
{
	char	**nums;
	long	value;
	int		j;

	nums = ft_split(arg);
	if (!nums)
		free_error(a);
	j = -1;
	while (nums[++j])
	{
		if (error_syntax(nums[j]))
			free_error(a);
		value = ft_atoi(nums[j]);
		if (value > INT_MAX || value < INT_MIN)
			free_error(a);
		if (error_duplicate(*a, (int)value))
			free_error(a);
		ft_append_node(a, (int)value);
	}
	free_split(nums);
}

void	ft_parsing(t_stack_node **a, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_parse_arg(a, argv[i]);
		i++;
	}
}
