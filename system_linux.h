/**
 * @file linux_x64.h
 *
 * `linux_x64.h` declares Linux kernel APIs implemented in assembly.
 *
 * The kernel APIs implemented here are used to implement the Phantom host
 * system interface.
 *
 * @see system.h
 * @see system_linux.c
 */
#ifndef PHANTOM_PROJECT_SYSTEM_LINUX_H
#define PHANTOM_PROJECT_SYSTEM_LINUX_H

#include <stdnoreturn.h>

/**
 * Linux `write` system call.
 *
 * @param file Linux file handle.
 * @param buffer Buffer to write to the /p file.
 * @param length Length of the /p buffer to write out.
 */
extern void sys_write(int file, void* buffer, unsigned int length);

/**
 * Linux `exit_group` system call.
 *
 * @param status Exit status code to return to the kernel.
 */
extern noreturn void sys_exit_group(int status);

#endif //PHANTOM_PROJECT_SYSTEM_LINUX_H
