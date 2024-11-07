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
	TEST_ASSERT_EQUAL_STRING("First", lst->content);
	TEST_ASSERT_NOT_NULL(lst);
	TEST_ASSERT_NULL(lst->next);
}

void	test_lstnew_failed(void)
{
	TEST_MESSAGE("test_ft_lstnew_failed:Not tested because it is difficult to reproduce.");	
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_normal);
	RUN_TEST(test_lstnew_failed);
	return (UNITY_END());
}
