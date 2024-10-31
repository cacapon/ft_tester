/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:20:23 by ttsubo            #+#    #+#             */
/*   Updated: 2024/10/31 13:39:40 by ttsubo           ###   ########.fr       */
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

void	*test_ft_calloc_helper(size_t x, size_t y)
{
	void *b = ft_calloc(x,y);
	TEST_ASSERT_NOT_NULL(b);
	return (b);
}

void	*test_ft_calloc_ignore_helper(size_t x, size_t y)
{
	void *b = ft_calloc(x,y);
	TEST_ASSERT_NULL(b);
	return (b);
}

// memo:	calloc(0,0)は一般的には非NULLポインタが返されることが多い
void	test_ft_calloc(void)
{
	void *b;

	b = test_ft_calloc_helper(0,0);		free(b);
	b = test_ft_calloc_helper(1,1);		free(b);
	b = test_ft_calloc_helper(3,5);		free(b);
	b = test_ft_calloc_helper(100,50);	free(b);
}

void	test_ft_calloc_ignore(void)
{
	void *b;

	b = test_ft_calloc_ignore_helper(-1,1);			free(b);
	b = test_ft_calloc_ignore_helper(1,-1);			free(b);
	b = test_ft_calloc_ignore_helper(10,SIZE_MAX);	free(b);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_calloc);
	RUN_TEST(test_ft_calloc_ignore);
	return (UNITY_END());
}