/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:49:10 by ttsubo            #+#    #+#             */
/*   Updated: 2024/10/31 11:58:34 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "time.h"
#include "unity.h"

void	setUp(void)
{
}

void	tearDown(void)
{
}

void	test_ft_atoi(void)
{
	TEST_ASSERT_EQUAL_INT(0, ft_atoi(""));
	TEST_ASSERT_EQUAL_INT(123, ft_atoi("123"));
	TEST_ASSERT_EQUAL_INT(-456, ft_atoi("    -456"));
	TEST_ASSERT_EQUAL_INT(0, ft_atoi("    ABC+456"));
	TEST_ASSERT_EQUAL_INT(0, ft_atoi("XYZ"));
}

int	main(void)
{
	srand(time(NULL));
	UNITY_BEGIN();
	RUN_TEST(test_ft_atoi);
	return (UNITY_END());
}
