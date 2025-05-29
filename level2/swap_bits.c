/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gojeda <gojeda@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:12:24 by gojeda            #+#    #+#             */
/*   Updated: 2025/05/28 11:12:25 by gojeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : swap_bits
Expected files   : swap_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, swaps its halves (like the example) and
returns the result.

Your function must be declared as follows:

unsigned char	swap_bits(unsigned char octet);

Example:

  1 byte
_____________
 0100 | 0001
     \ /
     / \
 0001 | 0100
*/

unsigned char	swap_bits(unsigned char octet)
{
	return (octet >> 4 | octet << 4);
}
