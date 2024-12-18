/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:49:10 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/09 12:36:43 by ttsubo           ###   ########.fr       */
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

void    test_s_is_null(void)
{
    TEST_ASSERT_EQUAL_PTR(NULL, ft_memchr(NULL, 'a', 20));
}

void    test_libft_tester5(void)
{
    char s[] = {0, 1, 2 ,3 ,4 ,5};
    TEST_ASSERT_EQUAL_PTR(ft_memchr(s, 2+256, 3), s+2);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_memchr);
	RUN_TEST(test_s_is_null);
	RUN_TEST(test_libft_tester5);
	return (UNITY_END());
}
