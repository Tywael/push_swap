/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c	                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalthaus <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:56:17 by yalthaus          #+#    #+#             */
/*   Updated: 2022/01/24 16:02:55 by yalthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_max_min(char *str, int isneg)
{
	if (*(str + 0) >= 2 + 48)
		if (*(str + 1) >= 1 + 48)
			if (*(str + 2) >= 4 + 48)
				if (*(str + 3) >= 7 + 48)
					if (*(str + 4) >= 4 + 48)
						if (*(str + 5) >= 8 + 48)
							if (*(str + 6) >= 3 + 48)
								if (*(str + 7) >= 6 + 48)
									if (*(str + 8) >= 4 + 48)
										if (*(str + 9) >= 8 + isneg + 48)
											return (1);
	return (0);
}

int	num_val(char *str)
{
	int	isneg;

	isneg = 0;
	if (*str == '-')
	{
		isneg = 1;
		str++;
	}
	if (check_max_min(str, isneg))
		return (ft_perror(NULL));
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (ft_perror(NULL));
		str++;
	}
	return (0);
}

int	*chars_to_ints(int len, char **arstr)
{
	int	*nbrs;
	int	i;

	i = -1;
	nbrs = (int *)ft_calloc(len + 1, sizeof(*nbrs));
	if (!nbrs)
		return (NULL);
	while (++i < len)
	{
		if (ft_strlen(arstr[i]) > 10 + (*(arstr[i]) == '-')
			|| num_val(arstr[i]))
		{
			free(nbrs);
			ft_perror(NULL);
			return (NULL);
		}
		nbrs[i] = ft_atoi(arstr[i]);
	}
	return (nbrs);
}

int	*init_b(int len)
{
	int	*nbrs;

	nbrs = (int *)ft_calloc(len + 1, sizeof(int));
	if (!nbrs)
		return (NULL);
	return (nbrs);
}

int	*format_ints(int *nbrs, int len)
{
	int	*a;
	int	i;

	i = -1;
	a = (int *)ft_calloc(len + 1, sizeof(int));
	if (!a)
		return (NULL);
	while (++i < len)
		a[i] = count_lower(nbrs[i], nbrs, len) + 1;
	return (a);
}
