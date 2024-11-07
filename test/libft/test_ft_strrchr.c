/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strrchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:53:31 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/07 10:30:46 by ttsubo           ###   ########.fr       */
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
    char *result = ft_strrchr(s, c);
    TEST_ASSERT_EQUAL_PTR(result, strrchr(s, c));
}

void    _helper_null(char *s, char c)
{
    char *result = ft_strrchr(s, c);
    TEST_ASSERT_NULL(result);
}

void    test_found(void){_helper_normal("Hello, World",'o');}
void    test_not_found_normal(void){_helper_null("hello",'x');}
void    test_not_found_s_null(void){_helper_null(NULL,'o');}
void    test_not_found_c_over(void){_helper_null("hello",128);}
void    test_not_found_c_under(void){_helper_null("hello",-42);}

void    test_1st_char(void){_helper_normal("Hello, World!", 'H');}
void    test_last_char(void){_helper_normal("Hello, World!", '!');}
void    test_empty_str(void){_helper_null("", 'a');}
void    test_same_char(void){_helper_normal("aaaaa", 'a');}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_found);
    RUN_TEST(test_not_found_normal);
    RUN_TEST(test_not_found_s_null);
    RUN_TEST(test_not_found_c_over);
    RUN_TEST(test_not_found_c_under);
    RUN_TEST(test_1st_char);
    RUN_TEST(test_last_char);
    RUN_TEST(test_empty_str);
    RUN_TEST(test_same_char);
	return (UNITY_END());
}
