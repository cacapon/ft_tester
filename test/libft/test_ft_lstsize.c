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
	lst->next = ft_lstnew("Second");
	lst->next->next = ft_lstnew("Third");
	TEST_ASSERT_EQUAL_INT(3, ft_lstsize(lst));
}

void	test_lst_is_null(void)
{
	t_list *lst = NULL;
	TEST_ASSERT_EQUAL_INT(0,ft_lstsize(lst));	
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_normal);
	RUN_TEST(test_lst_is_null);
	return (UNITY_END());
}
