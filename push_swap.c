/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalthaus <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:56:17 by yalthaus          #+#    #+#             */
/*   Updated: 2022/01/24 16:02:55 by yalthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bit_decal(t_push_swap *ps)
{
	int	nbr;
	int	i;

	i = 0;
	nbr = ps->len;
	while (nbr / 2 >= 1)
	{
		nbr /= 2;
		i++;
	}
	ps->bit = i + 2;
}

int	ft_perror(void *ptr)
{
	if (ptr)
		free(ptr);
	write(1, "Error\n", 6);
	exit(1);
	return (1);
}

void	free_ps(t_push_swap *ps)
{
	int	i;

	i = -1;
	free(ps->nbrs);
	if (ps->arg != NULL)
		while (ps->arg[++i] != NULL)
			free(ps->arg[i]);
	if (ps->arg != NULL)
		free(ps->arg);
	free(ps->a);
	free(ps->b);
}

int	push_swap(t_push_swap *ps)
{
	ps->a = format_ints(ps->nbrs, ps->len);
	ps->b = init_b(ps->len);
	ps->move = 0;
	bit_decal(ps);
	if (is_tried(ps->a, ps->len))
	{
		free_ps(ps);
		return (1);
	}
	else if (ps->len <= 3)
		algo_3(ps);
	else if (ps->len == 5)
		algo_5(ps);
	else
		algo(ps);
	free_ps(ps);
	return (0);
}

int	main(int argc, char **argv)
{
	t_push_swap	ps;

	ps.arg = NULL;
	if (argc > 2)
	{
		ps.len = argc - 1;
		ps.nbrs = chars_to_ints(ps.len, argv + 1);
		if (!ps.nbrs)
			return (0);
	}
	else if (argc == 1)
		exit(1);
	else
	{
		ps.arg = ft_split(argv[1], ' ');
		ps.len = array_len(ps.arg);
		ps.nbrs = chars_to_ints(ps.len, ps.arg);
		if (!ps.nbrs)
			return (0);
	}
	if (check_dup(ps.nbrs, ps.len))
	{
		return (ft_perror(ps.nbrs));
	}
	return (push_swap(&ps));
}
