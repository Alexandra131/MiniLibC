// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>



void *malloc(size_t size)
{
    void *ptr;

    if (size == 0) {
        return NULL;
    }

    ptr = mmap(0, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (ptr != MAP_FAILED) {
        if (mem_list_add(ptr, size) != 0) {
            munmap(ptr, size);
            ptr = NULL;
        }
    }

    return ptr;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	// return NULL;

	  if (nmemb == 0 || size == 0) {
        return NULL; }

    size_t total_size = nmemb * size;
    void *ptr = mmap(0, total_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    for (size_t i = 0; i < total_size; i++) {
        ((char *)ptr)[i] = 0;
    }
    return ptr;
}

void free(void *ptr)
{
  if (ptr != NULL) {
	struct mem_list *size = mem_list_find(ptr);
        munmap(ptr, size->len);
        ptr = NULL;
    } }


void *realloc(void *ptr, size_t size) {
	void *new_ptr = mremap(ptr, 0, size, MREMAP_MAYMOVE);
    if (new_ptr == MAP_FAILED) {
        new_ptr = mmap(0, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
        if (new_ptr == MAP_FAILED) {
            return NULL;
        }
        if (ptr != NULL) {
            size_t copy_size = size;
            if (size > ((size_t)-1) - sizeof(size_t)) {
                copy_size = ((size_t)-1) - sizeof(size_t);
            }
            memcpy(new_ptr, ptr, copy_size);
            munmap(ptr, copy_size);
        }
    }
    return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size) {
    size_t total_size = nmemb * size;
    void *new_ptr = mremap(ptr, 0, total_size, MREMAP_MAYMOVE);
    if (new_ptr == MAP_FAILED) {
        new_ptr = mmap(0, total_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
        if (new_ptr == MAP_FAILED) {
            return NULL;
        }
        if (ptr != NULL) {
			 if (total_size > ((size_t)-1) - sizeof(total_size)) {
                total_size = ((size_t)-1) - sizeof(size_t);
            }
            memcpy(new_ptr, ptr, total_size);
            munmap(ptr, total_size);
        }
    }
    return new_ptr;
}
