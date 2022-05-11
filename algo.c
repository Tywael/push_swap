/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalthaus <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:56:17 by yalthaus          #+#    #+#             */
/*   Updated: 2022/01/24 16:02:55 by yalthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	all_a(t_push_swap *ps)
{
	int	size_b;

	size_b = count_stack(ps->b, ps->len);
	while (size_b-- > 0)
		ps_pa(ps);
	return (0);
}

int	algo_3(t_push_swap *ps)
{
	if (ps->len == 2)
	{
		ps_rra(ps);
		return (0);
	}
	if (ps->a[0] > ps->a[1])
		ps_sa(ps);
	if (ps->a[1] > ps->a[2])
		ps_rra(ps);
	if (ps->a[0] > ps->a[1])
		ps_sa(ps);
	return (0);
}

int	algo_5(t_push_swap *ps)
{
	int	i;

	i = -1;
	while (++i < ps->len)
	{
		if (ps->a[0] == 4 || ps->a[0] == 5)
			ps_pb(ps);
		else
			ps_ra(ps);
	}
	algo_3(ps);
	if (ps->b[0] < ps->b[1])
		ps_sb(ps);
	ps_pa(ps);
	ps_pa(ps);
	ps_ra(ps);
	ps_ra(ps);
	return (0);
}

void	algo(t_push_swap *ps)
{
	int	i;
	int	j;

	i = -1;
	while (++i < ps->bit && !is_tried(ps->a, ps->len))
	{
		j = count_stack(ps->a, ps->len);
		while (j-- > 0)
		{
			if (ps->a[0] >> i & 1)
				ps_ra(ps);
			else
				ps_pb(ps);
		}
		j = count_stack(ps->b, ps->len);
		while (j-- > 0)
			ps_pa(ps);
	}
	all_a(ps);
}
