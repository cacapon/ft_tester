/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:49:10 by ttsubo            #+#    #+#             */
/*   Updated: 2024/10/31 13:57:52 by ttsubo           ###   ########.fr       */
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

void test_ft_isascii(void)
{
    // 正しい入力のテスト
    for (int i = 0; i < 128; i++) {
        TEST_ASSERT_TRUE(ft_isascii(i)); // ASCII範囲内の値
    }

    // 不正な入力のテスト
    TEST_ASSERT_FALSE(ft_isascii(128)); // ASCII範囲外
    TEST_ASSERT_FALSE(ft_isascii(255)); // ASCII範囲外
    TEST_ASSERT_FALSE(ft_isascii(-1));  // 負の値

    // 境界条件のテスト
    TEST_ASSERT_TRUE(ft_isascii(0));    // ASCIIの最小値
    TEST_ASSERT_TRUE(ft_isascii(127));  // ASCIIの最大値
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_isascii);
	return (UNITY_END());
}
