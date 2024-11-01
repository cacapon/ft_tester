/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:00:08 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/01 17:36:48 by ttsubo           ###   ########.fr       */
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

void	test_hit_flont(void){ _helper("+++Hello, World", "+", "Hello, World");}
void	test_hit_back(void){ _helper("Hello, World---", "-", "Hello, World");}
void	test_hit_flont_back(void){ _helper("===Hello, World===", "=", "Hello, World");}
void	test_hit2_flont(void){ _helper("+++Hello, World", "++", "+Hello, World");}
void	test_hit2_flont_back(void){ _helper("+++Hello, World+++", "++", "+Hello, World+");}
void	test_str_null(void){ _helper_null(NULL, "X");}
void	test_set_null(void){ _helper_null("Hello, World", NULL);}
void	test_str_set_null(void){ _helper_null(NULL, NULL);}
void	test_set_nullchar(void){ _helper("Hello, World", "\0", "Hello, World");}
void	test_str_nullchar(void){ _helper("\0", "x", "\0");}


int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_hit_flont);
	RUN_TEST(test_hit_back);
	RUN_TEST(test_hit_flont_back);
	RUN_TEST(test_hit2_flont);
	RUN_TEST(test_hit2_flont_back);
	RUN_TEST(test_str_null);
	RUN_TEST(test_set_null);
	RUN_TEST(test_str_set_null);
	RUN_TEST(test_set_nullchar);
	RUN_TEST(test_str_nullchar);
	return (UNITY_END());
}
