#include "push_swap.h"

int	check_double(t_stack *a)
{
	t_elem	*tmp1;
	t_elem	*tmp2;
	int		num;

	tmp1 = a->first;
	while (tmp1)
	{
		num = tmp1->value;
		tmp2 = tmp1;
		while (tmp2->next)
		{
			if (num == tmp2->next->value)
				return (0);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return(1);
}

int	count_nbr(t_stack *a)
{
	t_elem	*tmp;
	int		i;

	i = 0;
	tmp = a->first;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	ft_isblank(int c)
{
	return (c == ' ' || c == '\t');
}

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}

long long	ft_atoill(const char *str)
{
	int					i;
	unsigned long long	nb;
	int					p;

	i = 0;
	p = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
	|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		p = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	nb = nb * p;
	return (nb);
}
