/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:49:10 by ttsubo            #+#    #+#             */
/*   Updated: 2024/10/31 13:50:10 by ttsubo           ###   ########.fr       */
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

void test_ft_isdigit(void)
{
    // 正しい入力のテスト
    for (char c = '0'; c <= '9'; c++) {
        TEST_ASSERT_TRUE(isdigit(c)); // 数字
    }

    // 不正な入力のテスト
    TEST_ASSERT_FALSE(isdigit('A')); // 大文字
    TEST_ASSERT_FALSE(isdigit('z')); // 小文字
    TEST_ASSERT_FALSE(isdigit('@')); // 記号
    TEST_ASSERT_FALSE(isdigit(' ')); // スペース
    TEST_ASSERT_FALSE(isdigit('\n')); // 改行

    // 境界条件のテスト
    TEST_ASSERT_FALSE(isdigit(256)); // ASCII範囲外
    TEST_ASSERT_FALSE(isdigit(-1)); // 負の値
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_isdigit);
	return (UNITY_END());
}
