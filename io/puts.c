#include <stdio.h>
#include <internal/io.h>
#include <internal/syscall.h>
#include <internal/types.h>
#include <errno.h>
#include <string.h>


int puts(const char *str) {
int result_ret = 0;
    int length = strlen(str);
    if (write(1, str, length) < 0) {
        return -1;
    }
    if (write(1, "\n", 1) < 0) {
        return -1;
    }
    result_ret = length + 1;
    return result_ret;
}
