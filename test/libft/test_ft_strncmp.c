/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strncmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:49:10 by ttsubo            #+#    #+#             */
/*   Updated: 2024/10/31 16:49:23 by ttsubo           ###   ########.fr       */
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

void    test_same(void)
{
    const char *str1 = "Hello";
    const char *str2 = "Hello";
    TEST_ASSERT_EQUAL_INT(0, ft_strncmp(str1, str2, 5));
}

void    test_diff_1st(void)
{
    const char *str1 = "Hello";
    const char *str2 = "World";
    TEST_ASSERT_EQUAL_INT(-15, ft_strncmp(str1, str2, 5));
}

void    test_diff_end(void)  
{
    const char *str1 = "Hello";
    const char *str2 = "Hellz";
    TEST_ASSERT_EQUAL_INT(-11, ft_strncmp(str1, str2, 5));
}

void    test_same_diff_length(void)  
{
    const char *str1 = "Hello, World";
    const char *str2 = "Hello, W";
    TEST_ASSERT_EQUAL_INT(0, ft_strncmp(str1, str2, 8));
}

void    test_same_over_len(void)
{
    const char *str1 = "Hello";
    const char *str2 = "Hello, World";
    TEST_ASSERT_EQUAL_INT(0, ft_strncmp(str1, str2, 5));
}

void    test_diff_empty(void)
{
    const char *str1 = "";
    const char *str2 = "Hello";
    TEST_ASSERT_EQUAL_INT(-72, ft_strncmp(str1, str2, 5));
    TEST_ASSERT_EQUAL_INT(72, ft_strncmp(str2, str1, 5));
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_same);
    RUN_TEST(test_same_diff_length);
    RUN_TEST(test_same_over_len);
	RUN_TEST(test_diff_1st);
	RUN_TEST(test_diff_end);
    RUN_TEST(test_diff_empty);
	return (UNITY_END());
}
