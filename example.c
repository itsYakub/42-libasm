#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
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
    return (1);
}

static int __test_ft_strcpy(void) {
    return (1);
}

static int __test_ft_strcmp(void) {
    return (1);
}

static int __test_ft_write(void) {
    ft_write(1, "Hello, world!\n", 16);
    return (1);
}

static int __test_ft_read(void) {
    return (1);
}

static int __test_ft_strdup(void) {
    return (1);
}
