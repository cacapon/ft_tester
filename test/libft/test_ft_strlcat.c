/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:50:10 by ttsubo            #+#    #+#             */
/*   Updated: 2024/10/31 16:19:21 by ttsubo           ###   ########.fr       */
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
	char dst[20] = "Hello, ";
	const char *src = "World!";
	size_t result = ft_strlcat(dst, src, sizeof(dst));

	TEST_ASSERT_EQUAL_STRING("Hello, World!", dst);
	TEST_ASSERT_EQUAL(result, 13);
}

void	test_out_of_buff(void)
{
	char dst[10] = "Hello, ";
	const char *src = "World!";
	size_t result = ft_strlcat(dst, src, sizeof(dst));

	TEST_ASSERT_EQUAL_STRING("Hello, Wo", dst);
	TEST_ASSERT_EQUAL(result, 13);
}

void	test_dst_empty(void)
{
	char dst[20] = "";
	const char *src = "World!";
	size_t result = ft_strlcat(dst, src, sizeof(dst));

	TEST_ASSERT_EQUAL_STRING("World!", dst);
	TEST_ASSERT_EQUAL(result, 6);
}

void	test_src_empty(void)
{
	char dst[20] = "Hello, ";
	const char *src = "";
	size_t result = ft_strlcat(dst, src, sizeof(dst));

	TEST_ASSERT_EQUAL_STRING("Hello, ", dst);
	TEST_ASSERT_EQUAL(result, 7);
}

void	test_src_and_dst_same(void)
{
	char dst[20] = "Hello";
	const char *src = "Hello";
	size_t result = ft_strlcat(dst, src, sizeof(dst));

	TEST_ASSERT_EQUAL_STRING("HelloHello", dst);
	TEST_ASSERT_EQUAL(result, 10);
}

void	test_size_zero(void)
{
	char dst[20] = "Hello, ";
	const char *src = "World!";
	size_t result = ft_strlcat(dst, src, 0);

	TEST_ASSERT_EQUAL_STRING("Hello, ", dst);
	TEST_ASSERT_EQUAL(result, 13);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_normal);
	RUN_TEST(test_out_of_buff);
	RUN_TEST(test_dst_empty);
	RUN_TEST(test_src_empty);
	RUN_TEST(test_src_and_dst_same);
	RUN_TEST(test_size_zero); //TODO: FAILED
	return (UNITY_END());
}