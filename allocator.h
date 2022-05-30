/**
 * @file allocator.h
 *
 * `allocator.h` declares the interface to memory allocators used by Phantom.
 *
 * @author H Paterson
 * @copyright BSL-1.0
 */

#ifndef PHANTOM_PROJECT_ALLOCATOR_H
#define PHANTOM_PROJECT_ALLOCATOR_H

#include <stddef.h>

/**
 * @typedef PhAllocator
 *
 * Memory management function which performs dynamic memory allocation.
 */
typedef void* (*PhAllocator)(size_t);

/**
 * @typedef PhDeallocator
 *
 * Memory management function which performs frees dynamically allocated
 * memory.
 */
typedef void (*PhDeallocator)(void*);

/**
 * @struct PhMemoryManager
 *
 * Interface to a memory management implementation which provides dynamic
 * memory management.
 *
 * @note `PhMemoryManager`s are intended for Phantom's internal use, analogs to
 * `malloc` in the C Standard Library. Loading in binaries should be done using
 * (abstractions over) the OS's memory mapping (page-allocation) functions, not
 * a `PhMemoryManager`.
 */
struct PhMemoryManager
{
    PhAllocator alloc;
    PhDeallocator dealloc;
};

#endif //PHANTOM_PROJECT_ALLOCATOR_H
