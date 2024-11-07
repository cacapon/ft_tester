/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:49:10 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 15:20:08 by ttsubo           ###   ########.fr       */
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
    TEST_ASSERT_TRUE(ft_isalnum('A')); // 大文字
    TEST_ASSERT_TRUE(ft_isalnum('z')); // 小文字
    TEST_ASSERT_TRUE(ft_isalnum('0')); // 数字
    TEST_ASSERT_TRUE(ft_isalnum('9')); // 数字
}

void    test_normal_false()
{
    TEST_ASSERT_FALSE(ft_isalnum(' ')); // スペース
    TEST_ASSERT_FALSE(ft_isalnum('@')); // 記号
    TEST_ASSERT_FALSE(ft_isalnum('\n')); // 改行
    TEST_ASSERT_FALSE(ft_isalnum('!')); // 記号
}

void    test_boundary()
{
    // A-Z
    TEST_ASSERT_FALSE(ft_isalnum(64));
    TEST_ASSERT_TRUE(ft_isalnum(65));
    TEST_ASSERT_TRUE(ft_isalnum(90));
    TEST_ASSERT_FALSE(ft_isalnum(91));

    // a-z
    TEST_ASSERT_FALSE(ft_isalnum(64));
    TEST_ASSERT_TRUE(ft_isalnum(65));
    TEST_ASSERT_TRUE(ft_isalnum(90));
    TEST_ASSERT_FALSE(ft_isalnum(91));
    
    // 0-9
    TEST_ASSERT_FALSE(ft_isalnum(47));
    TEST_ASSERT_TRUE(ft_isalnum(48));
    TEST_ASSERT_TRUE(ft_isalnum(57));
    TEST_ASSERT_FALSE(ft_isalnum(58));
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_normal_true);
	RUN_TEST(test_normal_false);
	RUN_TEST(test_boundary);
	return (UNITY_END());
}
