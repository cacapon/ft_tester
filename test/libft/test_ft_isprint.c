/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:49:10 by ttsubo            #+#    #+#             */
/*   Updated: 2024/10/31 13:58:41 by ttsubo           ###   ########.fr       */
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

void test_ft_isprint(void)
{
    // 正しい入力のテスト
    for (char c = 32; c < 127; c++) {
        TEST_ASSERT_TRUE(ft_isprint(c)); // 印刷可能な文字
    }

    // 不正な入力のテスト
    TEST_ASSERT_FALSE(ft_isprint(0));   // NULL文字
    TEST_ASSERT_FALSE(ft_isprint(31));  // 制御文字
    TEST_ASSERT_FALSE(ft_isprint(127)); // DEL文字
    TEST_ASSERT_FALSE(ft_isprint(-1));  // 負の値
    TEST_ASSERT_FALSE(ft_isprint(128)); // ASCII範囲外

    // 境界条件のテスト
    TEST_ASSERT_TRUE(ft_isprint(32));   // スペース
    TEST_ASSERT_TRUE(ft_isprint(126));  // チルダ(~)
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_isprint);
	return (UNITY_END());
}
