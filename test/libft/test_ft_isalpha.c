/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:49:10 by ttsubo            #+#    #+#             */
/*   Updated: 2024/10/31 13:44:34 by ttsubo           ###   ########.fr       */
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

void test_ft_isalpha(void)
{
    // 正しい入力のテスト
    TEST_ASSERT_TRUE(ft_isalpha('A')); // 大文字
    TEST_ASSERT_TRUE(ft_isalpha('z')); // 小文字

    // 不正な入力のテスト
    TEST_ASSERT_FALSE(ft_isalpha('0')); // 数字
    TEST_ASSERT_FALSE(ft_isalpha('9')); // 数字
    TEST_ASSERT_FALSE(ft_isalpha(' ')); // スペース
    TEST_ASSERT_FALSE(ft_isalpha('@')); // 記号
    TEST_ASSERT_FALSE(ft_isalpha('\n')); // 改行
    TEST_ASSERT_FALSE(ft_isalpha('!')); // 記号

    // 境界条件のテスト
    TEST_ASSERT_FALSE(ft_isalpha(256)); // ASCII範囲外の値
    TEST_ASSERT_FALSE(ft_isalpha(-1)); // 負の値
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_isalpha);
	return (UNITY_END());
}
