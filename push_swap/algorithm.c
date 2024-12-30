/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:42:37 by vmustone          #+#    #+#             */
/*   Updated: 2023/04/18 16:01:33 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack_a)
{
	if (stack_a->ptr[0] > stack_a->ptr[1] && stack_a->ptr[0] > stack_a->ptr[2])
		ra(stack_a);
	if (stack_a->ptr[1] > stack_a->ptr[0] && stack_a->ptr[1] > stack_a->ptr[2])
		rra(stack_a);
	if (stack_a->ptr[0] > stack_a->ptr[1])
		sa(stack_a);
}

void	sort_small_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	pos;

	pos = 0;
	while (stack_a->size > 3)
	{
		pos = smallest_index(stack_a);
		while (pos > 0 && pos < stack_a->size)
		{
			if (pos > stack_a->size / 2)
			{
				rra(stack_a);
				pos++;
			}
			if (pos <= stack_a->size / 2)
			{
				ra(stack_a);
				pos--;
			}
		}
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (stack_b->size != 0)
		pa(stack_a, stack_b);
}

void	chunks(t_stack *stack_a, t_stack *stack_b, int chunk_count)
{
	long long int	min;
	long long int	max;
	int				current_c;
	long long int	size_c;
	int				i;

	min = smallest_number(stack_a);
	max = biggest_number(stack_a);
	current_c = 1;
	size_c = (max - min) / chunk_count;
	while (current_c <= chunk_count)
	{
		i = 0;
		while (i <= stack_a->size)
		{
			if (stack_a->ptr[0] <= (long long int)(min + size_c * current_c))
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			i++;
		}
		current_c++;
	}
	while (stack_a->size)
		pb(stack_a, stack_b);
}

void	sort_big_stack(t_stack *stack_a, t_stack *stack_b, int chunk_count)
{
	int	pos;

	pos = 0;
	chunks(stack_a, stack_b, chunk_count);
	while (stack_b->size != 0)
	{
		pos = biggest_index(stack_b);
		while (pos > 0 && pos < stack_b->size)
		{
			if (pos > stack_b->size / 2)
			{
				rrb(stack_b);
				pos++;
			}
			if (pos <= stack_b->size / 2)
			{	
				rb(stack_b);
				pos--;
			}
		}
		pa(stack_a, stack_b);
	}
}
