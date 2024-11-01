/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strmapi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:27:28 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/01 20:41:37 by ttsubo           ###   ########.fr       */
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

char _test_func(unsigned int index, char c)
{
	return (c + index);
}

void	_helper(char *s, char *expected)
{
	char* result = ft_strmapi(s, _test_func);
	TEST_ASSERT_EQUAL_STRING(expected, result);
	free(result);
}

void	_helper_null(char *s)
{
	char* result = ft_strmapi(s, _test_func);
	TEST_ASSERT_NULL(result);
	if (result != NULL)
		free(result);
}

void	test_normal(void){ _helper("abcd", "aceg"); }
void	test_empty(void){ _helper("", ""); }
void	test_null(void){ _helper_null(NULL); }


int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_normal);
	RUN_TEST(test_empty);
	RUN_TEST(test_null);
	return (UNITY_END());
}
