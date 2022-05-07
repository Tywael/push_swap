/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalthaus <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:11:55 by yalthaus          #+#    #+#             */
/*   Updated: 2022/01/11 18:07:03 by yalthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	ft_blockcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*s)
	{
		if (i == 0 && *s != c)
		{
			i = 1;
			count++;
		}
		else if (i == 1 && *s == c)
			i = 0;
		s++;
	}
	return (count);
}

int	ft_blocklen(char *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static void	*ft_freearray(char **array, int i)
{
	while (i-- > 0)
		free(array[i]);
	free(array);
	return (NULL);
}

char	**ft_split(char*s, char c)
{
	char	**array;
	int		blockcount;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	blockcount = ft_blockcount(s, c);
	array = (char **)malloc((blockcount + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	while (blockcount--)
	{
		while (*s == c && *s != '\0')
			s++;
		array[i] = ft_substr(s, 0, ft_blocklen(s, c));
		if (!array[i])
			return (ft_freearray(array, i));
		s = s + ft_blocklen(s, c);
		i++;
	}
	array[i] = NULL;
	return (array);
}