#ifdef LINKTIME
#include <stdio.h>
#include <malloc.h>

void *__wrap_malloc(size_t size)
{
    void *ptr = malloc(size);
    printf("malloc(%d) = %p\n", (int)size, ptr);
    return ptr;
}

void __wrap_free(void *ptr)
{
    free(ptr);
    printf("free(%p)\n", ptr);
}
#endif