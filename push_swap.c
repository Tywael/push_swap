/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalthaus <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:56:17 by yalthaus          #+#    #+#             */
/*   Updated: 2022/01/11 18:07:05 by yalthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *arstr_toarint(int len, char **arstr)
{
	int	*nbrs;
	int	i;

	i = -1;
	nbrs = (int *)malloc((len + 1) * sizeof(*nbrs));
	if (!nbrs)
		return (NULL);
	while (++i < len)
		nbrs[i] = ft_atoi(arstr[i]);

}

int	main(int argc, char **argv)
{
	if (argc > 1)
		
}
