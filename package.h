#include "defs.h"
#include "slot.h"
#include "queue.h"

#ifndef PACKAGE
#define PACKAGE

typedef struct package * packageptr;

struct package
{
    queueptr thequeue;
    slotgroupptr thebuffer;
};

packageptr initpackage(queueptr thequeue, slotgroupptr thebuffer);

#endif // PACKAGE
