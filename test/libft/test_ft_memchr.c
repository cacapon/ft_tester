/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:49:10 by ttsubo            #+#    #+#             */
/*   Updated: 2024/10/31 14:02:58 by ttsubo           ###   ########.fr       */
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

void test_ft_memchr(void)
{
    const char str[] = "Hello, World!";
    
    // 正しい入力のテスト
    TEST_ASSERT_EQUAL_PTR(&str[4], ft_memchr(str, 'o', 13)); // 'o' が最初に出現する位置
    TEST_ASSERT_EQUAL_PTR(&str[0], ft_memchr(str, 'H', 13)); // 'H' が最初に出現する位置
    TEST_ASSERT_EQUAL_PTR(&str[5], ft_memchr(str, ',', 13)); // ',' が最初に出現する位置

    // 指定された範囲内に存在しない文字のテスト
    TEST_ASSERT_EQUAL_PTR(NULL, ft_memchr(str, 'x', 13)); // 存在しない文字

    // 範囲を超えるテスト
    TEST_ASSERT_EQUAL_PTR(&str[4], ft_memchr(str, 'o', 5)); // 'o' が範囲内で最初に出現
    TEST_ASSERT_EQUAL_PTR(NULL, ft_memchr(str, 'o', 4));    // 'o' が範囲外で存在しない

    // 辺界条件のテスト
    TEST_ASSERT_EQUAL_PTR(NULL, ft_memchr(NULL, 'a', 0));    // NULL ポインタに対して
    TEST_ASSERT_EQUAL_PTR(NULL, ft_memchr(str, 'o', 0));     // 長さ 0 の範囲
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_memchr);
	return (UNITY_END());
}
