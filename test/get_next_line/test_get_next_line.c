/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:37:32 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/19 13:14:47 by ttsubo           ###   ########.fr       */
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

void	_helper_get_next_line(const char **expected, const char *actual, size_t actual_len)
{
	size_t i = 0;
	int pipe_fds[2];
	TEST_ASSERT_EQUAL_INT(0, pipe(pipe_fds));
	write(pipe_fds[1], actual, actual_len);
	close(pipe_fds[1]);

	while (*expected)
		TEST_ASSERT_EQUAL_STRING(*expected++, get_next_line(pipe_fds[0]));
	TEST_ASSERT_NULL(get_next_line(pipe_fds[0]));
	close(pipe_fds[0]);
}

void	_helper_get_next_line_null()
{
	size_t i = 0;
	int pipe_fds[2];
	TEST_ASSERT_EQUAL_INT(0, pipe(pipe_fds));
	write(pipe_fds[1], "", 0);
	close(pipe_fds[1]);

	TEST_ASSERT_EQUAL_STRING(NULL, get_next_line(pipe_fds[0]));
	close(pipe_fds[0]);
}

void	test_get_next_line(void) {
	char *expected[] = {"Hello\n", "world\n", "Welcome 42!", NULL};
	_helper_get_next_line(expected, "Hello\nworld\nWelcome 42!", 23);
}

void	test_get_next_line_no_linebreak(void) {
	char *expected[] = {"HelloworldWelcome 42!", NULL};
	_helper_get_next_line(expected, "HelloworldWelcome 42!", 21);
}

void	test_get_next_empty(void) {
	_helper_get_next_line_null();
}

void	test_get_next_eof_char(void) {
	char *expected[] = {"\0", NULL};
	_helper_get_next_line(expected, "\0", 1);
}

void test_get_next_line_multi_fd(void) {
		int pipe_fds[3][2];
	TEST_ASSERT_EQUAL_INT(0, pipe(pipe_fds[0]));
	TEST_ASSERT_EQUAL_INT(0, pipe(pipe_fds[1]));
	TEST_ASSERT_EQUAL_INT(0, pipe(pipe_fds[2]));
	
	write(pipe_fds[0][1], "Hello\nworld!\nWelcome42!", 23);
	write(pipe_fds[1][1], "single line", 11);
	write(pipe_fds[2][1], "This is\nanother\nmulti\nlines", 27);
	
	close(pipe_fds[0][1]);
	close(pipe_fds[1][1]);
	close(pipe_fds[2][1]);

	TEST_ASSERT_EQUAL_STRING("Hello\n", get_next_line(pipe_fds[0][0]));
	TEST_ASSERT_EQUAL_STRING("single line", get_next_line(pipe_fds[1][0]));
	TEST_ASSERT_EQUAL_STRING("This is\n", get_next_line(pipe_fds[2][0]));

	TEST_ASSERT_EQUAL_STRING("world!\n", get_next_line(pipe_fds[0][0]));
	TEST_ASSERT_EQUAL_STRING(NULL, get_next_line(pipe_fds[1][0]));
	TEST_ASSERT_EQUAL_STRING("another\n", get_next_line(pipe_fds[2][0]));

	TEST_ASSERT_EQUAL_STRING("Welcome42!", get_next_line(pipe_fds[0][0]));
	TEST_ASSERT_EQUAL_STRING(NULL, get_next_line(pipe_fds[1][0]));
	TEST_ASSERT_EQUAL_STRING("multi\n", get_next_line(pipe_fds[2][0]));

	TEST_ASSERT_EQUAL_STRING(NULL, get_next_line(pipe_fds[0][0]));
	TEST_ASSERT_EQUAL_STRING(NULL, get_next_line(pipe_fds[1][0]));
	TEST_ASSERT_EQUAL_STRING("lines", get_next_line(pipe_fds[2][0]));

	TEST_ASSERT_EQUAL_STRING(NULL, get_next_line(pipe_fds[0][0]));
	TEST_ASSERT_EQUAL_STRING(NULL, get_next_line(pipe_fds[1][0]));
	TEST_ASSERT_EQUAL_STRING(NULL, get_next_line(pipe_fds[2][0]));

	close(pipe_fds[0][0]);
	close(pipe_fds[1][0]);
	close(pipe_fds[2][0]);
}

void	test_get_next_line_fd_notfound() {
	TEST_ASSERT_NULL(get_next_line(-1));
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_get_next_line);
	//RUN_TEST(test_get_next_eof_char);
	RUN_TEST(test_get_next_line_no_linebreak);
	RUN_TEST(test_get_next_empty);
	RUN_TEST(test_get_next_line_fd_notfound);

	// bonus
	RUN_TEST(test_get_next_line_multi_fd);
	return (UNITY_END());
}