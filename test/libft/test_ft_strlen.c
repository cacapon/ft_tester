/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:49:10 by ttsubo            #+#    #+#             */
/*   Updated: 2024/10/31 11:52:12 by ttsubo           ###   ########.fr       */
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

void	test_ft_strlen(void)
{
	TEST_ASSERT_EQUAL_INT(0, ft_strlen(""));
	TEST_ASSERT_EQUAL_INT(7, ft_strlen("42Tokyo"));
	TEST_ASSERT_EQUAL_INT(0, ft_strlen("\0"));
}

int	main(void)
{
	srand(time(NULL));
	UNITY_BEGIN();
	RUN_TEST(test_ft_strlen);
	return (UNITY_END());
}
