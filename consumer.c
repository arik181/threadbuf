#include <stdio.h>
int initconsumer()
{
}

int consume(char * slot)
{
    if (slot)
        printf("%s\n", slot);
}

