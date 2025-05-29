/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gojeda <gojeda@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:20:10 by gojeda            #+#    #+#             */
/*   Updated: 2025/05/28 11:20:11 by gojeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
*/

#include <unistd.h>

void	ft_put_save_char(char *ascii, char c)
{
	write(1, &c, 1);
	ascii[c - '0'] = c;
}

void	ft_union(char *s1, char *s2)
{
	char	ascii[128];
	int		i;

	i = 0;
	while (i < 128)
		ascii[i++] = 0;
	i = 0;
	while (s1[i])
	{
		if (!ascii[s1[i] - '0'])
			ft_put_save_char(ascii, s1[i]);
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if (!ascii[s2[i] - '0'])
			ft_put_save_char(ascii, s2[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
