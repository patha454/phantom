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

/**
 * @typedef PhStatus
 *
 * `PhStatus` indicates the success or failure of Phantom's internal operations,
 * and provides hints to the cause of failure on errors.
 */
typedef enum {
    PH_SUCCESS = 0,
    PH_GENERIC_ERROR = 1,
    PH_PANIC = 2
} PhStatus;

/**
 * Get a human readable string naming a `PhStatus`.
 *
 * @param status Status code to look up.
 * @return A human readable string containing the name of \p status.
 */
[[nodiscard]] const char* const phStatusName(const PhStatus status);

[[nodiscard]] const char* const phStatusDescription(const PhStatus status);

#endif //PHANTOM_PROJECT_STATUS_H
