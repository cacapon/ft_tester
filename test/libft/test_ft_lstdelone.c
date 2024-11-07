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
	ft_lstdelone(l, _lstdelone_f);
	TEST_ASSERT_NULL(l->content);
}

void	test_lst_null(void)
{
	t_list *l = NULL;
	ft_lstdelone(l, _lstdelone_f);
	TEST_ASSERT_NULL(l);
}

void	test_dst_null(void)
{
	t_list *l = ft_lstnew(ft_strdup("1"));
	ft_lstdelone(l, NULL);
	TEST_ASSERT_NOT_NULL(l);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_normal);
	RUN_TEST(test_lst_null);
	RUN_TEST(test_dst_null);
	return (UNITY_END());
}
