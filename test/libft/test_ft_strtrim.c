/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:00:08 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/09 11:58:47 by ttsubo           ###   ########.fr       */
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

// normal
void	test_libft_tester_1(void){ _helper("   xxxtripouille", " x", "tripouille");}
void	test_libft_tester_8(void){ _helper("   xxx   xxx", " x", "");}
void	test_hit_back(void){ _helper("Hello, World---", "-", "Hello, World");}
void	test_hit_flont(void){ _helper("+++Hello, World", "+", "Hello, World");}
void	test_hit_flont_back(void){ _helper("===Hello, World===", "=", "Hello, World");}
void	test_hit2_flont_back(void){ _helper("   +++Hello, World+++   ", "+ ", "Hello, World");}
void	test_hit2_flont(void){ _helper("   +++Hello, World", "+ ", "Hello, World");}
// undifind
void	test_libft_tester_9(void){ _helper("", "123", "");}
void	test_str_null(void){ _helper(NULL, "X", "");}
void	test_set_null(void){ _helper("Hello, World", NULL, "Hello, World");}
void	test_str_set_null(void){ _helper(NULL, NULL,"");}
void	test_set_nullchar(void){ _helper("Hello, World", "\0", "Hello, World");}
void	test_str_nullchar(void){ _helper("\0", "x", "");}


int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_libft_tester_1);
	RUN_TEST(test_libft_tester_8);
	RUN_TEST(test_libft_tester_9);
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
