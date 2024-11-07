/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strnstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:49:10 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/07 10:13:01 by ttsubo           ###   ########.fr       */
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

void    _helper(char *s1, char *s2, int len, char *expact)
{
    TEST_ASSERT_EQUAL_STRING(expact, ft_strnstr(s1, s2, len));
}

void    test_hit_world(void)
{
    _helper("hello world", "world", 11, "world");
}

void    test_hit_lo(void)
{
    _helper("hello world", "lo", 5, "lo world");
}

void    test_hit_needle_empty(void)
{
    _helper("hello", "", 5, "hello");
}

void    test_hit_same_haystack_and_needle(void)
{
    _helper("abc", "abc", 3, "abc");
}

void    test_no_hit_and_short(void)
{
    _helper("hello world", "world", 5, NULL);
}

void    test_no_hit_haystack_empty(void)
{
    _helper("", "a", 0, NULL);
}

void    test_no_hit_same_short_haystack_and_needle(void)
{
    _helper("abc", "abc", 2, NULL);
}

void	test_big_is_null(void)
{
	_helper(NULL, "hay!", 5, NULL);
}

void	test_little_is_null(void)
{
	_helper("hello",NULL, 5, "hello");
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_hit_world);
	RUN_TEST(test_hit_lo);
	RUN_TEST(test_hit_needle_empty);
	RUN_TEST(test_hit_same_haystack_and_needle);
	RUN_TEST(test_no_hit_and_short);
	RUN_TEST(test_no_hit_haystack_empty);
	RUN_TEST(test_no_hit_same_short_haystack_and_needle);
	RUN_TEST(test_big_is_null);
	return (UNITY_END());
}
