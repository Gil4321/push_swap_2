/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombier <acombier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:19:23 by acombier          #+#    #+#             */
/*   Updated: 2026/01/15 17:23:14 by acombier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BENCHMARK_H
# define BENCHMARK_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int		*array;
	size_t	size;
}			t_stack;

#endif