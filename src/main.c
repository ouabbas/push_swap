/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soabbas <soabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:25:11 by soabbas           #+#    #+#             */
/*   Updated: 2022/11/22 19:51:40 by soabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	int i;
	t_list *tmp;
	t_list *tmp_2;
	t_list *lst_a;

	lst_a = NULL;
	if (ac <= 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	i = 0;
	while (++i < ac)
	{
		if (!comp_av(av) || (!ft_isdigit(av[i])) || (ft_atoi(av[i]) == INT_MIN))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		tmp = ft_lstnew(ft_atoi(av[i]));
		ft_lstadd_back(&lst_a, tmp);
	}

	printf("\n***** LISTE ******\n");
	print_list(lst_a);
	tmp_2 = lst_a;
	// OK

	printf("soundous\n");
	if (!isSorted(lst_a))
		lst_a = sorter(ac, tmp_2);
	else
	{
		printf("\nc trie\n");
		return (0);
	}
	printf("\n***** RESULT ******\n");
	print_list(lst_a);
	return 0;
}

int isSorted(t_list *lst_a)
{
	t_list *tmp2;

	tmp2 = lst_a;
	while (tmp2->next)
	{
		if (tmp2->content > tmp2->next->content)
		{
			printf("\nis NOT sorted\n");

			return (0);
		}
		tmp2 = tmp2->next;
	printf("\nis sorted\n");
	}

	return (1);
}

t_list *sorter(int ac, t_list *lst_a)
{
	t_list *tmp;
	t_list *lst_b;

	tmp = lst_a;
	lst_b = NULL;
	if (ac == 3)
		swap(&tmp, 'a');
	else if (ac == 4)
		algo_3(&tmp, 'a');
	else if (ac == 6)
		algo_5(&tmp, &lst_b, 'a');
	else if (ac == 5 || (ac >= 7 && ac <= 100))
		algo_100(&tmp, &lst_b);
	return (tmp);
}