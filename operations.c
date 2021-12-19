#include "push_swap.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

//sa : swap a - swap the first 2 elements at the top of stack a
void	ft_sa(t_stack *a)
{
	t_elem	*tmp;

	if (a->first && a->first->next)
	{
		tmp = a->first->next;
		a->first->next = a->first->next->next;
		tmp->next = a->first;
		a->first = tmp;
	}
	ft_putstr("sa\n");
}

//sb : swap b - swap the first 2 elements at the top of stack b.
void	ft_sb(t_stack *b)
{
	t_elem	*tmp;

	if (b->first && b->first->next)
	{
		tmp = b->first->next;
		b->first->next = b->first->next->next;
		tmp->next = b->first;
		b->first = tmp;
	}
	ft_putstr("sb\n");
}

//ss : sa and sb at the same time
void	ft_ss(t_stack *s)
{
	ft_sa(s);
	ft_sb(s);
	ft_putstr("ss\n");
}

//pa : push a - take the first element at the top of b  and put it at the top of a
void	ft_pa(t_stack *a, t_stack *b)
{
	long	value;

	if (b != NULL)
	{
		value = remove_from_top(b);
		add_to_top(a, value);
	}
	ft_putstr("pa\n");
}

//pb : push b - take the first element at the top of a and put it at the top of b.
void	ft_pb(t_stack *a, t_stack *b)
{
	long	value;

	if (a != NULL)
	{
		value = remove_from_top(a);
		add_to_top(b, value);
	}
	ft_putstr("pb\n");
}

//ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
void		ft_ra(t_stack *a)
{
	t_elem	*tmp;
	t_elem *head;

	if (a->first && a->first->next)
	{
		tmp = a->first;
		a->first = a->first->next;
		head = a->first;
		tmp->next = NULL;
		while (a->first->next)
		{
			a->first = a->first->next;
		}
		a->first->next = tmp;
		a->first = head;
	}
	ft_putstr("ra\n");
}

//rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
//
void		ft_rb(t_stack *b)
{
	t_elem	*tmp;
	t_elem *head;

	if (b->first && b->first->next)
	{
		tmp = b->first;
		b->first = b->first->next;
		head = b->first;
		tmp->next = NULL;
		while (b->first->next)
		{
			b->first = b->first->next;
		}
		b->first->next = tmp;
		b->first = head;
	}
	ft_putstr("rb\n");
}

//rr : ra and rb at the same time.

void	ft_rr(t_stack *a, t_stack *b)
{
	ft_ra(a);
	ft_rb(b);
	ft_putstr("rr\n");
}

//rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
void		ft_rra(t_stack *a)
{
	t_elem	*head;
	t_elem	*tmp;

	if (a->first && a->first->next)
	{
		head = a->first;
		while (a->first->next->next)
		{
			a->first = a->first->next;
		}
		tmp = a->first->next;
		a->first->next = NULL;
		a->first = head;
		tmp->next = a->first;
		a->first = tmp;
	}
	ft_putstr("rra\n");
}

//rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.


//rrr : rra and rrb at the same time.
void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_rra(a);
	//ft_rrb(b);
	ft_putstr("rrr\n");
}

//Reverse
void	reverse(t_stack *a)
{
	t_elem	*prev = NULL;
	t_elem *next = NULL;
	t_elem	*current;

	current = a->first;
	while (current != NULL)
	{
		next  = current->next;

		current->next = prev;
		
		prev = current;
		current = next;
	}
	a->first = prev;
	ft_putstr("Reverse\n");
}

