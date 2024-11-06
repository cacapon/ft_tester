#include "libft.h"
#include "unity.h"

void	setUp(void)
{
}

void	tearDown(void)
{
}

void	_change_first(void *contents)
{
	((char *)contents)[0] = 'X';
}

void	test_normal(void)
{
	t_list *lst = ft_lstnew(ft_strdup("First"));
	lst->next = ft_lstnew(ft_strdup("Next"));
	ft_lstiter(lst, _change_first);
	TEST_ASSERT_EQUAL_STRING("Xirst", lst->content);
	TEST_ASSERT_EQUAL_STRING("Xext", lst->next->content);
}

void	test_lst_null(void)
{
	t_list *lst = NULL;
	ft_lstiter(lst, _change_first);
	TEST_ASSERT_NULL(lst);	
}

void	test_new_null(void)
{
	t_list *lst = ft_lstnew("1");
	ft_lstiter(lst, NULL);
	TEST_ASSERT_NULL(lst->next);	
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_normal);
	RUN_TEST(test_lst_null);
	RUN_TEST(test_new_null);
	return (UNITY_END());
}
