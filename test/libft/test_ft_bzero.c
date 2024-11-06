/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:49:10 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 14:43:43 by ttsubo           ###   ########.fr       */
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

void	_helper(size_t len, char expected_1st_c, char expected_end_c)
{
	char	buf[10];

	for (int i = 0; i < 10; i++)
		buf[i] = 'x';
	ft_bzero(buf, len);
	TEST_ASSERT_EQUAL_CHAR(expected_1st_c, buf[0]);
	TEST_ASSERT_EQUAL_CHAR(expected_end_c, buf[9]);
}

void	_helper_nullcheck(void)
{
	char	*buf;

	buf = NULL;
	ft_bzero(buf, 1);
	TEST_ASSERT_NULL(buf);
}

// buf[10] = "xxxxxxxxxx"をft_bzeroで変更して確認する。
void	test_normal(void)
{
	_helper(10, 0, 0);
}
void	test_len_zero(void)
{
	_helper(0, 'x', 'x');
}
void	test_len_five(void)
{
	_helper(5, 0, 'x');
}
void	test_b_is_null(void)
{
	_helper_nullcheck();
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_normal);
	RUN_TEST(test_len_zero);
	RUN_TEST(test_len_five);
	RUN_TEST(test_b_is_null);
	return (UNITY_END());
}
