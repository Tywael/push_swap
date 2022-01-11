/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalthaus <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:08:27 by yalthaus          #+#    #+#             */
/*   Updated: 2022/01/11 17:08:41 by yalthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	skipspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi(const	char *str, t_info *info)
{
	int	result;
	int	sign;
	int	int_len;

	result = 0;
	sign = 1;
	int_len = 0;
	if (*str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = (result * 10) + (*str++ - '0');
		int_len++;
	}
	if (int_len > 10 && sign == 1)
		error(info);
	else if (int_len > 10)
		error(info);
	return (result * sign);
}

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9') || c == ' ' || c == '-')
		return (1);
	else
		return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		if (len > j && start <= i)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

void	same_arg(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < info->argc - 1)
	{
		while (j < info->argc)
		{
			if (info->first_step[i] == info->first_step[j])
			{
				error(info);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
}
