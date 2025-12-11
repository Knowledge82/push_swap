#include "push_swap.h"

/* Возвращает позицию элемента с заданным индексом в стеке
	0 = наверху, 1 = второй и т.д.
*/
int	get_position(t_node *stack, int index)
{
	int		pos;
	t_node	*current;

	pos = 0;
	current = stack;
	while (current)
	{
		if (current->index == index)
			return (pos);
		current = current->next;
		pos++;
	}
	return (-1);
}

// Найти минимальный индекс в стеке
int	get_min_index(t_node *stack)
{
	int		min;
	t_node	*current;

	if (!stack)
		return (-1);
	min = stack->index;
	current = stack->next;
	while (current)
	{
		if (current->index < min)
			min = current->index;
		current = current->next;
	}
	return (min);
}

// Найти максимальный индекс в стеке
int	get_max_index(t_node *stack)
{
	int		max;
	t_node	*current;

	if (!stack)
		return (-1);
	max = stack->index;
	current = stack->next;
	while (current)
	{
		if (current->index > max)
			max = current->index;
		current = current->next;
	}
	return (max);
}

int	find_target_in_b(t_node *b, int index_a)
{
	int		target;
	t_node	*current;
	int		found;//////

	if (!b)
		return (-1);
	target = INT_MIN;
	found = 0;
	current = b;
	while (current)
	{
		if (current->index < index_a)
		{
			if (!found || current->index > target)
			{
				target = current->index;
				found = 1;
			}
		}
		current = current->next;
	}
	if (!found)
		target = get_max_index(b);
	return (target);
}

/* Находит target в стеке A для элемента из B
 * Target = минимальный элемент в А, который больше текущего
 * если таких нет, то target = минимальный элемент в A
 */
int	find_target_in_a(t_node *a, int index_b)
{
	int		target;
	t_node	*current;
	int		found;//////

	if (!a)
		return (-1);
	target = INT_MAX;
	found = 0;
	current = a;
	while (current)
	{
		// тут ищем наименьший элемент, который боьше index_a
		if (current->index > index_b)
		{
			if (!found || current->index < target)
			{
				target = current->index;
				found = 1;
			}
		}
		current = current->next;
	}
	if (!found)
		target = get_min_index(a);
	return (target);
}

// Считает, сколько операций нужно, чтобы поднять элемент наверх
// Возвращает МИНИМУМ между ra и rra
int	get_rotation_cost(t_node *stack, int index)
{
	int	pos;
	int	size;
	int	cost_ra;
	int	cost_rra;

	pos = get_position(stack, index);
	size = stack_size(stack);

	if (pos == -1)
		return (0);

	cost_ra = pos;
	cost_rra = size - pos;

	// возвращаем минимальный
	if (cost_ra < cost_rra)
		return (cost_ra);
	return (cost_rra);
}

int	calculate_total_cost(t_node *a, t_node *b, int index_a)
{
	int	target_b;
	int	pos_a;
	int	pos_b;
	int	size_a;
	int	size_b;
	int	cost_variant[4];
	int	min_cost;
	int	i;

	target_b = find_target_in_b(b, index_a);
	pos_a = get_position(a, index_a);
	pos_b = get_position(b, target_b);
	size_a = stack_size(a);
	size_b = stack_size(b);

	// Вариант 1: оба ra + rb (rr)
	if (pos_a >= pos_b)
		cost_variant[0] = pos_a;// делаем pos_b раз rr, потом (pos_a - pos_b) раз ra.
	else
		cost_variant[0] = pos_b;// делаем pos_a раз rr, потом (pos_b - pos_a) раз rb.

	// Вариант 2: оба rra + rrb (rrr)
	if ((size_a - pos_a) >= (size_b - pos_b))
		cost_variant[1] = size_a - pos_a;
	else
		cost_variant[1] = size_b - pos_b;

	// Вариант 3: ra + rrb
	cost_variant[2] = pos_a + (size_b - pos_b);

	// Вариант 4: rra + rb
	cost_variant[3] = (size_a - pos_a) + pos_b;

	// Находим минимальный
	min_cost = cost_variant[0];
	i = 1;
	while (i < 4)
	{
		if (cost_variant[i] < min_cost)
			min_cost = cost_variant[i];
		i++;
	}
	return (min_cost);
}

