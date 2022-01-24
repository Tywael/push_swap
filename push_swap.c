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

int	is_tried(int *nbrs, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		if (nbrs[i] != i + 1)
			return (0);
	return (1);
}

void	bit_decal(t_push_swap *ps)
{
	int	nbr;
	int	i;

	i = 0;
	nbr = ps->len;
	while (nbr / 2 > 1)
	{
		nbr /= 2;
		i++;
	}
	ps->bit = i + 2;
}

int	all_a(t_push_swap *ps)
{
	int	size_b;

	size_b = count_stack(ps->b, ps->len);
	while (size_b-- > 0)
		ps_pa(ps);
	return (0);
}

int is_revtried(int	*nbrs, int len)
{
	int	i;

	i = -1;
	while (len > 0)
	{
		i++;
		if (nbrs[i] != len)
			return (0);
		len--;
	}
	return (1);
}

int	check_dup(int *nbrs, int len)
{
	int	i;
	int	j;
	int	same;

	same = 0;
	j = -1;
	while (++j < len)
	{
		i = -1;
		while (++i < len)
			if (nbrs[j] == nbrs[i])
				same++;
	}
	if (same != len)
		return (1);
	return (0);
}

int	count_stack(int *nbrs, int len)
{
	int	i;
	int	n;

	i = -1;
	n = 0;
	while (++i < len)
		if (nbrs[i])
			n++;
		else
			break ;
	return (n);
}

void	shift_down(int *nbrs, int len)
{
	int	tmp;

	tmp = len;
	if (len > 1 && !nbrs[len - 1])
	{
		while (--len)
			nbrs[len] = nbrs[len - 1];
		nbrs[0] = 0;
	}
}

void	shift_up(int *nbrs, int len)
{
	int	i;

	i = -1;
	if (len > 1 && !nbrs[0])
	{
		while (++i < len)
			nbrs[i] = nbrs[i + 1];
		nbrs[len - 1] = 0;
	}
}

int	*chars_to_ints(int len, char **arstr)
{
	int	*nbrs;
	int	i;

	i = -1;
	nbrs = (int *)malloc(len * sizeof(*nbrs));
	if (!nbrs)
		return (NULL);
	while (++i < len)
	{
		nbrs[i] = ft_atoi(arstr[i]);
	}
	return (nbrs);
}

int	count_lower(int n, int *nbrs, int len)
{
	int	i;
	int	ret;

	i = -1;
	ret = -1;
	while (++i < len)
		if (n >= nbrs[i])
			ret++;
	return (ret);
}

int	*format_ints(int *nbrs, int len)
{
	int	*a;
	int	i;

	i = -1;
	a = (int *)malloc(len * sizeof(*a));
	if (!a)
		return (NULL);
	while (++i < len)
		a[i] = count_lower(nbrs[i], nbrs, len) + 1;
	return (a);
}

int	*init_b(int len)
{
	int	*nbrs;

	nbrs = (int *)malloc(sizeof(int) * len);
	if (!nbrs)
		return (NULL);
	return (nbrs);
}

int	algo_3(t_push_swap *ps)
{
	int	i;

	i = 0;
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
		if(ps->a[0] == 4 || ps->a[0] == 5)
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
	int	n;

	i = -1;
	while (++i < ps->bit && !is_tried(ps->a, ps->len))
	{
		j = count_stack(ps->a, ps->len);
		while (j-- > 0)
			if (ps->a[0] >> i & 1)
				ps_ra(ps);
			else
				ps_pb(ps);
		n = j;
		j = count_stack(ps->b, ps->len);
		while (j-- > 0)
			if ((ps->b[0] >> i) != 0)
				ps_pa(ps);
			else
				ps_rb(ps);
	}
	all_a(ps);
}

int	main(int argc, char **argv)
{
	t_push_swap	ps;
	int			i;

	i = -1;
	ps.len = argc - 1;
	if (argc > 1)
		if (argc > 2)
			ps.nbrs = chars_to_ints(ps.len, argv + 1);
	if (check_dup(ps.nbrs , ps.len))
		return (1);
	ps.a = format_ints(ps.nbrs, ps.len);
	ps.b = init_b(ps.len);
	ps.move = 0;
	bit_decal(&ps);
	if (is_tried(ps.a, ps.len))
		return (1);
	if (ps.len <= 3)
		return (algo_3(&ps));
	if (ps.len == 5)
		return (algo_5(&ps));
	algo(&ps);
	return (0);
}
