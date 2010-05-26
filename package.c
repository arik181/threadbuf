#include "package.h"

packageptr initpackage(queueptr thequeue, slotgroupptr thebuffer)
{
    packageptr returnpackage = calloc(1,sizeof(struct package));

    returnpackage -> thequeue = thequeue;
    returnpackage -> thebuffer = thebuffer;

    return returnpackage;
}

