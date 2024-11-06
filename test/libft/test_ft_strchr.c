/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:53:31 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 19:58:24 by ttsubo           ###   ########.fr       */
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

void    _helper_normal(char *s, char c)
{
    char *result = ft_strchr(s, c);
    TEST_ASSERT_EQUAL_PTR(result, strchr(s, c));
}

void    _helper_null(char *s, char c)
{
    char *result = ft_strchr(s, c);
    TEST_ASSERT_NULL(result);
}

void    test_normal(void)
{
    _helper_normal("Hello, World!", 'o');
}

void    test_invalid_char(void)
{
    _helper_null("Hello, World!", 'z');
}

void    test_1st_char(void)
{
    _helper_normal("Hello, World!", 'H');
}

void    test_last_char(void)
{
    _helper_normal("Hello, World!", '!');
}

void    test_empty_str(void)
{
    _helper_null("", 'a');
}

void    test_same_char(void)
{
    _helper_normal("aaaaa", 'a');
}

void    test_not_found(void)
{
    _helper_null("Hello",-1);
    _helper_null("Hello",128);
    _helper_null(NULL, 'H');
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_normal);
    RUN_TEST(test_invalid_char);
    RUN_TEST(test_1st_char);
    RUN_TEST(test_last_char);
    RUN_TEST(test_empty_str);
    RUN_TEST(test_same_char);
    RUN_TEST(test_not_found);
	return (UNITY_END());
}
