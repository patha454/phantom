#include "library.h"

extern void sys_exit_group(int status);

void start(void)
{
    sys_exit_group(69);
}
