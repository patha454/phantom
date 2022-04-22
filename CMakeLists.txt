# CMake configuration.
CMAKE_MINIMUM_REQUIRED(VERSION 3.21)
CMAKE_POLICY(SET CMP0083 NEW)   # Manage PIE/PIC link settings.

# Basic project setup.
SET(PHANTOM_PROJECT "phantom_project")
SET(PHANTOM_BINARY "phantom")
SET(CMAKE_C_STANDARD 23)
SET(C_STANDARD_REQUIRED  ON)
SET(PHANTOM_MAJOR_VERSION "0" CACHE STRING "Major version of this Phantom build")
SET(PHANTOM_MINOR_VERSION "0" CACHE STRING "Minor version of this Phantom build")
SET(PHANTOM_PATCH_VERSION "0" CACHE STRING "Patch version of this Phantom build")
SET(PHANTOM_VERSION "${PHANTOM_MAJOR_VERSION}.${PHANTOM_MINOR_VERSION}.${PHANTOM_PATCH_VERSION}")
SET(PHANTOM_DESCRIPTION "Loader and Runtime Dynamic Linker (RTDL)")
SET(PHANTOM_HOMEPAGE "https://github.com/patha454/phantom")
PROJECT(
    ${PHANTOM_PROJECT}
    LANGUAGES C ASM
    VERSION ${PHANTOM_VERSION}
    DESCRIPTION ${PHANTOM_DESCRIPTION}
    HOMEPAGE_URL ${PHANTOM_HOMEPAGE}
)

# Report on target configuration.
MESSAGE(STATUS "Target CPU: ${CMAKE_SYSTEM_PROCESSOR}")
MESSAGE(STATUS "Target OS: ${CMAKE_SYSTEM_NAME}")

# Compile the provided target as a statically-linked position independent executable.
FUNCTION(MAKE_FREESTANDING_STATIC_PIE TARGET)
    # Set linker options.
    IF (CMAKE_SYSTEM_NAME STREQUAL "Linux")
        TARGET_LINK_OPTIONS(${PHANTOM_BINARY} PRIVATE
                "LINKER:--entry,start"
                "-nostdlib"
                "-nodefaultlibs"
                "-ffreestanding"
                "-static-pie"
                "-fpie"
                )
    ELSE()
        MESSAGE(FATAL_ERROR "Phantom: Unsupported target OS (`${CMAKE_SYSTEM_NAME}`)")
    ENDIF()
    # Set compiler options
    IF (CMAKE_C_COMPILER_ID STREQUAL "GNU")
        TARGET_COMPILE_OPTIONS(${PHANTOM_BINARY} PUBLIC
                "-nostartfiles"
                "-nodefaultlibs"
                "-ffreestanding"
                "-static-pie"
                "-fpie"
                )
    ELSE()
        MESSAGE(FATAL_ERROR "Phantom: Unsupported C Compiler (`${CMAKE_C_COMPILER_ID}`)")
    ENDIF()
ENDFUNCTION()

# Configure the Phantom RTDL binary.
ADD_EXECUTABLE(${PHANTOM_BINARY} library.c linux_x64.s)
MAKE_FREESTANDING_STATIC_PIE(${PHANTOM_BINARY})
