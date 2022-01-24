/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_move3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalthaus <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:05:20 by yalthaus          #+#    #+#             */
/*   Updated: 2022/01/24 11:49:53 by yalthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rrr(t_push_swap *ps)
{
	int	size_a;
	int	size_b;
	int	temp;

	size_a = count_stack(ps->a, ps->len);
	size_b = count_stack(ps->b, ps->len);
	if (size_a > 1 && size_b > 1)
	{
		temp = ps->a[size_a - 1];
		ps->a[size_a - 1] = 0;
		shift_down(ps->a, ps->len);
		ps->a[0] = temp; 
		temp = ps->b[size_b - 1];
		ps->b[size_b - 1] = 0;
		shift_down(ps->b, ps->len);
		ps->b[0] = temp; 
		ps->move++;
		write(1, "rrr\n", 4);
	}
}
