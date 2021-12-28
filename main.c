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
	if (a->size > 0)
	{
		new->prev = a->last;
		new->next = a->first;
		a->first->prev = new;
		a->last->next = new;
	}
	else
	{
			new->next = new;
			new->prev = new;
			a->first = new;
	}
	a->last = new;
	a->size += 1;
}

void	add_to_top(t_stack *a, long val)
{
	t_elem	*new;

	new = malloc(sizeof(t_elem));
	if (!new)
		ft_error();
	new->value = val;
	if (a->size > 0)
	{
		new->next = a->first;
		new->prev = a->last;
		a->first->prev = new;
		a->last->next = new;
	}
	else
	{
		new->next = new;
		new->prev = new;
		a->last = new;
	}
	a->first = new;
	a->size += 1;
}

long	remove_from_top(t_stack *a)
{
	long val;
	t_elem	*tmp;

	tmp = a->first;
	if (a->size == 0)
		return (-1);
	val = tmp->value;
	if (a->size > 1)
	{
		a->first = tmp->next;
		a->last->next = a->first;
		a->first->prev = a->last;
	}
	else
	{
		a->first = NULL;
		a->last = NULL;
	}
	a->size -= 1;
	free(tmp);
	return	(val);
}
/*
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
*/
void init_stack(t_stack *a, t_stack *b)
{
	//Init
	a->first = NULL;
	a->last = NULL;
	a->size = 0;
	b->first = NULL;
	b->last = NULL;
	b->size = 0;
}

void	print_stack(t_stack *a)
{
	t_elem *actuel;
	int size;

	size = 0;
	actuel = a->first;
	while (size < a->size)
	{
		printf("%2ld ", actuel->value);
		/*printf("first = %ld\n", a.first->value);
		printf("last = %ld\n", a.last->value);*/
		actuel = actuel->next;
		size ++;
	}
	printf(" >> \n");
}

void	print_stacks(t_stack *a, t_stack *b)
{
	printf("stack A : (%d)<<", a->size);
	print_stack(a);
	printf("stack B :(%d)<<", b->size);
	print_stack(b);
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
 	if ((str[i] == '+' || str[i] == '-')
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
	if (i - 1 != a->size)
		printf("probleme de taille %d %d\n", i-1, a->size);
}

void	build_b(t_stack * b)
{
		add_to_end(b , 2);
		add_to_end(b , 3);
		add_to_end(b , 4);
}

/*
 * non securise part du principe que 
 *		les tailles correspondent
 */
int fill_tab(t_stack *s, int *tab)
{
	int i;
	t_elem *elem;

	i = 0;

	elem = s->first;
	while(i < s->size)
	{
		tab[i] = elem->value;
		i++;
		elem =  elem->next;
	}
	return (i);
}

void super_trie(t_stack *a, t_stack *b, int *tab, int nb_elem);
int	main(int ac, char **av)
{
	t_stack	a;
	t_stack b;
	int *tab;

	if (ac < 2)
		return(0);

	init_stack(&a, &b);
	build_stack(&a, ac, av);
	print_stack(&a);

	//build_b(&b);
	//print_stack(&b);
	//ft_rra(&a);
	//print_stack(&a);
	//print_stack(&b);

	tab = malloc(sizeof(int) * (a.size + 1));
	fill_tab(&a, tab);
	super_trie(&a, &b, tab, a.size);
	/*
	if (!sorted(&a))
		printf("a is not sorted\n");
	else
		printf("a is sorted\n");
		*/
	//free
	return(0);
}
