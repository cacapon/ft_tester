/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:20:23 by ttsubo            #+#    #+#             */
/*   Updated: 2024/10/31 12:31:39 by ttsubo           ###   ########.fr       */
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


void	test_ft_calloc(void)
{
	void *b;
	b = ft_calloc(0,0); // 一般的には非NULLポインタが返されることが多い
	TEST_ASSERT_NOT_NULL(b);
	b = ft_calloc(1,1);
	TEST_ASSERT_NOT_NULL(b);
	b = ft_calloc(3,5);
	TEST_ASSERT_NOT_NULL(b);
	b = ft_calloc(100,50);
	TEST_ASSERT_NOT_NULL(b);
	free(b);
}

void	test_ft_calloc_ignore(void)
{
	void *b;

	b = ft_calloc(-1,1);
	TEST_ASSERT_NULL(b);
	b = ft_calloc(1,-1);
	TEST_ASSERT_NULL(b);
	b = ft_calloc(10 ,SIZE_MAX);
	TEST_ASSERT_NULL(b);
	free(b);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_calloc);
	RUN_TEST(test_ft_calloc_ignore);
	return (UNITY_END());
}