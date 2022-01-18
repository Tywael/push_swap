/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalthaus <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:56:17 by yalthaus          #+#    #+#             */
/*   Updated: 2022/01/18 17:14:41 by yalthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_tried(int *nbrs, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		if (nbrs[i] != i)
			return (0);
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
		a[i] = count_lower(nbrs[i], nbrs, len);
	return (a);
}

int	print_arr(char *str, int *nbrs, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		printf("%s\t%i\n", str, nbrs[i]);
	return (0);
}

int	*init_b(int len)
{
	int	*nbrs;

	nbrs = (int *)malloc(sizeof(int) * len);
	if (!nbrs)
		return (NULL);
	return (nbrs);
}

int	print_ps(t_push_swap ps)
{
	printf("######ARRAY_A#######\n");
	print_arr("a :", ps.a, ps.len);
	printf("######ARRAY_B#######\n");
	print_arr("b :", ps.b, ps.len);
	return (0);
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
	{
		printf("error :\tdup in args");
		return (1);
	}
	ps.a = format_ints(ps.nbrs, ps.len);
	ps.b = init_b(ps.len);
	print_arr("nbrs :", ps.nbrs, ps.len);
	print_ps(ps);
	if (is_tried(ps.a, ps.len))
	{
		printf("tried");
		return (1);
	}
	return (0);
}
