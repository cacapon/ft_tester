/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_striteri.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:51:05 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/01 21:07:15 by ttsubo           ###   ########.fr       */
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

void	_test_func(unsigned int index, char *c)
{
	(void)index;
	if (*c >= 'a' && *c <= 'z')
		*c -= 'a' - 'A';
}

void	_helper(char *s, const char *expected)
{
	ft_striteri(s, _test_func);
	TEST_ASSERT_EQUAL_STRING(expected, s);
}

void	test_normal(void)
{
	char str[] = "abcd";
	_helper(str, "ABCD");
}
void	test_empty(void)
{
	char str[] = "";
	_helper(str, "");
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_normal);
	RUN_TEST(test_empty);
	return (UNITY_END());
}
