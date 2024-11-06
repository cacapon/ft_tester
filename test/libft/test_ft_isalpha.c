/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:49:10 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 15:25:31 by ttsubo           ###   ########.fr       */
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

void    test_normal_true()
{
    TEST_ASSERT_TRUE(ft_isalpha('A'));
    TEST_ASSERT_TRUE(ft_isalpha('Z'));
    TEST_ASSERT_TRUE(ft_isalpha('a'));
    TEST_ASSERT_TRUE(ft_isalpha('z'));
}

void    test_normal_false()
{
    TEST_ASSERT_FALSE(ft_isalpha('0')); // 数字
    TEST_ASSERT_FALSE(ft_isalpha('9')); // 数字
    TEST_ASSERT_FALSE(ft_isalpha(' ')); // スペース
    TEST_ASSERT_FALSE(ft_isalpha('@')); // 記号
    TEST_ASSERT_FALSE(ft_isalpha('\n')); // 改行
    TEST_ASSERT_FALSE(ft_isalpha('!')); // 記号
}

void    test_boundary()
{
    // A-Z
    TEST_ASSERT_FALSE(ft_isalpha(64));
    TEST_ASSERT_TRUE(ft_isalpha(65));
    TEST_ASSERT_TRUE(ft_isalpha(90));
    TEST_ASSERT_FALSE(ft_isalpha(91));

    // a-z
    TEST_ASSERT_FALSE(ft_isalpha(64));
    TEST_ASSERT_TRUE(ft_isalpha(65));
    TEST_ASSERT_TRUE(ft_isalpha(90));
    TEST_ASSERT_FALSE(ft_isalpha(91));
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_normal_true);
	RUN_TEST(test_normal_false);
	RUN_TEST(test_boundary);
	return (UNITY_END());
}
