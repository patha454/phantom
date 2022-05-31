#include "printf/printf.h"
#include "system.h"
#include "status.h"

extern void putchar_(char c)
{
    phWrite(1, &c, 1);
}

void print_arguments(long argc, char** argv)
{
    for (int i = 0; i < argc; i++)
    {
        printf_("%s\n", argv[i]);
    }
}

void print_process_state(void* stackBase)
{
    long* argc = (long*) stackBase;
    char** argv = (char**) (stackBase + sizeof(long*));
    print_arguments(*argc, argv);
    char** env = stackBase + 16 + 8 * *argc;
    if (*(env - 1)!= 0)
    {
        printf_("fuck\n");
    }
    while (env != 0 && *env != NULL)
    {
        printf_("%s\n", *env);
        env += 1;
    }
}

[[noreturn]] void main(void* stackPointer)
{
    print_process_state(stackPointer);
    printf_("%s %s\n", phStatusName(PH_SUCCESS), phStatusDescription(PH_SUCCESS));
    phTerminate(69);
}
