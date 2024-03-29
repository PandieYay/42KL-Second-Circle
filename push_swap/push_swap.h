/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlim <edlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:14:45 by edlim             #+#    #+#             */
/*   Updated: 2022/05/09 11:14:46 by edlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_array {
	int		*stacka;
	int		*stackb;
	int		sizea;
	int		sizeb;
	int		pi;
	int		ori;
	int		median;
	int		rcount;
}	t_array;

int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(const char *str);
int		checkarg(char **argv);
char	ft_atoichecker(const char *str);
char	**ft_split(char const *s, char c);
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
void	quicksort(t_array *array, int len);
void	quicksortb(t_array *array, int len);
void	insertionsort(t_array *array, int len);
void	insertionsortb(t_array *array, int len);
void	partitionisthree(t_array *array, int len);
void	partitionisthreeb(t_array *array, int len);
int		findmedian(int *arr, int n);
int		bubblesort(int *arr, t_array *array);
int		sortmedian(t_array *array);
int		sortmedianb(t_array *array);

#endif