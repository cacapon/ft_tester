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

void	test_normal(void)
{
	t_list *l = ft_lstnew(ft_strdup("1"));
	l->next = ft_lstnew(ft_strdup("2"));
	l->next->next = ft_lstnew(ft_strdup("3"));
	t_list *res = ft_lstlast(l);
	TEST_ASSERT_EQUAL_STRING("3", res->content);
}

void	test_lst_null(void)
{
	t_list *l = NULL;
	t_list *res = ft_lstlast(l);
	TEST_ASSERT_NULL(l);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_normal);
	RUN_TEST(test_lst_null);
	return (UNITY_END());
}
