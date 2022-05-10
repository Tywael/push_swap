/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalthaus <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:08:47 by yalthaus          #+#    #+#             */
/*   Updated: 2022/01/18 16:43:37 by yalthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c)
	{
		if (*s == 0)
			return (0);
		++s;
	}
	return ((char *)s);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ret;
	size_t	i;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = ft_calloc(len + 1, sizeof(char));
	if (!ret)
		return (0);
	i = 0;
	while (*s1)
		ret[i++] = *s1++;
	while (*s2)
		ret[i++] = *s2++;
	ret[i] = 0;
	return (ret);
}

int	array_len(void *array)
{
	int	i;

	i = 0;
	while (((char **)array)[i] != NULL)
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*s;
	size_t	i;

	i = 0;
	s = (char *)malloc(count * size);
	if (s == NULL)
		return (NULL);
	while (i < count * size)
	{
		*(s + i) = 0;
		i++;
	}
	return ((void *)s);
}
