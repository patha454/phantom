/**
* @file status.c
 *
 * `status.c` implements functions related to the `PhStatus` type, such as
 * getting a human readable string representing a status code.
*/

#include "status.h"

#define PH_SUCCESS_NAME "PH_SUCCESS"
#define PH_SUCCESS_DESCRIPTION "Operation completed successfully"
#define PH_GENERIC_ERROR_NAME "PH_FAILURE"
#define PH_GENERIC_ERROR_DESCRIPTION "Unknown or general error"
#define PH_PANIC_NAME "PH_PANIC"
#define PH_PANIC_DESCRIPTION "This should have never happened. Please file a bug report."
#define UNKNOWN_STATUS_NAME "<unknown>"
#define UNKNOWN_STATUS_DESCRIPTION "<unknown status>"

/**
 * @struct StatusStrings
 *
 * Human readable strings describing a `PhStatus`.
 */
struct StatusStrings
{
    const char* const name;
    const char* const description;
};

const struct StatusStrings unknownStatus = {UNKNOWN_STATUS_NAME, UNKNOWN_STATUS_DESCRIPTION};

const struct StatusStrings statusStringMap[] = {
    [PH_SUCCESS] = { PH_SUCCESS_NAME, PH_SUCCESS_DESCRIPTION },
    [PH_GENERIC_ERROR] = { PH_GENERIC_ERROR_NAME, PH_GENERIC_ERROR_DESCRIPTION },
    [PH_PANIC] = { PH_PANIC_NAME, PH_PANIC_DESCRIPTION }
};
