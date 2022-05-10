/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalthaus <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:56:55 by yalthaus          #+#    #+#             */
/*   Updated: 2022/01/24 16:02:57 by yalthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_push_swap
{
	int		*nbrs;
	int		*a;
	int		*b;
	int		len;
	int		move;
	char	**arg;
	int		bit;
}				t_push_swap;

int		print_arr(char *str, int *nbrs, int len);
int		*chars_to_ints(int len, char **arstr);
int		ft_atoi(const char *str);
int		ft_strlen(const char *str);
int		count_stack(int *nbrs, int len);
void	shift_up(int *nbrs, int len);
void	shift_down(int *nbrs, int len);
int		array_len(void *array);
char	**ft_split(char *s, char c);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_isdigit(int c);
void	*ft_calloc(size_t count, size_t size);
void	ps_sa(t_push_swap *ps);
void	ps_sb(t_push_swap *ps);
void	ps_ss(t_push_swap *ps);
void	ps_ra(t_push_swap *ps);
void	ps_rb(t_push_swap *ps);
void	ps_rr(t_push_swap *ps);
void	ps_rra(t_push_swap *ps);
void	ps_rrb(t_push_swap *ps);
void	ps_rrr(t_push_swap *ps);
void	ps_pa(t_push_swap *ps);
void	ps_pb(t_push_swap *ps);
#endif
