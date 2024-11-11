/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:49:10 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/11 12:55:13 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unity.h"

void	setUp(void)
{
}

void	tearDown(void)
{
}

void	_helper(int expected, char *str)
{
	TEST_ASSERT_EQUAL_INT(expected, ft_atoi(str));
}

void	test_normal(void)
{
	_helper(123, "123");
	_helper(-456, "-456");
	_helper(789, "   789");
	_helper(-9876, "\t\t  \t-9876");
	_helper(1, "1a2b3c");
}

void	test_ignore_str(void)
{
	_helper(0, "");
	_helper(0, "ABC");
	_helper(0, "+-123");
	_helper(0, " ");
}

void	test_overflow(void)
{
	_helper(INT_MIN, "2147483648"); 	// 1overするため
	_helper(-1, "9223372036854775807");	// LONG_MAXのオーバーは-1になる
}

void	test_underflow(void)
{
	_helper(INT_MAX, "-2147483649");
	_helper(0, "-9223372036854775808");
}

void	test_atoi_same_check(void)
{
	char *actual[] = {
		"0", "42", "-123",  
		"2147483647", "-2147483648", 
		"9223372036854775807", "-9223372036854775808",
		"2234567890", "-2234567890",
		};

	for (int i=0; i<9; i++)
		TEST_ASSERT_EQUAL_INT(atoi(actual[i]), ft_atoi(actual[i]));
}

void	test_str_is_null(void)
{
	_helper(0, NULL);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_normal);
	RUN_TEST(test_ignore_str);
	RUN_TEST(test_overflow);
	RUN_TEST(test_underflow);
	RUN_TEST(test_str_is_null);
	RUN_TEST(test_atoi_same_check);
	return (UNITY_END());
}
