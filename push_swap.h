/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombier <acombier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 21:37:16 by adghouai          #+#    #+#             */
/*   Updated: 2026/01/21 17:50:11 by acombier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <stdlib.h>
# include <unistd.h>

typedef struct s_benchmark
{
	int			enabled;
	float		disorder;
	int			strategy;
	int			total_ops;
	int			sa;
	int			sb;
	int			ss;
	int			pa;
	int			pb;
	int			ra;
	int			rb;
	int			rr;
	int			rra;
	int			rrb;
	int			rrr;
}				t_benchmark;

typedef struct s_strat
{
	int			strategy;
	float		disorder;
}				t_strat;

typedef struct s_stack
{
	int			**array;
	size_t		size;
	t_benchmark	*bench;
}				t_stack;

typedef struct s_chunk_info
{
	int			min;
	int			max;
	int			chunk_size;
	size_t		num_chunks;
}				t_chunk_info;

void			init_benchmark(t_benchmark *bench);
void			print_benchmark(t_benchmark *bench);

// ft_printf
int				ft_printf(const char *str, int output, ...);

// Parsing and error handling
void			error_checker(char **argv, int argc, t_stack *a);
int				ft_atoi(const char *nptr);
int				ft_atoi_range(const char *nptr);
int				option_check(char *arg);
int				ft_isdigit(int c);
char			**ft_split(char *s, char c);
size_t			compute_tab_len(char **argv, int argc);
void			free_double_tab(char **tab);
void			options_selector(int argc, char **argv, t_benchmark *bench);
int				ft_strcmp(char *s1, const char *s2);
int				initialize_stack_array(t_stack *stack, size_t size);
void			free_stack(t_stack *stack, size_t j);

// Array filling functions
void			fill_array(t_stack *a, char **argv, int argc);
void			fill_array_bis(char **split_args, t_stack *a, size_t *k);
void			fill_array_index(t_stack *a);

// Simple algo
void			simple_algo(t_stack *a, t_stack *b);

// Medium algo
void			find_max_div(t_stack *a, t_stack *b);

// Operations
void			pa(t_stack *a, t_stack *b);
void			pb(t_stack *a, t_stack *b);
void			ra(t_stack *a);
void			rb(t_stack *b);
void			rr(t_stack *a, t_stack *b);
void			rra(t_stack *a);
void			rrb(t_stack *b);
void			rrr(t_stack *a, t_stack *b);
void			sa(t_stack *a);
void			sb(t_stack *b);
void			ss(t_stack *a, t_stack *b);
void			get_ptr_value(int *dst, int *src);

// Chunks sort utils
size_t			ft_sqrt(size_t nb);
size_t			calculate_num_chunks(size_t size);
void			find_min_max(t_stack *stack, int *min, int *max);
int				calculate_chunk_size(int min, int max, size_t num_chunks);
int				is_in_chunk(int value, int min, int chunk_num, int chunk_size);

// Chunks finds
int				find_chunk_number(t_stack *a, int min, int chunk_num,
					int chunk_size);
size_t			find_max_index(t_stack *stack);

// Chunks rotate
void			rotate_to_top_a(t_stack *a, size_t index);
void			rotate_to_top_b(t_stack *b, size_t index);

// Medium Chunks Algo
void			medium_algo(t_stack *a, t_stack *b);

#endif