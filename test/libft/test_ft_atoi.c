/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:49:10 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/01 15:10:03 by ttsubo           ###   ########.fr       */
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

void	_helper_null(void)
{
}

void	test_1(void)
{
	_helper(1, "1");
}
void	test_a1(void)
{
	_helper(0, "a1");
}
void	test_2minus(void)
{
	_helper(0, "--1");
}
void	test_2plus(void)
{
	_helper(0, "++1");
}
void	test_1plus(void)
{
	_helper(1, "+1");
}
void	test_1minus(void)
{
	_helper(-1, "-1");
}
void	test_zero(void)
{
	_helper(0, "0");
}
void	test_42tokyo(void)
{
	_helper(42, "+42Tokyo");
}
void	test_plus101(void)
{
	_helper(101, "+101");
}
void	test_intmax(void)
{
	_helper(INT_MAX, "2147483647");
}
void	test_intmin(void)
{
	_helper(INT_MIN, "-2147483648");
}
void	test_minus_plus(void)
{
	_helper(0, "-+42");
}
void	test_plus_minus(void)
{
	_helper(0, "+-42");
}
void	test_only_plus(void)
{
	_helper(0, "+");
}
void	test_only_minus(void)
{
	_helper(0, "-");
}
void	test_escape(void)
{
	_helper(42, "   \t\n42");
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_1);
	RUN_TEST(test_a1);
	RUN_TEST(test_2minus);
	RUN_TEST(test_2plus);
	RUN_TEST(test_1plus);
	RUN_TEST(test_1minus);
	RUN_TEST(test_zero);
	RUN_TEST(test_42tokyo);
	RUN_TEST(test_plus101);
	RUN_TEST(test_intmax);
	RUN_TEST(test_intmin);
	RUN_TEST(test_minus_plus);
	RUN_TEST(test_plus_minus);
	RUN_TEST(test_only_plus);
	RUN_TEST(test_only_minus);
	RUN_TEST(test_escape);
	return (UNITY_END());
}
