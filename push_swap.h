/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mman <mman@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:35:19 by mman              #+#    #+#             */
/*   Updated: 2024/04/01 20:12:05 by mman             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_member
{
	int				value;
	int				s_index; //Distance to first node (0 is start / Head)
	int				cost; //Used when finding optimal move
	int				b_value;
	int				x_value;
	int				move_up; //How far is it supposed to move UP
	int				mover_two; //How far is it supposed to move REVERSE
	struct s_member	*next;
	struct s_member	*prev;
}				t_value;

void	fullstack(t_value *stack);

// errors
void	ft_error(void);
void	ft_allocation_failure(char *str);

// utilities
int		ft_checksorted(t_value *list);
int		ft_util_stacksize(t_value *stack);
t_value	*ft_util_reset_head(t_value **stack);
t_value	*ft_search_by_index(t_value **stack, int searched_index);
t_value	*ft_search_by_value(t_value **stack, int searched_index);
t_value	*ft_last(t_value **x);
void	ft_clean(t_value **a);
void	free_split_result(char **split_result);
int		ft_biggestvalueinstack(t_value **a);
int		ft_smallestvalueinstack(t_value **a);
int		ft_stack_size(t_value **entry_node);
t_value	*ft_lowest_cost(t_value **a);
int		ft_direction(t_value **a);
int		ft_find_closest_smaller(t_value **stack, int searched_index);
void 	ft_cost_assigner(t_value *node, t_value **a, t_value **b);
void	ft_subcostassigner(t_value *node, t_value *b_node,
			int a_size, t_value **b);

// head initiation
t_value	*ft_init(int size, char **values);
t_value	*ft_new_head(int value);
void	ft_add_back(t_value **head, int value, int index);
void	ft_free(t_value **head);
int		ft_checkifvalid(t_value **values);

void	ft_sort(t_value	**a);
void	ft_last_three(t_value **a);
int		ft_last_three_logic(t_value **a, t_value **crawl);
void	ft_algo_perform(t_value **a);
void	ft_last_b(t_value **a, t_value **b);

// t
void	ft_rotate(void *data);
void	ft_reverse_rotate(void *data);
void	ft_lstitr(t_value *lst, void (*f)(void*));

// the moves
void	ft_m_rb(t_value **b);
void	ft_m_ra(t_value **list);

void	ft_moves_ra(t_value **list);
void	ft_moves_rr(t_value **a, t_value **b);
void	ft_moves_rrr(t_value **a, t_value **b);
void	ft_moves_rra(t_value **list);
void	ft_moves_sa(t_value **list);
void	ft_moves_pa(t_value **a, t_value **b);
void	ft_moves_pb(t_value **a, t_value **b);
void	ft_moves_rb(t_value **b);
void	ft_firsttolast(t_value **list);
void	ft_lasttofirst(t_value **list);

// the algo
void	ft_algo_b(t_value **a, t_value **b);
void	ft_algo_wrap(t_value **a, t_value **b);
void	ft_check_descending(t_value **b);
void	ft_back_to_a(t_value **a, t_value **b);
void	ft_sub_aligner(t_value **a, t_value **b);

void	ft_findmove(t_value **a, t_value **b);
void	ft_subfindmove(t_value **a, t_value **b);
void	ft_subsubfindmove(t_value **a, t_value **b, int x, int y);

#endif
