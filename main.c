#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(const char *str);

void
	test_strlen(char *str)
{
	printf("TEST OF STRLEN WITH %s\n", str);
	printf("ft_strlen %d\n", ft_strlen(str));
	printf("strlen %lu\n", strlen(str));
}

int
	main(int ac, char **av)
{
	(void)ac;
	test_strlen(*av);
}
