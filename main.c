#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	ft_strlen(const char *str);
char *ft_strcpy(char *dest, char *src);
int	ft_strcmp(char *a, char *b);
int ft_write(int fd, char *a, int len);
int ft_read(int fd, char *a, int len);
char *ft_strdup(char *str);
int ft_atoi_base(char *str, char *base);

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

void	ft_list_push_front(t_list **begin_list, void *data);
int		ft_list_size(t_list *begin_list);
void	ft_list_sort(t_list **begin_list, int (*cmp)());
void	*ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
void	ft_lstprint(t_list *lst, char *cmt)
{
	int i;

	i = 0;
	printf("--- nodes ---\n");
	if (cmt)
		printf("| %s\n", cmt);
	while (lst)
	{
		printf("| %d | \"%s\" (%p)\n", i++, lst->data, lst);
		lst = lst->next;
	}
	printf("---------------\n\n");
}
void
	test_strlen(char *str)
{
	printf("\n%d = ft_strlen(\"%s\")\n", ft_strlen(str), str);
	printf("%lu = strlen(\"%s\")\n", strlen(str), str);
}

void
	test_strcpy(char *str)
{
	char dest[20];

	ft_strcpy(dest, str);
	printf("\n%s = ft_strcpy(dest[20], \"%s\")\n", dest, str);
}

void
	test_strcmp(char *a, char *b)
{
	printf("\n%d = ft_strcmp(\"%s\", \"%s\")\n", ft_strcmp(a, b), a, b);
	printf("%d = strcmp(\"%s\", \"%s\")\n", strcmp(a, b), a, b);
}

void
	test_write(int fd, char *str, int len)
{
	printf("\nft_write(%d, '%s', %d) ==> '", fd, str, len);
	fflush(stdout);
	int ret = ft_write(fd, str, len);
	printf("' (%d)\n", ret);
	printf("write(%d, '%s', %d) ==> '", fd, str, len);
	fflush(stdout);
	int ret2 = (int)write(fd, str, len);
	printf("' (%d)\n", ret2);
}

void
	test_read(char *path, int buffsize)
{
	int fd = open(path, O_RDONLY);
	int fd2 = open(path, O_RDONLY);
	char buffer[buffsize + 1];
	char buffer2[buffsize + 1];
	// char buffer2[buffsize];
	memset(buffer, 0, buffsize + 1);
	memset(buffer2, 0, buffsize + 1);
	int ret = (int)read(fd, buffer, buffsize);
	int ret2 = ft_read(fd2, buffer2, buffsize);
	printf("\nread(%d, [BUFFER], %d) ==> (%d) '%s'", fd, buffsize, ret, buffer);
	printf("\nft_read(%d, [BUFFER], %d) ==> (%d) '%s'\n", fd, buffsize, ret2, buffer2);
}

void
	test_strdup(char *str)
{
	char *ret = ft_strdup(str);
	printf("\n%s (%p) = ft_strdup(%s) from %p\n", ret, ret, str, str);
}

void
	test_atoibase(char *str, char *base)
{
	int ret;

	ret = ft_atoi_base(str, base);
	printf("\nTesting '%s'\n", str);
	printf("Atoing base %s = %d\n", base, ret);
}

int sorter(t_list *a, t_list *b)
{
	int ret = ft_strcmp(a->data, b->data);
	// printf("Calling fn %p (%p)| %p (%p)\nRet is %d\n", a, a->data, b, b->data, ret);
	return (ret);
}

int remover(void *data, void *ref)
{
	int ret;

	// ret = ft_strcmp(data, ref);
	(void)ref;
	ret = ft_strlen(data);
	printf("Calling remover with %p (%s) | %p\n ret is %d\n", data, data, ref, ret);
	ret = ret == 5;
	return (!ret);
}

int remover2(void *data, void *ref)
{
	int ret;

	ret = ft_strcmp(data, ref);
	printf("REMOVER2 cmp(%s, %s)%d\n", (char *)data, (char *)ref, ret);
	return (ret);
}

void freeer(void *data)
{
	printf("CALLING FREE %p (%s)\n", data, data);
	(void)data;
}

int
	main(int ac, char **av)
{
	(void)ac;
	(void)**av;
	test_strlen("Bonjour");
	test_strlen("");
	test_strlen("a");
	test_strcpy("Bonjour");
	test_strcmp("Abc", "Abc");
	test_strcmp("Abc", "Abd");
	test_strcmp("Abc", "Abce");
	test_strcmp("aaa", "aaa");
	test_strcmp("c", "b");
	test_write(1, "Bonjour", strlen("Bonjour"));
	test_write(1, "", 1);
	test_write(1, NULL, 1);
	test_write(-1, "yo", 2);
	test_read("ft_read.s", 10);
	test_read("", 10);
	test_strdup("dupped");
	test_atoibase("   \t\n++---+1010", "01");
	test_atoibase("   \t\n++---+123456", "0123456789");
	test_atoibase("   \t\n++--+ff", "0123456789abdcef");
	test_atoibase("   \t\n++--+ff", "0123456789abbdcef");
	test_atoibase("...--.", ".");

	t_list *l1 = malloc(sizeof(t_list *));
	t_list *l2 = malloc(sizeof(t_list *));
	t_list *l3 = malloc(sizeof(t_list *));
	*l3 = (t_list) { .data = "Bonjour", .next = NULL };
	*l2 = (t_list) { .data = "Bonjour", .next = l3 };
	printf("Init malloc ptr %p\n", &l1);
	*l1 = (t_list) { .data = "el 1", .next = l2 };
	ft_lstprint(l1, "Initialized");
	printf("Sended ptr %p\n", l1);
	char *el = ft_strdup("Salut");
	ft_list_push_front(&l1, el);
	ft_list_push_front(&l1, "Bonjour");
	ft_lstprint(l1, "Modified");
	printf("Ret is %p\n", l1);
	printf("Data init ptr is %p and l1->data is %p (%s)\n", el, (char *)l1->data, l1->data);
	printf("Next is %p\n", l1->next);
	int size = ft_list_size(l1);
	printf("SIZE IS %d\n", size);

	// printf("List %p\nl1 %p\nl2 %p\nl3 %p\nSort FN %p\n", &l1, l1, l1->next, l1->next->next, sorter);
	// ft_lstprint(l1, "Before");	
	// ft_list_sort(&l1, sorter);
	// ft_lstprint(l1, "Sorted");
	char *refer = "Bonjour";
	printf("LST PTR = %p\n", &l1);
	printf("BEFORE PTR = %p\n", l1);
	// printf("List %p\nl1 %p (%p)\nl2 %p (%p)\nl3 %p\nRefer str %p\nRemover FN %p\nFreer FN %p\n", &l1, l1, l1->data,
	// 	l1->next, l1->next->data, l1->next->next, refer, remover, freeer);
	void *ret = (void *)ft_list_remove_if(&l1, refer, remover2, freeer);
	printf("AFTER LST PTR = %p\n", l1);
	
	// printf("Bef Next = %p\n", l1->next);
	ft_lstprint(l1, "deleted");
	printf("RET = %p\n", ret);
	// printf("Next = %p\n", l1->next);
}
