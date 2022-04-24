#include "library.h"
#include "printf/printf.h"

extern void sys_exit_group(int status);
extern long sys_write(int fd, void* buf, unsigned long count);

extern void putchar_(char c)
{
    sys_write(1, &c, 1);
}

void start(void)
{
    printf_("Hello, world!");
    sys_write(1, "Test", 4);
    sys_exit_group(69);
}
