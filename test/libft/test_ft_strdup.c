/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:58:10 by ttsubo            #+#    #+#             */
/*   Updated: 2024/10/31 15:49:17 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include "unity.h"

void	setUp(void)
{
}

void	tearDown(void)
{
}

void test_normal(void)
{
	const char *src = "Hello, World!";
	char *dst = ft_strdup(src);
	TEST_ASSERT_NOT_NULL(dst);
	TEST_ASSERT_EQUAL_STRING(src, dst);
	free(dst);
}

void test_empty_str(void)
{
	const char *src = "";
	char *dst = ft_strdup(src);
	TEST_ASSERT_NOT_NULL(dst);
	TEST_ASSERT_EQUAL_STRING(src, dst);
	free(dst);
}

void test_long_str(void)
{
	const char *src = "This is a long string for testing ft_strdup.";
	char *dst = ft_strdup(src);
	TEST_ASSERT_NOT_NULL(dst);
	TEST_ASSERT_EQUAL_STRING(src, dst);
	free(dst);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_normal);
	RUN_TEST(test_empty_str);
	RUN_TEST(test_long_str);

	return (UNITY_END());
}
