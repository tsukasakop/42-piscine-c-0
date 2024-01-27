/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:15:33 by tkondo            #+#    #+#             */
/*   Updated: 2024/01/27 11:17:38 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_number(int n)
{
	if (n > 9)
	{
		ft_putchar(n / 10 + '0');
		ft_putchar(n % 10 + '0');
	}
	else
	{
		ft_putchar('0');
		ft_putchar(n + '0');
	}
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < 99)
	{
		j = i + 1;
		while (j < 100)
		{
			ft_print_number(i);
			ft_putchar(' ');
			ft_print_number(j);
			if (i == 98 && j == 99)
				return ;
			ft_putchar(',');
			ft_putchar(' ');
			++j;
		}
		++i;
	}
}

/* RM this line to test

int	main(void)
{
	ft_print_comb2();
	return (0);
}
//*/
