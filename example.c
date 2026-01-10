#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

extern size_t ft_strlen(const char *s);
extern char *ft_strcpy(char *dest, const char *src);
extern int ft_strcmp(const char *s1, const char *s2);
extern ssize_t ft_write(int fd, const void *buf, size_t count);
extern ssize_t ft_read(int fd, void *buf, size_t count);
extern char *ft_strdup(const char *s);

static int __test_ft_strlen(void);
static int __test_ft_strcpy(void);
static int __test_ft_strcmp(void);
static int __test_ft_write(void);
static int __test_ft_read(void);
static int __test_ft_strdup(void);

int main(void) {
    __test_ft_strlen();
    __test_ft_strcpy();
    __test_ft_strcmp();
    __test_ft_write();
    __test_ft_read();
    __test_ft_strdup();

    return (0);
}

static int __test_ft_strlen(void) {
    printf("=== TEST: ft_strlen ===\n");

    /* 1. Hello, world! */
    do {
        const char *str = "Hello, world!";
        size_t len = ft_strlen(str);

        printf("ft_strlen(%s) : %zu\n", str, len);
    } while (0);
    
    /* 2. Empty */
    do {
        const char *str = "";
        size_t len = ft_strlen(str);

        printf("ft_strlen(%s) : %zu\n", str, len);
    } while (0);
    
    /* 3. Long */
    do {
        const char *str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
        size_t len = ft_strlen(str);

        printf("ft_strlen(%s) : %zu\n", str, len);
    } while (0);
    return (1);
}

static int __test_ft_strcpy(void) {
    printf("=== TEST: ft_strcpy ===\n");

    /* 1. Hello, World! */
    do {
        char dst[16] = { 0 };
        const char *src = "Hello, World!";

        ft_strcpy(dst, src);
        printf("src: %s, dst = %s\n", src, dst);
    } while (0);
    
    /* 2. String literal */
    do {
        char dst[16] = { 0 };

        ft_strcpy(dst, "Hello, world!");
        printf("src: %s, dst = %s\n", "Hello, world!", dst);
    } while (0);
    return (1);
}

static int __test_ft_strcmp(void) {
    printf("=== TEST: ft_strcmp ===\n");

    /* 1. Two same */
    do {
        const char *str0 = "Hello, World!",
                   *str1 = "Hello, World!";

        printf("ft_strcmp(%s, %s) : %d\n", str0, str1, ft_strcmp(str0, str1));
    } while (0);

    /* 2. One string */
    do {
        const char *str0 = "Hello, World!";

        printf("ft_strcmp(%s, %s) : %d\n", str0, str0, ft_strcmp(str0, str0));
    } while (0);

    /* 3. Difference no. 1 */
    do {
        const char *str0 = "Hello, World!",
                   *str1 = "Lorem ipsum dolor sit amet";

        printf("ft_strcmp(%s, %s) : %d\n", str0, str1, ft_strcmp(str0, str1));
    } while (0);
    
    /* 4. Difference no. 2 */
    do {
        const char *str0 = "Hello, World!",
                   *str1 = "Hello, world!";

        printf("ft_strcmp(%s, %s) : %d\n", str0, str1, ft_strcmp(str0, str1));
    } while (0);
    
    /* 5. Difference no. 3 */
    do {
        const char *str0 = "Hello, World!",
                   *str1 = "Hello, World";

        printf("ft_strcmp(%s, %s) : %d\n", str0, str1, ft_strcmp(str0, str1));
    } while (0);

    /* 6. One empty */
    do {
        const char *str0 = "Hello, World!",
                   *str1 = "";

        printf("ft_strcmp(%s, %s) : %d\n", str0, str1, ft_strcmp(str0, str1));
    } while (0);

    /* 6. Two empty */
    do {
        const char *str0 = "",
                   *str1 = "";

        printf("ft_strcmp(%s, %s) : %d\n", str0, str1, ft_strcmp(str0, str1));
    } while (0);
    return (1);
}

static int __test_ft_write(void) {
    printf("=== TEST: ft_write ===\n");
    
    /* 1. stdout */
    do {
        if (ft_write(1, "Hello, World!\n", 14) == -1) {
            perror("ft_write");
        }
    } while (0);
    
    /* 2. Non-existing file */
    do {
        if (ft_write(42, "Hello, World!\n", 14) == -1) {
            perror("ft_write");
        }
    } while (0);
    
    /* 3. Valid file */
    do {
        int fd = open("text.txt", O_CREAT | O_WRONLY, 0644);
        if (fd == -1) { perror("open"); break; }
        if (ft_write(fd, "Hello, World!\n", 16) == -1) {
            perror("ft_write");
        }
        
        close(fd);
    } while (0);
    return (1);
}

static int __test_ft_read(void) {
    printf("=== TEST: ft_read ===\n");

    /* 1. stdin */
    do {
        char input[32] = { 0 };

        if (ft_read(0, input, 32) == -1) {
            perror("ft_read");
        }
    } while (0);
    
    /* 2. Non-existing file */
    do {
        char input[32] = { 0 };

        if (ft_write(42, input, 32) == -1) {
            perror("ft_read");
        }
    } while (0);
    
    /* 3. No size */
    do {
        char input[32] = { 0 };

        if (ft_write(0, input, 0) == -1) {
            perror("ft_read");
        }
    } while (0);
    
    /* 4. From file descriptor */
    do {
        char input[32] = { 0 };
        
        int fd = open("text.txt", O_RDONLY);
        if (fd == -1) { perror("open"); break; }
        if (ft_read(fd, input, 32) == -1) {
            perror("ft_read");
        }
        
        close(fd);
    } while (0);
    return (1);
}

static int __test_ft_strdup(void) {
    printf("=== TEST: ft_strdup ===\n");

    /* 1. Valid string */
    do {
        const char *s0 = "Hello, world!\n";
              char *s1 = ft_strdup(s0);

        if (!s1) { perror("ft_strdup"); }
        else {
            printf("%s", s1), free(s1);
        }
    } while (0);
    return (1);
}
