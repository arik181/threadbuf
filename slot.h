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

void destructslots(slotgroupptr slots);
void resetallslotbusystates(slotgroupptr slotgrp);
slotgroupptr initslots();
char * requestslot();

#endif // SLOT
