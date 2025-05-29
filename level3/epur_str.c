/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gojeda <gojeda@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:03:11 by gojeda            #+#    #+#             */
/*   Updated: 2025/05/28 14:03:13 by gojeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : epur_str
Expected files   : epur_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays this string with exactly one
space between words, with no spaces or tabs either at the beginning or the end,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

If the number of arguments is not 1, or if there are no words to display, the
program displays \n.

Example:

$> ./epur_str "vous voyez c'est facile d'afficher la meme chose" | cat -e
vous voyez c'est facile d'afficher la meme chose$
$> ./epur_str " seulement          la c'est      plus dur " | cat -e
seulement la c'est plus dur$
$> ./epur_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
$
$> ./epur_str "" | cat -e
$
$>
*/

#include <unistd.h>

int	is_over(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == ' ' || str[i] == 9))
			return (0);
		i++;
	}
	return (1);
}

void	ft_epur_str(char *str)
{
	int	i;
	int	flag;

	i = 0;
	while (str[i] == ' ' || str[i] == 9)
		i++;
	flag = 1;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == 9)
		{
			if (!is_over(&str[i]) && flag)
			{
				flag = 0;
				write(1, " ", 1);
			}
		}
		else
		{
			flag = 1;
			write(1, &str[i], 1);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_epur_str(argv[1]);
	write(1, "\n", 1);
	return (0);
}
