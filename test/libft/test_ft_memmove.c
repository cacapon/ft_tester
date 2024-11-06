/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:49:10 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 19:27:29 by ttsubo           ###   ########.fr       */
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

// memo: overlapの動きについて
//  ft_memmove(overlap_src2, overlap_src2 + 2, 8);
//      ABCDEFGHIJ
//      CDEFGHIJ
//    ->CDEFGHIJIJ
void test_ft_memmove(void) {
    // 正常コピー(内容が同じ)
    char src0[] = "Hello, World!";
    TEST_ASSERT_EQUAL_STRING((char *)ft_memmove(src0, src0, 13), src0); 
 
    // 正常コピーのテスト（オーバーラップなし）
    char src1[] = "Hello, World!";
    char dest1[20];
    TEST_ASSERT_EQUAL_PTR(ft_memmove(dest1, src1, 13), dest1); // 戻り値がdest1であることを確認
    dest1[13] = '\0';
    TEST_ASSERT_EQUAL_STRING("Hello, World!", dest1);           // src1の内容がdest1にコピーされたか確認

    // オーバーラップのテスト（後方へコピー）
    char overlap_src1[] = "1234567890";
    ft_memmove(overlap_src1 + 4, overlap_src1, 6); // 後方へ重複コピー
    TEST_ASSERT_EQUAL_STRING("1234123456", overlap_src1); // 正しく重複コピーされたか確認

    // オーバーラップのテスト（前方へコピー）
    char overlap_src2[] = "ABCDEFGHIJ";
    ft_memmove(overlap_src2, overlap_src2 + 2, 8); // 前方へ重複コピー
    TEST_ASSERT_EQUAL_STRING("CDEFGHIJIJ", overlap_src2); // 正しく重複コピーされたか確認

    // サイズ0のテスト
    char src2[] = "Sample text";
    char dest2[20] = "Pre-existing text";
    TEST_ASSERT_EQUAL_PTR(ft_memmove(dest2, src2, 0), dest2); // サイズ0でコピーが発生しないことを確認
    TEST_ASSERT_EQUAL_STRING("Pre-existing text", dest2);      // 元の内容が保持されていることを確認
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_memmove);
	return (UNITY_END());
}
