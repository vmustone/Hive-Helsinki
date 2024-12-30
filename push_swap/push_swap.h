/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:41:13 by vmustone          #+#    #+#             */
/*   Updated: 2023/05/11 18:43:24 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_stack
{
	int	*ptr;
	int	size;
}				t_stack;

void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	sort_small_stack(t_stack *stack_a, t_stack *stack_b);
void	sort_big_stack(t_stack *stack_a, t_stack *stack_b, int chunk_count);
int		is_sorted(t_stack *stack_a);
int		valid_input(char **argv);
int		biggest_index(t_stack *stack_b);
int		biggest_number(t_stack *stack_a);
int		smallest_number(t_stack *stack_a);
int		smallest_index(t_stack *stack_a);
void	free_stacks(t_stack *stack_a, t_stack *stack_b, int argc, char **argv);
void	errors(char **argv);
#endif