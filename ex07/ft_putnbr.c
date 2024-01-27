/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 09:07:40 by tkondo            #+#    #+#             */
/*   Updated: 2024/01/27 15:02:39 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putabs(int num)
{
	char	digit;
	int		sign;

	if (num / 10)
		ft_putabs(num / 10);
	sign = (num >= 0) * 1 + (num < 0) * (-1);
	digit = '0' + (num % 10) * sign;
	write(1, &digit, 1);
}
void	ft_putnbr(int num)
{
	if (num < 0)
		write(1, "-", 1);
	ft_putabs(num);
}
/* RM this line to test
#include <limits.h>

int	main(void)
{
	ft_putnbr(INT_MAX);
	ft_putnbr(INT_MIN);
	ft_putnbr(0);
	return (0);
} //*/
