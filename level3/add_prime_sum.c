/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gojeda <gojeda@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:22:01 by gojeda            #+#    #+#             */
/*   Updated: 2025/05/28 12:22:03 by gojeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>
*/

#include <unistd.h>

void	ft_putnbr(int nbr)
{
	long	num;
	char	c;

	num = nbr;
	if (num < 0)
	{
		write(1, "-", 1);
		num = num * -1;
	}
	if (num > 9)
		ft_putnbr(num / 10);
	c = (num % 10) + '0';
	write(1, &c, 1);
}

int	ft_atoi_again(char *str)
{
	int	result;
	int	i;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i])
		return (0);
	return (result * sign);
}

int	is_prime(int num)
{
	int	i;

	if (num <= 1)
		return (0);
	i = 2;
	while (i * i <= num)
	{
		if ((num % i) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_add_prime_sum(int num)
{
	int	i;
	int	sum;

	i = 2;
	sum = 0;
	while (i <= num)
	{
		if (is_prime(i))
			sum += i;
		i++;
	}
	return (sum);
}

int	main(int argc, char **argv)
{
	int	num;
	int	result;

	if (argc == 2)
	{
		num = ft_atoi_again(argv[1]);
		if (num >= 0)
		{
			result = ft_add_prime_sum(num);
			ft_putnbr(result);
		}
		else
			write(1, "0", 1);
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}
