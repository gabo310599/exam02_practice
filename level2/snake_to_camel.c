/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gojeda <gojeda@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:52:28 by gojeda            #+#    #+#             */
/*   Updated: 2025/05/28 11:52:30 by gojeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : snake_to_camel
Expected files   : snake_to_camel.c
Allowed functions: malloc, free, realloc, write
--------------------------------------------------------------------------------

Write a program that takes a single string in snake_case format
and converts it into a string in lowerCamelCase format.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.

Examples:
$>./snake_to_camel "here_is_a_snake_case_word"
hereIsASnakeCaseWord
$>./snake_to_camel "hello_world" | cat -e
helloWorld$
$>./snake_to_camel | cat -e
$
*/

#include <unistd.h>
#include <stdlib.h>

int	calculate_malloc_size(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '_')
			count++;
		i++;
	}
	return (i - count);
}

char	*ft_snake_to_camel(char *str)
{
	int		i;
	int		j;
	char	*result;

	result = (char *) malloc(sizeof(char) * calculate_malloc_size(str));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '_')
		{
			i++;
			result[j++] = str[i++] - 32;
		}
		else
			result[j++] = str[i++];
	}
	return (result);
}

int	main(int argc, char **argv)
{
	char	*result;
	int		i;

	if (argc == 2)
	{
		result = ft_snake_to_camel(argv[1]);
		i = 0;
		while (result[i])
			write(1, &result[i++], 1);
		free(result);
	}
	write(1, "\n", 1);
	return (0);
}
