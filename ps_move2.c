/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_move2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalthaus <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:01:10 by yalthaus          #+#    #+#             */
/*   Updated: 2022/01/24 11:49:08 by yalthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_ra(t_push_swap *ps)
{
	int	size;
	int	temp;

	size = count_stack(ps->a, ps->len);
	if (size > 1)
	{
		temp = ps->a[0];
		shift_up(ps->a, ps->len);
		ps->a[size - 1] = temp;
		write(1, "ra\n", 3);
		ps->move++;
	}
}

void	ps_rb(t_push_swap *ps)
{
	int	size;
	int	temp;

	size = count_stack(ps->b, ps->len);
	if (size > 1)
	{
		temp = ps->b[0];
		shift_up(ps->b, ps->len);
		ps->b[size - 1] = temp;
		write(1, "rb\n", 3);
		ps->move++;
	}
}

void	ps_rr(t_push_swap *ps)
{
	int	size_a;
	int	size_b;
	int	temp;

	size_a = count_stack(ps->a, ps->len);
	size_b = count_stack(ps->b, ps->len);
	if(size_a > 1 && size_b > 1)
	{	
		temp = ps->b[0];
		shift_up(ps->b, ps->len);
		ps->b[size_b - 1] = temp;
		temp = ps->a[0];
		shift_up(ps->a, ps->len);
		ps->a[size_a - 1] = temp;
		write(1, "rr\n", 3);
		ps->move++;
	}
}

void	ps_rra(t_push_swap *ps)
{
	int	size;
	int	temp;

	size = count_stack(ps->a, ps->len);
	if (size > 1)
	{
		temp = ps->a[size - 1];
		shift_down(ps->a, ps->len);
		ps->a[0] = temp;
		write(1, "rra\n", 4);
		ps->move++;
	}
}

void	ps_rrb(t_push_swap *ps)
{
	int	size;
	int	temp;

	size = count_stack(ps->b, ps->len);
	if (size > 1)
	{
		temp = ps->b[size - 1];
		shift_down(ps->b, ps->len);
		ps->b[0] = temp;
		write(1, "rrb\n", 4);
		ps->move++;
	}
}
