/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putstr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:10:39 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/01 21:23:30 by ttsubo           ###   ########.fr       */
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

void	_helper(char *expected)
{
	int fd;
	char buffer[10] = {0};
 
	// テスト用に一時ファイルを作成して書き込み用に開く
    fd = open("test_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    TEST_ASSERT_NOT_EQUAL(-1, fd); // ファイルが正しく開かれているか確認

    // 関数をテスト実行
    ft_putstr_fd(expected, fd);

    // 書き込んだ内容を確認するため、ファイルの先頭に戻る
    lseek(fd, 0, SEEK_SET);

    // 結果を読み取る
    read(fd, buffer, 4);

    // 読み取った内容が期待通りかを確認
    TEST_ASSERT_EQUAL_STRING(expected, buffer);

    // ファイルを閉じて削除
    close(fd);
    remove("test_output.txt");
}

void	_helper_null()
{
}

void	test_normal(void){ _helper("TEXT"); }


int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_normal);
	return (UNITY_END());
}
