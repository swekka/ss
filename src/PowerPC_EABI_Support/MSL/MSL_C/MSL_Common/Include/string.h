#ifndef _MSL_COMMON_STRING_H
#define _MSL_COMMON_STRING_H

#include "stddef.h"

#ifdef __cplusplus
extern "C" {
#endif

void *memcpy(void *dst, const void *src, size_t n);
void *memset(void *dst, int val, size_t n);
int memcmp(const void *lhs, const void *rhs, size_t count);
void *__memrchr(const void *ptr, int ch, size_t count);
void *memchr(const void *ptr, int ch, size_t count);
void *memmove(void *dst, const void *src, size_t n);
char *strrchr(const char *str, int c);
char *strchr(const char *str, int c);
int strncmp(const char *str1, const char *str2, size_t n);
int strcmp(const char *str1, const char *str2);
char *strstr(const char *str1, const char *str2);
char *strncat(char *dst, const char *src, size_t n);
char *strcat(char *dst, const char *src);
char *strncpy(char *dst, const char *src, size_t n);
char *strcpy(char *dst, const char *src);
int sscanf(const char *buffer, const char *format, ...);
size_t strlen(const char *str);

int atoi(const char *str);

#ifdef __cplusplus
}
#endif

#endif /* _MSL_COMMON_STRING_H */