// Находит индекс элемента в стеке А, который дешевле всего запушить в B
int	find_cheapest_in_a(t_node *a, t_node *b)
{
	t_node	*current;
	int		cost;
	int		min_cost;
	int		cheapest_index;

	current = a;
	min_cost = INT_MAX;
	cheapest_index = current->index;
	while (current)
	{
		cost = calculate_total_cost(a, b, current->index);
		if (cost < min_cost)
		{
			min_cost = cost;
			cheapest_index = current->index;
		}
		current = current->next;
	}
	return (cheapest_index);
}

// Аналогично для B -> A
int	find_cheapest_in_b(t_node *a, t_node *b)
{
	t_node	*current;
	int		cost;
	int		min_cost;
	int		cheapest_index;
	int		target_a;

	current = b;
	min_cost = INT_MAX;
	cheapest_index = current->index;
	while (current)
	{
		target_a = find_target_in_a(a, current->index);
		cost = get_rotation_cost(b, current->index) + get_rotation_cost(a, target_a); 
		if (cost < min_cost)
		{
			min_cost = cost;
			cheapest_index = current->index;
		}
		current = current->next;
	}
	return (cheapest_index);
}

// Поднимает элемент с заданным индексом наверх стека A
// Выбирает короткий путь (ra / rra)
void	bring_to_top_a(t_node **a, int index)
{
	int	pos;
	int	size;

	pos = get_position(*a, index);
	size = stack_size(*a);
	if (pos <= size / 2)// короче через ra
	{
		while ((*a)->index != index)
			ra(a);
	}
	else// короче через rra
	{
		while ((*a)->index != index)
			rra(a);
	}
}

// Аналогично для B
void	bring_to_top_b(t_node **b, int index)
{
	int	pos;
	int	size;

	pos = get_position(*b, index);
	size = stack_size(*b);
	if (pos <= size / 2)// короче через ra
	{
		while ((*b)->index != index)
			rb(b);
	}
	else// короче через rra
	{
		while ((*b)->index != index)
			rrb(b);
	}
}

// Синхронное движение обоих стеков
// Поднимает оба элемента наверх, используя rr/rrr где возможно
void	bring_both_to_top(t_node **a, t_node **b, int index_a, int index_b)
{
	int	pos_a;
	int	pos_b;
	int	size_a;
	int	size_b;

	pos_a = get_position(*a, index_a);
	pos_b = get_position(*b, index_b);
	size_a = stack_size(*a);
	size_b = stack_size(*b);

	// если оба надо крутить вперёд (ra + rb), то используем rr
	while (pos_a > 0 && pos_b > 0 && pos_a <= size_a / 2 && pos_b <= size_b / 2)
	{
		rr(a, b);
		pos_a--;
		pos_b--;
	}

	// если оба назад (rra + rrb), итспользуем rrr
	while (pos_a > 0 && pos_b > 0 && pos_a > size_a / 2 && pos_b > size_b / 2)
	{
		rrr(a, b);
		pos_a++;
		pos_b++;
		if (pos_a >= size_a)
			pos_a = 0;
		if (pos_b >= size_b)
			pos_b = 0;
	}

	// докручиваем остатки
	bring_to_top_a(a, index_a);
	bring_to_top_b(b, index_b);
}

void	turk_sort(t_node **a, t_node **b)
{
	int	cheapest_index;
	int	target_index;

	//ФАЗА 1: пушим в B всё, кроме 3 элементов
	// Пушим первые 2 без раздумий
	if (stack_size(*a) > 3)
		pb(a, b);
	if (stack_size(*a) > 3)
		pb(a, b);
	// остальные пушим по стоимости
	while (stack_size(*a) > 3)
	{
		cheapest_index = find_cheapest_in_a(*a, *b);
		target_index = find_target_in_b(*b, cheapest_index);

		// поднимаем оба элемента наверх
		bring_both_to_top(a, b, cheapest_index, target_index);

		// пушим
		pb(a, b);
	}

	// ФАЗА 2: сортируем 3 элемента в А
	sort_three(a);

	// ФАЗА 3: возвращаем из B в A

	while (*b)
	{
		cheapest_index = find_cheapest_in_b(*a, *b);
		target_index = find_target_in_a(*a, cheapest_index);


		// поднимаем оба наверх
		bring_both_to_top(a, b, target_index, cheapest_index);

		// пушим обратно
		pa(b, a);
	}

	// ФАЗА 4: финальная ротация (минимум наверх)

	cheapest_index = get_min_index(*a);

	bring_to_top_a(a, cheapest_index);
}
