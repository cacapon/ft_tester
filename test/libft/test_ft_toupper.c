/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_toupper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:53:31 by ttsubo            #+#    #+#             */
/*   Updated: 2024/10/31 19:12:29 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unity.h"
#include <string.h>

void	setUp(void)
{
}

void	tearDown(void)
{
}

void	_helper(char c, char expected)
{
	TEST_ASSERT_EQUAL_INT(expected, ft_toupper(c));
}

void	test_a(void)
{
	_helper('A', 'A');
}

void	test_b(void)
{
	_helper('b', 'B');
}

void	test_c(void)
{
	_helper('C', 'C');
}

void	test_1(void)
{
	_helper('1', '1');
}

void	test_symbol(void)
{
	_helper('!', '!');
}

void	test_space(void)
{
	_helper(' ', ' ');
}

void	test_eof(void)
{
	_helper(EOF, EOF);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_a);
	RUN_TEST(test_b);
	RUN_TEST(test_c);
	RUN_TEST(test_1);
	RUN_TEST(test_symbol);
	RUN_TEST(test_space);
	RUN_TEST(test_eof);
	return (UNITY_END());
}
