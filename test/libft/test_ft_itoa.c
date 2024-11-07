/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:49:10 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/01 19:33:41 by ttsubo           ###   ########.fr       */
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

void	_helper(int n, char *expected)
{
	TEST_ASSERT_EQUAL_STRING(expected, ft_itoa(n));
}

void	_helper_null(void)
{
}

void	test_1(void){_helper(1, "1");}
void	test_0(void){_helper(0, "0");}
void	test_42(void){_helper(42, "42");}
void	test_10000(void){_helper(10000, "10000");}
void	test_minus(void){_helper(-10000, "-10000");}
void	test_intmax(void){_helper(INT_MAX, "2147483647");}
void	test_intmin(void){_helper(INT_MIN, "-2147483648");}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_1);
	RUN_TEST(test_0);
	RUN_TEST(test_42);
	RUN_TEST(test_10000);
	RUN_TEST(test_minus);
	RUN_TEST(test_intmax);
	RUN_TEST(test_intmin);
	return (UNITY_END());
}
