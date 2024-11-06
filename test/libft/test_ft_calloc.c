/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:20:23 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 15:06:43 by ttsubo           ###   ########.fr       */
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

void	*_helper(size_t x, size_t y)
{
	void *b = ft_calloc(x,y);
	TEST_ASSERT_NOT_NULL(b);
	return (b);
}

void	*_ignore_helper(size_t x, size_t y)
{
	void *b = ft_calloc(x,y);
	TEST_ASSERT_NULL(b);
	return (b);
}

// memo:	calloc(0,0)は一般的には非NULLポインタが返されることが多い
void	test_normal(void)
{
	void *b;

	b = _helper(1,1);		free(b);
	b = _helper(3,5);		free(b);
	b = _helper(100,50);	free(b);
}

void	test_return_null(void)
{
	void *b;

	b = _ignore_helper(0,0);
	b = _ignore_helper(1,0);
	b = _ignore_helper(0,1);
	b = _ignore_helper(-1,1);
	b = _ignore_helper(1,-1);
	b = _ignore_helper(10,SIZE_MAX);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_normal);
	RUN_TEST(test_return_null);
	return (UNITY_END());
}
