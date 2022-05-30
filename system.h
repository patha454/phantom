/**
 * @file system.h
 *
 * `system.h` declares the interface functions Phantom uses to request
 * elementary services from the host.
 *
 * Functions declared in `system.h` need to be implemented for each host
 * Phantom targets. Hosts would usually be an operating system kernel.
 *
 * @author H Paterson
 * @copyright BSL-1.0
 */
#ifndef PHANTOM_PROJECT_SYSTEM_H
#define PHANTOM_PROJECT_SYSTEM_H

#include <stddef.h>
#include <stdint.h>
#include <stdnoreturn.h>

/**
 * Write the contents of a buffer to an open file.
 *
 * @param file Handle to an open file to be written to.
 * @param buffer Date to write to the \p file.
 * @param length Bytes to be written from the /p buffer to the /p file.
 */
void phWrite(int file, uint8_t* buffer, size_t length);

/**
 * Terminate the process, including the Phantom loader, loaded program, and
 * all associated resources. Violently...
 *
 * @param status Exit status code to return to the system.
 */
noreturn void phTerminate(int status);

#endif //PHANTOM_PROJECT_SYSTEM_H
