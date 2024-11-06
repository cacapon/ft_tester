#include "libft.h"
#include "unity.h"

void	setUp(void)
{
}

void	tearDown(void)
{
}

void	_lstdelone_f(void *d) {
	free(d);
}

void	*_lstmap_f(void *content) {
	(void)content;
	return ("OK !");
}

void	test_normal(void)
{
	t_list *lst = ft_lstnew(ft_strdup("First"));
	lst->next = ft_lstnew(ft_strdup("Next"));
	t_list *res = ft_lstmap(lst, _lstmap_f, _lstdelone_f);
	TEST_ASSERT_EQUAL_STRING("OK !", res->content);
	TEST_ASSERT_EQUAL_STRING("OK !", res->next->content);
}

void	test_create_node_failed(void)
{
	TEST_MESSAGE("test_ft_lstmap:create_node_failed:Not tested because it is difficult to reproduce.");	
}

void	test_lst_null(void)
{
	t_list *lst = NULL;
	t_list *res = ft_lstmap(lst, _lstmap_f, _lstdelone_f);
	TEST_ASSERT_NULL(res);	
}

void	test_f_null(void)
{
	t_list *lst = ft_lstnew("1");
	t_list *res = ft_lstmap(lst, NULL, _lstdelone_f);
	TEST_ASSERT_NULL(res);	
}

void	test_del_null(void)
{
	t_list *lst = ft_lstnew("1");
	t_list *res = ft_lstmap(lst, _lstmap_f, NULL);
	TEST_ASSERT_NULL(res);	
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_normal);
	RUN_TEST(test_create_node_failed);
	RUN_TEST(test_lst_null);
	RUN_TEST(test_f_null);
	RUN_TEST(test_del_null);
	return (UNITY_END());
}
