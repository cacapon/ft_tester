/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_substr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:37:38 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/02 11:27:27 by ttsubo           ###   ########.fr       */
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

void	_helper(char *s, unsigned int start, size_t len, char *expected)
{
	char *result = ft_substr(s, start, len);
	TEST_ASSERT_EQUAL_STRING(result, expected);
	free(result);
}

void	_helper_null(char *s, unsigned int start, size_t len)
{
	char *result = ft_substr(s, start, len);
	TEST_ASSERT_NULL(result);
}

void	test_normal(void){ _helper("Hello world!", 6, 5, "world"); }
void	test_start_over(void){ _helper("Hello world!", 20, 5, ""); }
void	test_start_eq_len(void){ _helper("Hello world!", 13, 5, ""); }
void	test_head(void){ _helper("Hello world!", 0, 5, "Hello"); }
void	test_over_length(void){ _helper("Hello world!", 0, 20, "Hello world!"); }
void	test_s_is_null(void){ _helper_null(NULL, 0, 5); }



int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_normal);
	RUN_TEST(test_start_over);
	RUN_TEST(test_start_eq_len);
	RUN_TEST(test_head);
	RUN_TEST(test_over_length);
	RUN_TEST(test_s_is_null);
	return (UNITY_END());
}
