/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gojeda <gojeda@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:38:30 by gojeda            #+#    #+#             */
/*   Updated: 2025/05/27 17:38:34 by gojeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name	: ft_strspn
Expected files	: ft_strspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the strspn function 
(man strspn).

The function should be prototyped as follows:

size_t	ft_strspn(const char *s, const char *accept);
*/

#include <unistd.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i;
	size_t	j;
	int		flag;

	i = 0;
	while (s[i])
	{
		j = 0;
		flag = 0;
		while (accept[j] && !flag)
		{
			if ((unsigned char) s[i] == (unsigned char) accept[j])
				flag = 1;
			j++;
		}
		if (!flag)
			return (i);
		i++;
	}
	return (i);
}
