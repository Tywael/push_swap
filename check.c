/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c	                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalthaus <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:56:17 by yalthaus          #+#    #+#             */
/*   Updated: 2022/01/24 16:02:55 by yalthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_tried(int *nbrs, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		if (nbrs[i] != i + 1)
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

int	is_revtried(int	*nbrs, int len)
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

int	count_stack(int *nbrs, int len)
{
	int	i;
	int	n;

	i = -1;
	n = 0;
	while (++i < len)
	{
		if (nbrs[i])
			n++;
		else
			break ;
	}
	return (n);
}
