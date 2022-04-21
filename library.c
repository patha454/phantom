#include "library.h"

extern void sys_exit_group(int status);

void main(void)
{
    sys_exit_group(69);
}
