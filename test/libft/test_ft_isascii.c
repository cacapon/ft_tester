/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:49:10 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 15:30:57 by ttsubo           ###   ########.fr       */
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

void    test_normal()
{
    TEST_ASSERT_TRUE(ft_isascii('A')); // 大文字
    TEST_ASSERT_TRUE(ft_isascii('z')); // 小文字
    TEST_ASSERT_TRUE(ft_isascii('0')); // 数字
    TEST_ASSERT_TRUE(ft_isascii('9')); // 数字
    TEST_ASSERT_TRUE(ft_isascii(' ')); // スペース
    TEST_ASSERT_TRUE(ft_isascii('@')); // 記号
    TEST_ASSERT_TRUE(ft_isascii('\n')); // 改行
    TEST_ASSERT_TRUE(ft_isascii('!')); // 記号
}

void    test_boundary()
{
    // ASCII
    TEST_ASSERT_FALSE(ft_isascii(-1));
    TEST_ASSERT_TRUE(ft_isascii(0));
    TEST_ASSERT_TRUE(ft_isascii(127));
    TEST_ASSERT_FALSE(ft_isascii(128));
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_normal);
	RUN_TEST(test_boundary);
	return (UNITY_END());
}
