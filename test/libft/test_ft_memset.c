/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:45:48 by ttsubo            #+#    #+#             */
/*   Updated: 2024/10/31 14:52:08 by ttsubo           ###   ########.fr       */
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

void test_ft_memset(void) 
{
    // テスト用のバッファ
    char buffer1[20];
    char buffer2[20];

    // 1. 正常な初期化テスト
    memset(buffer1, 'A', sizeof(buffer1)); // 標準のmemsetを使って
    ft_memset(buffer2, 'A', sizeof(buffer2)); // 自作のft_memsetを使って
    TEST_ASSERT_EQUAL_MEMORY(buffer1, buffer2, sizeof(buffer1)); // メモリの内容が同じか確認

    // 2. 部分的な初期化テスト
    char partial_buffer[10] = "Hello";
    ft_memset(partial_buffer, 'X', 3); // 最初の3バイトを'X'で埋める
    TEST_ASSERT_EQUAL_STRING("XXXlo", partial_buffer); // 期待される出力と比較

    // 3. サイズが0の初期化テスト
    char zero_buffer[10] = "Test";
    ft_memset(zero_buffer, 'Z', 0); // サイズ0で初期化
    TEST_ASSERT_EQUAL_STRING("Test", zero_buffer); // 元の内容が保持されているか確認

    // 4. 非ASCII文字のテスト
    char non_ascii_buffer[5];
    ft_memset(non_ascii_buffer, '\0', sizeof(non_ascii_buffer)); // ヌル文字で初期化
    TEST_ASSERT_EQUAL_MEMORY(non_ascii_buffer, "\0\0\0\0\0", sizeof(non_ascii_buffer)); // 期待される出力と比較

    // 5. 大きなサイズの初期化テスト
    char large_buffer[100];
    ft_memset(large_buffer, 'C', sizeof(large_buffer)); // 大きなバッファを'c'で埋める
    for (size_t i = 0; i < sizeof(large_buffer); i++) {
        TEST_ASSERT_EQUAL('C', large_buffer[i]); // すべてのバイトが'C'であることを確認
    }
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_memset);
	return (UNITY_END());
}
