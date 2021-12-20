#include "push_swap.h"

int	sorted(t_stack *a)
{
	t_elem	*tmp;

	tmp = a->first;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	add_to_end(t_stack *a, long val)
{
	t_elem *new;

	new = malloc(sizeof(t_elem));
	if (!new)
		ft_error();
	new->value = val;
	new->prev = a->last;
	new->next = NULL;
	if (a->last)
		a->last->next = new;
	else
		a->first = new;
	a->last = new;
}

void	add_to_top(t_stack *a, long val)
{
	t_elem	*new;

	new = malloc(sizeof(t_elem));
	if (!new)
		ft_error();
	new->value = val;
	new->next = a->first;
	new->prev = NULL;
	if (a->first)
		a->first->prev = new;
	else
		a->last = new;
	a->first = new;
}

long	remove_from_top(t_stack *a)
{
	long val;
	t_elem	*tmp;

	tmp = a->first;
	if (!tmp)
		return (-1);
	val = tmp->value;
	a->first = tmp->next;
	if (a->first)
		a->first->prev = NULL;
	else
		a->last = NULL;
	free(tmp);
	return	(val);
}

long	remove_from_end(t_stack *a)
{
	long	val;
	t_elem	*tmp;

	tmp = a->last;
	if (!tmp)
		return (-1);
	val = tmp->value;
	if (a->last)
		a->last->next = NULL;
	else
		a->first = NULL;
	free(tmp);
	return (val);
}

void init_stack(t_stack *a, t_stack *b)
{
	//Init
	a->first = NULL;
	a->last = NULL;
	b->first = NULL;
	b->last = NULL;
}

void	print_stack(t_stack a)
{
	t_elem *actuel;
	
	actuel = a.first;
	while (actuel)
	{
		printf("%ld\n", actuel->value);
		/*printf("first = %ld\n", a.first->value);
		printf("last = %ld\n", a.last->value);*/
		actuel = actuel->next;
	}
}

long	parse(char *str)
{
	int	i;
	long long 	num;

	i = 0;

	//printf("str = %s\n", str);
	if (!str)
		return 0;

	if (!ft_isblank(str[i]) && !ft_isdigit(str[i]) 
		&& str[i] != '+' && str[i] != '-' && str[i] != '\0')
		ft_error();
 	if (ft_isdigit(str[i]) && !ft_isdigit(str[i + 1]) 
	&& !ft_isblank(str[i + 1]) && str[i + 1] != '\0')
		ft_error();
 	if (str[i] == '+' || str[i] == '-'
		&& !ft_isdigit(str[i + 1]) && str[i + 1] != '\0')
		ft_error();

	num = ft_atoill(&str[i]);
	//printf("num atoilld = %lld\n", num);
	if (num > INT_MAX || num < INT_MIN)
		ft_error();
	return (num);
}
 
void	build_stack(t_stack *a, int ac, char **av)
{
	int	i;
	long	num;

	i = 1;
	while (i < ac)
	{
		num = parse(av[i]);
		add_to_end(a, num);
		i++;
	}
	if (!(check_double(a)))
		ft_error();
}

void	divid_list(t_stack *a, t_stack *b, int size)
{
	int medium = size / 2;
	while (size > medium)
	{
		ft_pb(a, b);
		size--;
	}

}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack b;
	int	 count;

	if (ac < 2)
		return(0);

	init_stack(&a, &b);
	build_stack(&a, ac, av);
	print_stack(a);

	count = count_nbr(&a);
	printf("count stack = %d\n", count);
	
	divid_list(&a, &b, count);

	printf("stack a\n");
	print_stack(a);
	printf("stack b\n");
	print_stack(b);



	if (!sorted(&a))
		printf("a is not sorted\n");
	else
		printf("a is sorted\n");
	//ft_rra(&a);

	return(0);
}
