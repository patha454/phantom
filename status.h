/**
 * @file status.h
 *
 * `status.h` declares the `PhStatus` type, and related functions.
 *
 * `PhStatus` communicates the success, or reason for failure, of basic
 * Phantom operations.
 *
 * @author H Paterson
 * @copyright BSL-1.0
 */

#ifndef PHANTOM_PROJECT_STATUS_H
#define PHANTOM_PROJECT_STATUS_H

typedef enum {
    PH_SUCCESS = 0,
    PH_GENERIC_ERROR = 1,
    PH_PANIC = 1
} PhStatus;

const char* const phStatusName(PhStatus status);

#endif //PHANTOM_PROJECT_STATUS_H
