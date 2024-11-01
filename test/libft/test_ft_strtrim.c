/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:00:08 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/01 11:54:15 by ttsubo           ###   ########.fr       */
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

void	_helper(char const *s1, char const *set, char const *expected)
{
	char	*result;
	result = ft_strtrim(s1, set);
	TEST_ASSERT_EQUAL_STRING(expected, result);
	free(result);
}

void	_helper_null(char const *s1, char const *set)
{
	char	*result;
	result = ft_strtrim(s1, set);
	TEST_ASSERT_NULL(result);
	if (result != NULL)
		free(result);
}

void	test_set1_hit1(void){ _helper("Hello, World", "e", "Hllo, World");}
void	test_set1_hit2(void){ _helper("Hello, World", "o", "Hell, Wrld");}
void	test_set3_hit1(void){ _helper("Hello, World", "llo", "He, World");}
void	test_set2_hit2(void){ _helper("FizzBuzz", "zz", "FiBu");}
void	test_str_null(void){ _helper_null(NULL, "X");}
void	test_set_null(void){ _helper("Hello, World", NULL, "Hello, World");}
void	test_str_set_null(void){ _helper_null(NULL, NULL);}
void	test_set_nullchar(void){ _helper("Hello, World", "\0", "Hello, World");}
void	test_str_nullchar(void){ _helper("\0", "x", "\0");}


int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_set1_hit1);
	RUN_TEST(test_set1_hit2);
	RUN_TEST(test_set3_hit1);
	RUN_TEST(test_set2_hit2);
	RUN_TEST(test_str_null);
	RUN_TEST(test_set_null);
	RUN_TEST(test_str_set_null);
	RUN_TEST(test_set_nullchar);
	RUN_TEST(test_str_nullchar);
	return (UNITY_END());
}
