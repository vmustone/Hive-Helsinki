/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:35:59 by vmustone          #+#    #+#             */
/*   Updated: 2023/05/18 13:11:02 by vmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_string(t_stack *stack_a, t_stack *stack_b, char **argv)
{
	int	i;

	i = 0;
	while (argv[stack_a->size])
		stack_a->size++;
	stack_a->ptr = ft_calloc(stack_a->size + 1, sizeof(int));
	stack_b->size = 0;
	stack_b->ptr = ft_calloc(stack_a->size + 1, sizeof(int));
	if (stack_a->ptr == NULL)
		errors(NULL);
	if (stack_b->ptr == NULL)
		errors(NULL);
	while (i < stack_a->size)
	{
		stack_a->ptr[i] = ft_atoi(argv[i]);
		i++;
	}
}

void	init_stack(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
{
	int	i;

	i = 0;
	stack_a->size = argc - 1;
	stack_a->ptr = ft_calloc(stack_a->size + 1, sizeof(int));
	stack_b->size = 0;
	stack_b->ptr = ft_calloc(stack_a->size + 1, sizeof(int));
	if (stack_a->ptr == NULL)
		errors(NULL);
	if (stack_b->ptr == NULL)
		errors(NULL);
	while (i < stack_a->size)
	{
		stack_a->ptr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
}

void	choose_sorting(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a) == 0)
		exit (0);
	else if (stack_a->size == 2)
		sa(stack_a);
	else if (stack_a->size <= 5)
		sort_small_stack(stack_a, stack_b);
	else if (stack_a->size <= 100)
		sort_big_stack(stack_a, stack_b, 6);
	else if (stack_a->size > 100)
		sort_big_stack(stack_a, stack_b, 16);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	**str;

	str = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2 && ft_strrchr(argv[1], ' ') != 0)
	{
		str = ft_split(argv[1], ' ');
		if (str == NULL)
			errors(NULL);
		if (valid_input(str) == 1)
			errors(str);
		init_string(&stack_a, &stack_b, str);
	}
	else
	{
		if (valid_input(argv) == 1)
			errors(NULL);
		init_stack(&stack_a, &stack_b, argc, argv);
	}
	choose_sorting(&stack_a, &stack_b);
	free_stacks(&stack_a, &stack_b, argc, str);
	return (0);
}
