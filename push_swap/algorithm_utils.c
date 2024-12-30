/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:42:51 by vmustone          #+#    #+#             */
/*   Updated: 2023/05/04 22:45:07 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smallest_index(t_stack *stack_a)
{
	int	i;
	int	smallest;
	int	smallest_index;

	i = 0;
	smallest = stack_a->ptr[0];
	while (i < stack_a->size)
	{
		if (stack_a->ptr[i] <= smallest)
		{
			smallest = stack_a->ptr[i];
			smallest_index = i;
		}
		i++;
	}
	return (smallest_index);
}

int	smallest_number(t_stack *stack_a)
{
	int	i;
	int	smallest;

	i = 0;
	smallest = stack_a->ptr[0];
	while (i < stack_a->size)
	{
		if (stack_a->ptr[i] <= smallest)
			smallest = stack_a->ptr[i];
		i++;
	}
	return (smallest);
}

int	biggest_number(t_stack *stack_a)
{
	int	i;
	int	max;

	i = 0;
	max = stack_a->ptr[0];
	while (i < stack_a->size)
	{
		if (stack_a->ptr[i] >= max)
			max = stack_a->ptr[i];
		i++;
	}
	return (max);
}

int	biggest_index(t_stack *stack_b)
{
	int	i;
	int	max;
	int	index;

	i = 0;
	max = stack_b->ptr[0];
	while (i < stack_b->size)
	{
		if (stack_b->ptr[i] >= max)
		{
			max = stack_b->ptr[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	is_sorted(t_stack *stack_a)
{
	int	i;

	i = 0;
	while (i < stack_a->size - 1)
	{
		if (stack_a->ptr[i] > stack_a->ptr[i + 1])
			return (1);
		i++;
	}
	return (0);
}
