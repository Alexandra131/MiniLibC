// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';

    return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{    while (len > 0) {
		if ((*destination = *source) != '\0') {
        destination++;
        source++;
		}
		len--;
    }
    while (len > 0) {
        *destination = '\0';
        destination++;
        len--;
    }
    return destination;
}

char *strcat(char *destination, const char *source)
{   while (*destination != '\0') {
        destination++;
    }
    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{   while (*destination != '\0') {
        destination++;
    }
    while (len > 0) {
		if(*source != '\0'){
        *destination = *source;
        destination++;
        source++;
		}
        len--;
    }
    *destination = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{   while (*str1 && *str2 && *str1 == *str2) {
        str1++;
        str2++;
    }
    return (*str1 - *str2);
}

int strncmp(const char *str1, const char *str2, size_t len)
{   while (len > 0 && *str1 && *str2 && *str1 == *str2) {
        str1++;
        str2++;
        len--;
    }
    if (len == 0 || (*str1 == '\0' && *str2 == '\0')) {
        return 0;
    } else {
        return (*str1 - *str2);
    }
	return -1;
}

size_t strlen(const char *str)
{   size_t length_str = 0;
    while (*str != '\0') {
        str++;
        length_str++;
    }
    return length_str;
}

char *strchr(const char *str, int c)
{   while (*str != '\0') {
        if (*str == c) {
            return (char *)str;
        }
        str++;
    }
    return NULL;
}

char *strrchr(const char *str, int c)
{   char *last = NULL;
    while (*str != '\0') {
        if (*str == c) {
            last = (char *)str;
        }
        str++;
    }
    if (last) {
        return last;
    }
	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{   if (*needle == '\0') {
        return (char *)haystack;
    }
    while (*haystack != '\0') {
        const char *h = haystack;
        const char *n = needle;

        while (*n != '\0' && *h == *n) {
            h++;
            n++;
        }
        if (*n == '\0') {
            return (char *)haystack;
        }

        haystack++;
    }
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{   if (*needle == '\0') {
        return (char *)haystack;
    }
    const char *last = NULL;
    while (*haystack != '\0') {
        const char *h = haystack;
        const char *n = needle;
        while (*n != '\0' && *h == *n) {
            h++;
            n++;
        }
        if (*n == '\0') {
            last = haystack;
        }
        haystack++;
    }
    return (char *)last;
}

void *memcpy(void *destination, const void *source, size_t num)
{   char *dest_copie = (char *)destination;
    const char *src_copie = (const char *)source;
    size_t i = 0;
    for (i = 0; i < num; i++) {
        dest_copie[i] = src_copie[i];
    }
    return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{   char *dest_copie = (char *)destination;
    const char *src_copie = (const char *)source;
    size_t i = 0;
    if (dest_copie > src_copie && dest_copie < src_copie + num) {
        for (i = num; i > 0; i--) {
            dest_copie[i - 1] = src_copie[i - 1];
        }
    } else {
        for (i = 0; i < num; i++) {
            dest_copie[i] = src_copie[i];
        }
    }
    return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{   const unsigned char *ptr1_copie = (const unsigned char *)ptr1;
    const unsigned char *ptr2_copie = (const unsigned char *)ptr2;
    size_t i = 0;
    for (i = 0; i < num; i++) {
        if (ptr1_copie[i] < ptr2_copie[i]) {
            return -1;
        } else if (ptr1_copie[i] > ptr2_copie[i]) {
            return 1;
        }
    }
    return 0;
}

void *memset(void *source, int value, size_t num)
{   unsigned char *sour_copie = (unsigned char *)source;
    unsigned char val_copie = (unsigned char)value;
    size_t i = 0;
    for (i = 0; i < num; i++) {
        sour_copie[i] = val_copie;
    }
    return source;
}
