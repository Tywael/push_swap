/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalthaus <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:08:47 by yalthaus          #+#    #+#             */
/*   Updated: 2022/01/11 17:09:07 by yalthaus         ###   ########.fr       */
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
	ret = malloc(len + 1);
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
