/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:49:10 by ttsubo            #+#    #+#             */
/*   Updated: 2024/10/31 14:17:35 by ttsubo           ###   ########.fr       */
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

#include <string.h>

void test_ft_memcpy(void)
{
    char src[] = "Hello, World!";
    char dest[20];

    // 正しい入力のテスト
    TEST_ASSERT_EQUAL_PTR(ft_memcpy(dest, src, 13), dest); // 戻り値が dest であることを確認
    dest[13] = '\0'; // null 終端を追加
    TEST_ASSERT_EQUAL_STRING("Hello, World!", dest);       // src の内容が dest にコピーされたか確認

    // 一部だけコピーするテスト
    ft_memcpy(dest, src, 5);
    dest[5] = '\0'; // null 終端を追加
    TEST_ASSERT_EQUAL_STRING("Hello", dest);               // 正しく部分コピーされたか確認

    // 空のコピーのテスト
    char empty_dest[20] = {0}; // 初期化
    ft_memcpy(empty_dest, src, 0); // 何もコピーしない
    TEST_ASSERT_EQUAL_STRING("", empty_dest);                // 空のままであることを確認

    // NULL ポインタのテスト
    TEST_ASSERT_NULL(ft_memcpy(NULL, NULL, 0)); // NULL ポインタに対する動作を確認

}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_memcpy);
	return (UNITY_END());
}
