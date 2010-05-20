#include "defs.h"

#ifndef SLOT
#define SLOT

struct slotgroup
{
    char slot[NUMBEROFSLOTS][SIZEOFSLOT];
    int fillcount[NUMBEROFSLOTS];
    int inuse[NUMBEROFSLOTS];
};


/*** Buffer/Slot Definition ***/
typedef struct slotgroup * slotgroupptr;

slotgroupptr initslots();
char * requestslot();

#endif // SLOT
