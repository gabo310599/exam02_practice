/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gojeda <gojeda@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:03:05 by gojeda            #+#    #+#             */
/*   Updated: 2025/05/26 13:03:14 by gojeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	size_t	i;

	if (argc != 2)
		write(1, "\n", 1);
	else
	{
		i = 0;
		while (argv[1][i] == ' ' || (argv[1][i] >= 9 && argv[1][i] <= 13))
			i++;
		if (!argv[1][i])
			write(1, "\n", 1);
		else
		{
			while (argv[1][i] && !(argv[1][i] == ' '
					|| (argv[1][i] >= 9 && argv[1][i] <= 13)))
			{
				write(1, &argv[1][i], 1);
				i++;
			}
		}
	}
	return (0);
}
