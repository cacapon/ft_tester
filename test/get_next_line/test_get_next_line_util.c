/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line_util.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:37:32 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/18 12:50:34 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "unity.h"
#include <unistd.h>
#include <fcntl.h>

void	setUp(void)
{
}

void	tearDown(void)
{
}

void	_helper_ft_getc(const char *expected, const char *actual, size_t actual_len)
{
	size_t i = 0;
	int pipe_fds[2];
	TEST_ASSERT_EQUAL_INT(0, pipe(pipe_fds));
	write(pipe_fds[1], actual, actual_len);
	close(pipe_fds[1]);

	while (i < actual_len)
		TEST_ASSERT_EQUAL_CHAR(expected[i++], ft_getc(pipe_fds[0]));
	TEST_ASSERT_EQUAL_CHAR(EOF, ft_getc(pipe_fds[0]));
	close(pipe_fds[0]);
}

void	_helper_ft_putc(const char *expected, const char *actual, size_t actual_len)
{
	size_t i = 0;
	t_string str;
	str.str = NULL;
	str.capa = 0;
	str.len = 0;
	
	while (i < actual_len) {
		TEST_ASSERT_EQUAL_CHAR(expected[i], ft_putc(&str, actual[i]));
		i++;
	}
	if (str.str != NULL) {
		TEST_ASSERT_EQUAL_STRING(expected, str.str);
		free(str.str);
	}
	else
		TEST_ASSERT_NULL(str.str);
}

void	test_ft_getc(void) 				 { _helper_ft_getc("Hello", "Hello", 5); }
void	test_ft_getc_in_line_break(void) { _helper_ft_getc("Welcome\n42!", "Welcome\n42!", 11); }
void	test_ft_getc_null(void) 		 { _helper_ft_getc("", "", 0); }

void	test_ft_putc(void) 					{ _helper_ft_putc("Hello", "Hello", 5); }
void	test_ft_putc_in_line_break(void) 	{ _helper_ft_putc("Welcome\n42!", "Welcome\n42!", 11); }
void	test_ft_putc_null(void) 			{ _helper_ft_putc("", "", 0); }

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_getc);
	RUN_TEST(test_ft_getc_in_line_break);
	RUN_TEST(test_ft_getc_null);

	RUN_TEST(test_ft_putc);
	RUN_TEST(test_ft_putc_in_line_break);
	RUN_TEST(test_ft_putc_null);
	return (UNITY_END());
}