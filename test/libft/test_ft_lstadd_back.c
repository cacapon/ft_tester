#include "libft.h"
#include "unity.h"

void	setUp(void)
{
}

void	tearDown(void)
{
}

void	test_normal(void)
{
	t_list *lst = ft_lstnew("First");
	t_list *node = ft_lstnew("Next");
	ft_lstadd_back(&lst, node);
	TEST_ASSERT_EQUAL_STRING("Next", lst->next->content);
}

void	test_normal2(void)
{
	t_list *lst = ft_lstnew("1");
	t_list *node1 = ft_lstnew("2");
	t_list *node2 = ft_lstnew("3");
	ft_lstadd_back(&lst, node1);
	ft_lstadd_back(&lst, node2);
	TEST_ASSERT_EQUAL_STRING("3", lst->next->next->content);
}

void	test_lst_null(void)
{
	t_list *lst = NULL;
	t_list *node = ft_lstnew("1");
	ft_lstadd_back(&lst, node);
	TEST_ASSERT_EQUAL_STRING("1", lst->content);	
}

void	test_new_null(void)
{
	t_list *lst = ft_lstnew("1");
	t_list *node = NULL;
	ft_lstadd_back(&lst, node);
	TEST_ASSERT_NULL(lst->next);	
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_normal);
	RUN_TEST(test_normal2);
	RUN_TEST(test_lst_null);
	RUN_TEST(test_new_null);
	return (UNITY_END());
}
