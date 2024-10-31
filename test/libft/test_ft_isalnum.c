/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:49:10 by ttsubo            #+#    #+#             */
/*   Updated: 2024/10/31 12:39:54 by ttsubo           ###   ########.fr       */
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

void	test_ft_isalnum_num(void)
{
	TEST_ASSERT_EQUAL_INT(0, ft_isalnum('/'));
	TEST_ASSERT_EQUAL_INT(1, ft_isalnum('0'));
	TEST_ASSERT_EQUAL_INT(1, ft_isalnum('9'));
	TEST_ASSERT_EQUAL_INT(0, ft_isalnum(':'));
}

void	test_ft_isalnum_upper(void)
{
	TEST_ASSERT_EQUAL_INT(0, ft_isalnum('@'));
	TEST_ASSERT_EQUAL_INT(1, ft_isalnum('A'));
	TEST_ASSERT_EQUAL_INT(1, ft_isalnum('Z'));
	TEST_ASSERT_EQUAL_INT(0, ft_isalnum('['));
}

void	test_ft_isalnum_lower(void)
{
	TEST_ASSERT_EQUAL_INT(0, ft_isalnum('`'));
	TEST_ASSERT_EQUAL_INT(1, ft_isalnum('a'));
	TEST_ASSERT_EQUAL_INT(1, ft_isalnum('z'));
	TEST_ASSERT_EQUAL_INT(0, ft_isalnum('{'));
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_isalnum_num);
	RUN_TEST(test_ft_isalnum_upper);
	RUN_TEST(test_ft_isalnum_lower);
	return (UNITY_END());
}
