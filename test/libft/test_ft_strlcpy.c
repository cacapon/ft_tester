/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:50:10 by ttsubo            #+#    #+#             */
/*   Updated: 2024/10/31 16:27:31 by ttsubo           ###   ########.fr       */
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

void	test_normal(void)
{
	char dst[20];
	const char *src = "Hello, World!";
	size_t result = ft_strlcpy(dst, src, sizeof(dst));

	TEST_ASSERT_EQUAL_STRING("Hello, World!", dst);
	TEST_ASSERT_EQUAL(result, 13);
}

void	test_out_of_buff(void)
{
	char dst[10];
	const char *src = "Hello, World!";
	size_t result = ft_strlcpy(dst, src, sizeof(dst));

	TEST_ASSERT_EQUAL_STRING("Hello, Wo", dst);
	TEST_ASSERT_EQUAL(result, 13);
}

void	test_dst_empty_str(void)
{
	char dst[20] = "";
	const char *src = "Hello!";
	size_t result = ft_strlcpy(dst, src, sizeof(dst));

	TEST_ASSERT_EQUAL_STRING("Hello!", dst);
	TEST_ASSERT_EQUAL(result, 6);
}

void	test_src_empty_str(void)
{
	char dst[20];
	const char *src = "";
	size_t result = ft_strlcpy(dst, src, sizeof(dst));

	TEST_ASSERT_EQUAL_STRING("", dst);
	TEST_ASSERT_EQUAL(result, 0);
}

void	test_size_zero(void)
{
	char dst[20] = "Zero";
	const char *src = "Change";
	size_t result = ft_strlcpy(dst, src, 0);

	TEST_ASSERT_EQUAL_STRING("Zero", dst);
	TEST_ASSERT_EQUAL(result, 6);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_normal);
	RUN_TEST(test_out_of_buff);
	RUN_TEST(test_dst_empty_str);
	RUN_TEST(test_src_empty_str);
	RUN_TEST(test_size_zero);
	return (UNITY_END());
}