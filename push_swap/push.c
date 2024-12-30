/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:40:22 by vmustone          #+#    #+#             */
/*   Updated: 2023/05/11 20:05:20 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	if (stack_a->size == 0)
		return ;
	i = stack_b->size;
	stack_b->size++;
	while (i)
	{
		stack_b->ptr[i] = stack_b->ptr[i - 1];
		i--;
	}
	stack_b->ptr[0] = stack_a->ptr[0];
	stack_a->size--;
	i = 0;
	while (i < stack_a->size)
	{
		stack_a->ptr[i] = stack_a->ptr[i + 1];
		i++;
	}
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}
