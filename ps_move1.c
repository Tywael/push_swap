/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_move1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalthaus <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:58:07 by yalthaus          #+#    #+#             */
/*   Updated: 2022/01/24 11:49:40 by yalthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sa(t_push_swap *ps)
{
	int	temp;

	if (ps->a[0] && ps->a[1])
	{
		temp = ps->a[0];
		ps->a[0] = ps->a[1];
		ps->a[1] = temp;
		write(1, "sa\n", 3);
		ps->move++;
	}
}

void	ps_sb(t_push_swap *ps)
{
	int	temp;

	if (ps->b[0] && ps->b[1])
	{
		temp = ps->b[0];
		ps->b[0] = ps->b[1];
		ps->b[1] = temp;
		write(1, "sb\n", 3);
		ps->move++;
	}
}

void	ps_ss(t_push_swap *ps)
{
	int	temp;

	if (ps->a[0] && ps->a[1] && ps->b[0] && ps->b[1])
	{
		temp = ps->a[0];
		ps->a[0] = ps->a[1];
		ps->a[1] = temp;
		temp = ps->b[0];
		ps->b[0] = ps->b[1];
		ps->b[1] = temp;
		write(1, "ss\n", 3);
		ps->move++;
	}
}

void	ps_pa(t_push_swap *ps)
{
	if (ps->b[0])
	{
		shift_down(ps->a, ps->len);
		ps->a[0] = ps->b[0];
		ps->b[0] = 0;
		shift_up(ps->b, ps->len);
		write(1, "pa\n", 3);
		ps->move++;
	}
}

void	ps_pb(t_push_swap *ps)
{	
	if (ps->a[0])
	{
		shift_down(ps->b, ps->len);
		ps->b[0] = ps->a[0];
		ps->a[0] = 0;
		shift_up(ps->a, ps->len);
		write(1, "pb\n", 3);
		ps->move++;
	}
}
