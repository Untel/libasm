/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:05:02 by adda-sil          #+#    #+#             */
/*   Updated: 2020/01/30 16:16:23 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	free(ret);
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

	printf("\nTYPE SOMETHING:\n> ");
	fflush(stdout);
	char buff[301];
	int ret = ft_read(0, buff, 300);
	buff[ret] = 0;
	printf("Ret == %s (%d)", buff, ret);
}
