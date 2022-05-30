/**
* @file status.c
 *
 * `status.c` implements functions related to the `PhStatus` type, such as
 * getting a human readable string representing a status code.
 *
 * @see status.h for detailed documentation.
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

/**
 * Look up the human readable strings describing a status.
 *
 * @param status Status code to look up.
 * @return A set of strings describing the \p status.
 */
const struct StatusStrings statusString(PhStatus status)
{
    switch (status)
    {
        case PH_SUCCESS:
        {
            const struct StatusStrings result = { PH_SUCCESS_NAME, PH_SUCCESS_DESCRIPTION};
            return result;
        }
        case PH_GENERIC_ERROR:
        {
            const struct StatusStrings result = {PH_GENERIC_ERROR_NAME, PH_GENERIC_ERROR_DESCRIPTION};
            return result;
        }
        case PH_PANIC:
        {
            const struct StatusStrings result = { PH_PANIC_NAME, PH_PANIC_DESCRIPTION};
            return result;

        }
        default:
        {
            const struct StatusStrings result = { UNKNOWN_STATUS_NAME, UNKNOWN_STATUS_DESCRIPTION };
            return result;
        }
    }
}

[[nodiscard]] const char* const phStatusName(const PhStatus status)
{
    return statusString(status).name;
}

[[nodiscard]] const char* const phStatusDescription(const PhStatus status)
{
    return statusString(status).description;
}