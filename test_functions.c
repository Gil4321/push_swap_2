#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
	int			*array;
	size_t		size;
	size_t		capacity;
}				t_stack;

void	ra(t_stack *a)
{
	int		temp;
	size_t	i;

	if (a->size < 2)
		return ;
	temp = a->array[0];
	i = 0;
	while (i < a->size - 1)
	{
		a->array[i] = a->array[i + 1];
		i++;
	}
	a->array[a->size - 1] = temp;
	printf("ra\n");
}

void	rra(t_stack *a)
{
	int		temp;
	size_t	i;

	if (a->size < 2)
		return ;
	temp = a->array[a->size - 1];
	i = a->size - 1;
	while (i > 0)
	{
		a->array[i] = a->array[i - 1];
		i--;
	}
	a->array[0] = temp;
	printf("rra\n");
}

void	rb(t_stack *b)
{
	int		temp;
	size_t	i;

	if (b->size < 2)
		return ;
	temp = b->array[0];
	i = 0;
	while (i < b->size - 1)
	{
		b->array[i] = b->array[i + 1];
		i++;
	}
	b->array[b->size - 1] = temp;
	printf("rb\n");
}

void	rrb(t_stack *b)
{
	int		temp;
	size_t	i;

	if (b->size < 2)
		return ;
	temp = b->array[b->size - 1];
	i = b->size - 1;
	while (i > 0)
	{
		b->array[i] = b->array[i - 1];
		i--;
	}
	b->array[0] = temp;
	printf("rrb\n");
}

void	pb(t_stack *a, t_stack *b)
{
	size_t	i;

	if (a->size == 0)
		return ;
	b->array[b->size] = a->array[0];
	b->size++;
	i = 0;
	while (i < a->size - 1)
	{
		a->array[i] = a->array[i + 1];
		i++;
	}
	a->size--;
	printf("pb\n");
}

void	pa(t_stack *a, t_stack *b)
{
	size_t	i;

	if (b->size == 0)
		return ;
	i = a->size;
	while (i > 0)
	{
		a->array[i] = a->array[i - 1];
		i--;
	}
	a->array[0] = b->array[0];
	a->size++;
	i = 0;
	while (i < b->size - 1)
	{
		b->array[i] = b->array[i + 1];
		i++;
	}
	b->size--;
	printf("pa\n");
}

int	is_in_chunk(int value, int min, int chunk_num, int chunk_size)
{
	int	chunk_min;
	int	chunk_max;
	int	is_in_range;

	chunk_min = min + (chunk_num * chunk_size);
	chunk_max = chunk_min + chunk_size - 1;
	is_in_range = (value >= chunk_min && value <= chunk_max);
	return (is_in_range);
}

size_t	ft_sqrt(int nb)
{
	size_t	i;

	i = 1;
	while (i * i <= (size_t)nb)
	{
		if (i * i == (size_t)nb)
			return (i);
		i++;
	}
	return (i - 1); // Fixed: return floor of sqrt
}

size_t	calculate_num_chunks(size_t size)
{
	size_t	num_chunks;

	num_chunks = ft_sqrt(size);
	if (num_chunks < 2)
		num_chunks = 2;
	return (num_chunks);
}

void	find_min_max(t_stack *stack, int *min, int *max)
{
	size_t	i;

	*min = stack->array[0];
	*max = stack->array[0];
	i = 1;
	while (i < stack->size)
	{
		if (stack->array[i] < *min)
			*min = stack->array[i];
		if (stack->array[i] > *max)
			*max = stack->array[i];
		i++;
	}
}

int	calculate_chunk_size(int min, int max, size_t num_chunks)
{
	return ((max - min) / num_chunks + 1);
}

size_t	find_max_index(t_stack *stack)
{
	size_t	i;
	size_t	max_index;
	int		max_value;

	if (stack->size == 0)
		return (0);
	max_index = 0;
	max_value = stack->array[0];
	i = 1;
	while (i < stack->size)
	{
		if (stack->array[i] > max_value)
		{
			max_value = stack->array[i];
			max_index = i;
		}
		i++;
	}
	return (max_index);
}

int	find_chunk_number(t_stack *a, int min, int chunk_num, int chunk_size)
{
	size_t	i;

	i = 0;
	while (i < a->size)
	{
		if (is_in_chunk(a->array[i], min, chunk_num, chunk_size))
			return ((int)i);
		i++;
	}
	return (-1);
}


void	rotate_to_top_a(t_stack *a, int index)
{
	size_t	mid;

	mid = a->size / 2;
	if (index <= (int)mid)
	{
		while (index > 0)
		{
			ra(a);
			index--;
		}
	}
	else
	{
		while (index < (int)a->size)
		{
			rra(a);
			index++;
		}
	}
}

void	rotate_to_top_b(t_stack *b, size_t index)
{
	size_t	mid;

	mid = b->size / 2;
	if (index <= mid)
	{
		while (index > 0)
		{
			rb(b);
			index--;
		}
	}
	else
	{
		while (index < b->size)
		{
			rrb(b);
			index++;
		}
	}
}

static size_t	count_chunk_elements(t_stack *a, int min, int chunk_num,
		int chunk_size)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (i < a->size)
	{
		if (is_in_chunk(a->array[i], min, chunk_num, chunk_size))
			count++;
		i++;
	}
	return (count);
}

static void	push_chunk_to_b(t_stack *a, t_stack *b, int min, int chunk_num,
		int chunk_size)
{
	size_t	total;
	size_t	pushed;
	int		index;

	total = count_chunk_elements(a, min, chunk_num, chunk_size); // ✅ Fixed
	pushed = 0;
	while (pushed < total)
	{
		index = find_chunk_number(a, min, chunk_num, chunk_size);
		if (index >= 0)
		{
			rotate_to_top_a(a, index); // ✅ Fixed
			pb(a, b);
			pushed++;
		}
	}
}

static void	push_back_sorted(t_stack *a, t_stack *b)
{
	size_t	max_index;

	while (b->size > 0)
	{
		max_index = find_max_index(b);
		rotate_to_top_b(b, max_index);
		pa(a, b);
	}
}

void	medium_algo(t_stack *a, t_stack *b)
{
	size_t	num_chunks;
	int		min;
	int		max;
	int		chunk_size;
	size_t	chunk;

	num_chunks = calculate_num_chunks(a->size);
	find_min_max(a, &min, &max);
	chunk_size = calculate_chunk_size(min, max, num_chunks);
	chunk = 0;
	while (chunk < num_chunks)
	{
		push_chunk_to_b(a, b, min, chunk, chunk_size);
		chunk++;
	}
	push_back_sorted(a, b);
}

	void print_stack(t_stack *stack, char *name)
{
	size_t	i;

	printf("%s: [", name);
	i = 0;
	while (i < stack->size)
	{
		printf("%d", stack->array[i]);
		if (i < stack->size - 1)
			printf(", ");
		i++;
	}
	printf("]\n");
}

int	is_sorted(t_stack *stack)
{
	size_t	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->array[i] > stack->array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	main(void)
{
	int		tab[] = {10, 7, 72, 40, 52, 69, 42};
	t_stack	a;
	t_stack	b;
	size_t	num_chunks;
	int		chunk_size;

	a.array = tab;
	a.size = 7;
	a.capacity = 7;

	b.array = malloc(sizeof(int) * 7);
	b.size = 0;
	b.capacity = 7;

	int min, max;

	medium_algo(&a, &b);

	print_stack(&a, "Stack A");

	free(b.array);
	return (0);
}
