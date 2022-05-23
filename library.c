#include "printf/printf.h"
#include <stdnoreturn.h>

extern noreturn void sys_exit_group(int status);
extern long sys_write(int fd, void* buf, unsigned long count);

extern void putchar_(char c)
{
    sys_write(1, &c, 1);
}

noreturn void main(void* stackPointer)
{
    long* argc = (long*) stackPointer;
    printf_("sp: %p\n", argc);
    printf_("&argc: %p\n", argc + 0);
    printf_("Argc: %d\n", *(argc + 0));
    sys_write(1, "Test\n", 5);
    sys_exit_group(69);
}
