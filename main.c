#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(const char *str);
char *ft_strcpy(char *dest, char *src);

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


int
	main(int ac, char **av)
{
	(void)ac;
	(void)**av;
	test_strlen("Bonjour");
	test_strlen("");
	test_strlen("a");

	test_strcpy("Bonjour");
}
