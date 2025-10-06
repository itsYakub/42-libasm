#include <stdio.h>
#include <stddef.h>
#include <string.h>

extern size_t ft_strlen(const char *s);
extern char *ft_strcpy(char *dest, const char *src);
extern int ft_strcmp(const char *s1, const char *s2);
extern ssize_t ft_write(int fd, const void *buf, size_t count);
extern ssize_t ft_read(int fd, void *buf, size_t count);
extern char *ft_strdup(const char *s);

int main(void) {
	printf("----\n");

	/* ft_strlen
	 * */
	{
		printf("strlen: %zu\n", strlen("Hello, world!"));
		printf("ft_strlen: %zu\n", ft_strlen("Hello, world!"));
	}

	printf("----\n");

	/* ft_strcpy
	 * */
	{
		const char	src0[16] = "Hello, world!",
					src1[16] = "Hello, world!";
		char		dst0[16],
					dst1[16];

		printf("strcpy(dst0, src0) = %s\n", strcpy(dst0, src0));
		printf("ft_strcpy(dst1, src1) = %s\n", ft_strcpy(dst1, src1));
	}
	
	printf("----\n");
	
	/* ft_strcmp
	 * */
	{
		const char	s1[16] = "Hello, Word!",
					s2[16] = "Hello, world!";

		printf("strcmp(s1, s2) = %i\n", strcmp(s1, s2));
		printf("ft_strcmp(s1, s2) = %i\n", ft_strcmp(s1, s2));
	}
	
	printf("----\n");
	
	return (0);
}
