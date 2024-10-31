/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:53:31 by ttsubo            #+#    #+#             */
/*   Updated: 2024/10/31 14:57:34 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include "unity.h"

void	setUp(void)
{
}

void	tearDown(void)
{
}

void test_ft_strchr(void) {
    // 1. 基本的な検索テスト
    const char *str1 = "Hello, World!";
    char *result1 = ft_strchr(str1, 'o'); // 'o'の最初の出現位置を探す
    TEST_ASSERT_EQUAL_PTR(result1, strchr(str1, 'o')); // 標準のstrchrと比較

    // 2. 存在しない文字のテスト
    const char *str2 = "Hello, World!";
    char *result2 = ft_strchr(str2, 'z'); // 存在しない文字を探す
    TEST_ASSERT_NULL(result2); // NULLが返されるべき

    // 3. 文字列の最初の文字のテスト
    const char *str3 = "Hello, World!";
    char *result3 = ft_strchr(str3, 'H'); // 最初の文字'H'を探す
    TEST_ASSERT_EQUAL_PTR(result3, strchr(str3, 'H')); // 標準のstrchrと比較

    // 4. 文字列の最後の文字のテスト
    const char *str4 = "Hello, World!";
    char *result4 = ft_strchr(str4, '!'); // 最後の文字'!'を探す
    TEST_ASSERT_EQUAL_PTR(result4, strchr(str4, '!')); // 標準のstrchrと比較

    // 5. 空文字列のテスト
    const char *str5 = "";
    char *result5 = ft_strchr(str5, 'a'); // 空文字列に'a'を探す
    TEST_ASSERT_NULL(result5); // NULLが返されるべき

    // 6. 同じ文字が連続する場合のテスト
    const char *str6 = "aaaaa";
    char *result7 = ft_strchr(str6, 'a'); // 連続する文字'a'を探す
    TEST_ASSERT_EQUAL_PTR(result7, strchr(str6, 'a')); // 標準のstrchrと比較

    // 7. 最後の文字が一致する場合のテスト
    const char *str7 = "abcabc";
    char *result8 = ft_strchr(str7, 'c'); // 最後の文字'c'を探す
    TEST_ASSERT_EQUAL_PTR(result8, strchr(str7, 'c')); // 標準のstrchrと比較
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_strchr);
	return (UNITY_END());
}
