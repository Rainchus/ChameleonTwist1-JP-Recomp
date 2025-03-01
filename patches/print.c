#include "patches.h"

int dummyData = 0;
int dummyBss;

void dummyFunc(void)
{
    return;
}

#if 0
RECOMP_PATCH void Sched_StartThread(void) {
    *(volatile int*) 0 = 0;
}
#endif

#if 0
#include "patches.h"
#include "misc_funcs.h"

void* proutPrintf(void* dst, const char* fmt, size_t size) {
    recomp_puts(fmt, size);
    return (void*)1;
}

int recomp_printf(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);

    int ret = _Printf(&proutPrintf, NULL, fmt, args);

    va_end(args);

    return ret;
}

#endif