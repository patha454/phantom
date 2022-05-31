/**
* @file system_linux.h
 *
 * `system_linux.h` implements the interface between Phantom and a Linux kernel
 * host.
 *
 * @see system.h for the abstract interface definition and documentation comments.
 *
 * @author H Paterson
 * @copyright BSL-1.0
*/

#include "system.h"
#include "system_linux.h"

void phWrite(int file, uint8_t* buffer, size_t length)
{
    sys_write(file, buffer, length);
}

[[noreturn]] void phTerminate(int status)
{
    sys_exit_group(status);
}
