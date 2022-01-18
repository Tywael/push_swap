/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalthaus <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:56:55 by yalthaus          #+#    #+#             */
/*   Updated: 2022/01/18 17:12:39 by yalthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_push_swap
{
	int	*nbrs;
	int	*a;
	int	*b;
	int	len;
}				t_push_swap;

int		print_arr(char *str, int *nbrs, int len);
int		*chars_to_ints(int len, char **arstr);
int		ft_atoi(const char *str);
int		ft_strlen(const char *str);
void	ps_sa(void);
void	ps_sb(void);
void	ps_ss(void);
void	ps_ra(void);
void	ps_rb(void);
void	ps_rr(void);
void	ps_rra(void);
void	ps_rrb(void);
void	ps_rrr(void);
void	ps_pa(void);
void	ps_pb(void);
#endif
