#include "library.h"

extern void sys_exit_group(int status);
extern long sys_write(int fd, void* buf, unsigned long count);

void start(void)
{
    sys_write(1, "Test", 4);
    sys_exit_group(69);
}
