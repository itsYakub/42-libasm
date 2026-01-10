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

static int __test_ft_strlen(size_t (*)(const char *));
static int __test_ft_strcpy(char *(*)(char *, const char *));
static int __test_ft_strcmp(int (*)(const char *, const char *));
static int __test_ft_write(ssize_t (*)(int, const void *, size_t));
static int __test_ft_read(ssize_t (*)(int, void *, size_t));
static int __test_ft_strdup(char *(*)(const char *));

int main(void) {
    __test_ft_strlen(strlen);
    __test_ft_strlen(ft_strlen);

    __test_ft_strcpy(strcpy);
    __test_ft_strcpy(ft_strcpy);
    
    __test_ft_strcmp(strcmp);
    __test_ft_strcmp(ft_strcmp);
    
    __test_ft_write(write);
    __test_ft_write(ft_write);
    
    __test_ft_read(read);
    __test_ft_read(ft_read);
    
    __test_ft_strdup(strdup);
    __test_ft_strdup(ft_strdup);

    return (0);
}

static int __test_ft_strlen(size_t (*func)(const char *)) {
    printf("=== TEST: strlen ===\n");

    /* 1. Hello, world! */
    do {
        const char *str = "Hello, world!";
        size_t len = func(str);

        printf("%s : %zu\n", str, len);
    } while (0);
    
    /* 2. Empty */
    do {
        const char *str = "";
        size_t len = func(str);

        printf("%s : %zu\n", str, len);
    } while (0);
    
    /* 3. Long */
    do {
        const char *str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
        size_t len = func(str);

        printf("%s : %zu\n", str, len);
    } while (0);
    return (1);
}

static int __test_ft_strcpy(char *(*func)(char *, const char *)) {
    printf("=== TEST: strcpy ===\n");

    /* 1. Hello, World! */
    do {
        char dst[16] = { 0 };
        const char *src = "Hello, World!";

        func(dst, src);
        printf("src: %s, dst = %s\n", src, dst);
    } while (0);
    
    /* 2. String literal */
    do {
        char dst[16] = { 0 };

        func(dst, "Hello, world!");
        printf("src: %s, dst = %s\n", "Hello, world!", dst);
    } while (0);
    return (1);
}

static int __test_ft_strcmp(int (*func)(const char *, const char *)) {
    printf("=== TEST: strcmp ===\n");

    /* 1. Two same */
    do {
        const char *str0 = "Hello, World!",
                   *str1 = "Hello, World!";

        printf("%s <-> %s : %d\n", str0, str1, func(str0, str1));
    } while (0);

    /* 2. One string */
    do {
        const char *str0 = "Hello, World!";

        printf("%s <-> %s : %d\n", str0, str0, func(str0, str0));
    } while (0);

    /* 3. Difference no. 1 */
    do {
        const char *str0 = "Hello, World!",
                   *str1 = "Lorem ipsum dolor sit amet";

        printf("%s <-> %s : %d\n", str0, str1, func(str0, str1));
    } while (0);
    
    /* 4. Difference no. 2 */
    do {
        const char *str0 = "Hello, World!",
                   *str1 = "Hello, world!";

        printf("%s <-> %s : %d\n", str0, str1, func(str0, str1));
    } while (0);
    
    /* 5. Difference no. 3 */
    do {
        const char *str0 = "Hello, World!",
                   *str1 = "Hello, World";

        printf("%s <-> %s : %d\n", str0, str1, func(str0, str1));
    } while (0);

    /* 6. One empty */
    do {
        const char *str0 = "Hello, World!",
                   *str1 = "";

        printf("%s <-> %s : %d\n", str0, str1, func(str0, str1));
    } while (0);

    /* 6. Two empty */
    do {
        const char *str0 = "",
                   *str1 = "";

        printf("%s <-> %s : %d\n", str0, str1, func(str0, str1));
    } while (0);
    return (1);
}

static int __test_ft_write(ssize_t (*func)(int, const void *, size_t)) {
    printf("=== TEST: write ===\n");
    
    /* 1. stdout */
    do {
        if (func(1, "Hello, World!\n", 14) == -1) {
            perror("func");
        }
    } while (0);
    
    /* 2. Non-existing file */
    do {
        if (func(42, "Hello, World!\n", 14) == -1) {
            perror("func");
        }
    } while (0);
    
    /* 3. Valid file */
    do {
        int fd = open("text.txt", O_CREAT | O_WRONLY, 0644);
        if (fd == -1) { perror("open"); break; }
        if (func(fd, "Hello, World!\n", 16) == -1) {
            perror("func");
        }
        close(fd);
    } while (0);
    return (1);
}

static int __test_ft_read(ssize_t (*func)(int, void *, size_t)) {
    printf("=== TEST: read ===\n");

    /* 1. stdin */
    do {
        char input[32] = { 0 };

        if (func(0, input, 32) == -1) {
            perror("func");
            break;
        }
        printf("%s\n", input);
    } while (0);
    
    /* 2. Non-existing file */
    do {
        char input[32] = { 0 };

        if (ft_write(42, input, 32) == -1) {
            perror("func");
            break;
        }
        printf("%s\n", input);
    } while (0);
    
    /* 3. No size */
    do {
        char input[32] = { 0 };

        if (ft_write(0, input, 0) == -1) {
            perror("func");
            break;
        }
        printf("%s\n", input);
    } while (0);
    
    /* 4. From file descriptor */
    do {
        char input[32] = { 0 };
        
        int fd = open("text.txt", O_RDONLY);
        if (fd == -1) { perror("open"); break; }
        if (func(fd, input, 32) == -1) {
            perror("func");
            close(fd);
            break;
        }
        printf("%s\n", input);
        close(fd);
    } while (0);
    return (1);
}

static int __test_ft_strdup(char *(*func)(const char *)) {
    printf("=== TEST: strdup ===\n");

    /* 1. Valid string */
    do {
        const char *s0 = "Hello, world!\n";
              char *s1 = func(s0);

        if (!s1) { perror("ft_strdup"); }
        else {
            printf("%s", s1), free(s1);
        }
    } while (0);
    return (1);
}
