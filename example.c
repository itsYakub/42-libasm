/* TODO(@joleksia):
 * - [ ] finish all the functions;
 * - [ ] setup errno
 * */

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>

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
	
	/* ft_write
	 * */
	{
		int result0,
			result1;

		result0 = write(1, "write(): Hello, world!\n", 32);
		result1 = ft_write(1, "ft_write(): Hello, world!\n", 32);

		printf("result of write(): %d\n", result0);
		printf("result of ft_write(): %d\n", result1);

		printf("\n...yeah, it should be broken then...\n");
	}
	
	printf("----\n");
	
	/* ft_read
	 * */
	{
		char	buf0[16],
				buf1[16];
		int		result0,
				result1;

		result0 = read(0, buf0, 16);
		result1 = ft_read(0, buf1, 16);

		printf("result of read(): %s", buf0);
		printf("result of ft_read(): %s", buf1);
	}
	
	return (0);
}
