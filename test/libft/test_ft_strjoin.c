/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:18:40 by ttsubo            #+#    #+#             */
/*   Updated: 2024/10/31 19:34:58 by ttsubo           ###   ########.fr       */
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

void	_helper(const char *s1, const char *s2, const char *expected)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	TEST_ASSERT_EQUAL_STRING(expected, result);
	free(result);
}

void	_helper_null(const char *s1, const char *s2)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	TEST_ASSERT_NULL(result);
}

void	test_normal(void)
{
	_helper("Hello, ", "World!", "Hello, World!");
}
void	test_s1_empty(void)
{
	_helper("", "World!", "World!");
}
void	test_s2_empty(void)
{
	_helper("Hello, ", "", "Hello, ");
}
void	test_empty(void)
{
	_helper("", "", "");
}
void	test_s1_null(void)
{
	_helper_null(NULL, "World!");
}
void	test_s2_null(void)
{
	_helper_null("Hello", NULL);
}
void	test_null(void)
{
	_helper_null(NULL, NULL);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_normal);
	RUN_TEST(test_s1_empty);
	RUN_TEST(test_s2_empty);
	RUN_TEST(test_empty);
	RUN_TEST(test_s1_null);
	RUN_TEST(test_s2_null);
	RUN_TEST(test_null);
	return (UNITY_END());
}
