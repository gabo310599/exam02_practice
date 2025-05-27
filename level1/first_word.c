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

/*
Assignment name  : first_word
Expected files   : first_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its first word, followed by a
newline.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:

$> ./first_word "FOR PONY" | cat -e
FOR$
$> ./first_word "this        ...    is sparta, then again, maybe    not" | cat -e
this$
$> ./first_word "   " | cat -e
$
$> ./first_word "a" "b" | cat -e
$
$> ./first_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
*/

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
