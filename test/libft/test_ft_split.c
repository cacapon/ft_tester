/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:39:38 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/01 18:36:15 by ttsubo           ###   ########.fr       */
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

void	_helper(const char *s, char c, size_t len, char **expacted)
{
	char	**result;

	result = ft_split(s, c);
	TEST_ASSERT_EQUAL_STRING_ARRAY(expacted, result, len);
}

void	_helper_null(const char *s, char c)
{
	char	**result;

	result = ft_split(s, c);
	TEST_ASSERT_NULL(result);
}

void	test_split2(void)
{
	char	*expected[] = {"hello", "world", NULL};

	_helper("hello,world", ',', 3, expected);
}

void	test_split3(void)
{
	char	*expected[] = {"hello", "world", "42Tokyo", NULL};

	_helper("hello,world,42Tokyo", ',', 4, expected);
}

void	test_null_s(void)
{
	_helper_null(NULL, 'x');	
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_split2);
	RUN_TEST(test_split3);
	RUN_TEST(test_null_s);
	return (UNITY_END());
}
