/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:49:10 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 19:05:45 by ttsubo           ###   ########.fr       */
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

void test_ft_memcmp(void) {
    // 同一メモリ内容のテスト
    char mem1[] = "Hello, World!";
    char mem2[] = "Hello, World!";
    TEST_ASSERT_EQUAL_INT(0, ft_memcmp(mem1, mem2, 13)); // 完全一致するか確認

    // 部分一致のテスト
    char mem3[] = "Hello, World!";
    char mem4[] = "Hello, world!"; // 'W'と'w'が異なる
    TEST_ASSERT_TRUE(ft_memcmp(mem3, mem4, 13) != 0); // 大文字小文字の違いで不一致となるか確認
    TEST_ASSERT_TRUE(ft_memcmp(mem3, mem4, 7) == 0);  // 最初の7バイトが一致するか確認

    // 異なる内容のテスト（数値で差を確認）
    char mem5[] = "ABCDEF";
    char mem6[] = "ABDDEF"; // 'C'と'D'が異なる
    TEST_ASSERT_TRUE(ft_memcmp(mem5, mem6, 6) < 0); // mem5がmem6より小さいか確認（'C' < 'D'）

    // 空のメモリ領域のテスト
    char empty1[] = "";
    char empty2[] = "";
    TEST_ASSERT_EQUAL_INT(0, ft_memcmp(empty1, empty2, 0)); // サイズが0のときは常に一致とみなす

    // バイト比較のテスト（異なるバイトパターン）
    unsigned char bytes1[] = {0x01, 0x02, 0x03, 0x04};
    unsigned char bytes2[] = {0x01, 0x02, 0x04, 0x03}; // 3番目のバイトが異なる
    TEST_ASSERT_TRUE(ft_memcmp(bytes1, bytes2, 4) < 0); // bytes1 < bytes2であるか確認
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_memcmp);
	return (UNITY_END());
}
