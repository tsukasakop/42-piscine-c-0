/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:27:16 by tkondo            #+#    #+#             */
/*   Updated: 2024/01/27 14:50:52 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_combination(int *comb, int n)
{
	int	i;
	int	print_flag;

	i = -1;
	print_flag = 1;
	while (++i < n - 1)
	{
		if (comb[i] >= comb[i + 1])
		{
			print_flag = 0;
			break ;
		}
	}
	if (print_flag)
	{
		i = -1;
		while (++i < n)
			ft_putchar(comb[i] + '0');
		if (comb[0] < (10 - n))
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
}

bool	increment_combination(int *comb, int n, int idx)
{
	if (idx == -1)
		return (false);
	if (comb[idx] < 9 - (n - idx - 1))
		comb[idx]++;
	else
	{
		if (!increment_combination(comb, n, idx - 1))
			return (false);
		comb[idx] = comb[idx - 1] + 1;
	}
	return (true);
}

void	ft_print_combn(int n)
{
	int	comb[10];
	int	i;

	if (n <= 0 || n >= 10)
		return ;
	i = 0;
	while (i < n)
	{
		comb[i] = i;
		i++;
	}
	print_combination(comb, n);
	while (increment_combination(comb, n, n - 1))
		print_combination(comb, n);
}

/* RM this line to test
#include <stdio.h>

int	main(void)
{
	ft_print_combn(2);
	putchar('\n');
	putchar('\n');
	ft_print_combn(3);
	putchar('\n');
	putchar('\n');
	ft_print_combn(4);
	putchar('\n');
	putchar('\n');
	ft_print_combn(5);
	putchar('\n');
	putchar('\n');
	ft_print_combn(6);
	putchar('\n');
	putchar('\n');
	ft_print_combn(7);
	putchar('\n');
	putchar('\n');
	ft_print_combn(8);
	putchar('\n');
	putchar('\n');
	ft_print_combn(9);
	return (0);
}
//*/
