/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlim <edlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:14:45 by edlim             #+#    #+#             */
/*   Updated: 2022/05/19 10:48:47 by edlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_array {
	int		*stacka;
	int		*stackb;
	int		sizea;
	int		sizeb;
	int		racount;
	int		rbcount;
}	t_array;

int		ft_strncmp(char *s1, char *s2, size_t n);
int		ft_atoi(const char *str);
char	ft_atoichecker(const char *str);
char	**ft_split(char const *s, char c);
int		checkarg(char **argv);
void	sa(t_array *array);
void	sb(t_array *array);
void	ss(t_array *array);
void	pa(t_array *array);
void	pb(t_array *array);
void	ra(t_array *array);
void	rb(t_array *array);
void	rr(t_array *array);
void	rra(t_array *array);
void	rrb(t_array *array);
void	rrr(t_array *array);
int		bubblesort(int *arr, t_array *array);
char	*get_next_line(int fd);

#endif
