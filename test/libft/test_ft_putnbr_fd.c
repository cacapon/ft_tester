/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putnbr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:10:39 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/01 21:41:17 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "unity.h"

void	setUp(void)
{
}

void	tearDown(void)
{
}

void	_helper(int actual, char *expected)
{
	int fd;
	char buffer[13] = {0};
 
	// テスト用に一時ファイルを作成して書き込み用に開く
    fd = open("test_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    TEST_ASSERT_NOT_EQUAL(-1, fd); // ファイルが正しく開かれているか確認

    // 関数をテスト実行
    ft_putnbr_fd(actual, fd);

    // 書き込んだ内容を確認するため、ファイルの先頭に戻る
    lseek(fd, 0, SEEK_SET);

    // 結果を読み取る
    read(fd, buffer, 13);

    // 読み取った内容が期待通りかを確認
    TEST_ASSERT_EQUAL_STRING(expected, buffer);

    // ファイルを閉じて削除
    close(fd);
    remove("test_output.txt");
}

void	_helper_null()
{
}

void	test_42(void){ _helper(42, "42"); }
void	test_0(void){ _helper(0, "0"); }
void	test_minus10(void){ _helper(-10, "-10"); }
void	test_intmax(void){ _helper(INT_MAX, "2147483647"); }
void	test_intmin(void){ _helper(INT_MIN, "-2147483648"); }


int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_42);
	RUN_TEST(test_0);
	RUN_TEST(test_minus10);
	RUN_TEST(test_intmax);
	RUN_TEST(test_intmin);
	return (UNITY_END());
}
