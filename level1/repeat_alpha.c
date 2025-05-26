/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gojeda <gojeda@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:33:46 by gojeda            #+#    #+#             */
/*   Updated: 2025/05/26 14:33:48 by gojeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	find_index(char letter)
{
	if (letter >= 'A' && letter <= 'Z')
		return (letter - 'A' + 1);
	else if (letter >= 'a' && letter <= 'z')
		return (letter - 'a' + 1);
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	repeat;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
		{
			repeat = find_index(argv[1][i]);
			while (repeat--)
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
