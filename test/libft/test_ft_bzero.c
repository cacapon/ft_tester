/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:49:10 by ttsubo            #+#    #+#             */
/*   Updated: 2024/10/31 12:18:25 by ttsubo           ###   ########.fr       */
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

void	test_ft_bzero(void)
{
	char buf[10];

	for (int i = 0; i < 10; i++)
		buf[i] = 'A';
	ft_bzero(buf, 10);
	for (int i = 0; i < 10; i++)
		TEST_ASSERT_EQUAL_CHAR(buf[i], 0);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_bzero);
	return (UNITY_END());
}
