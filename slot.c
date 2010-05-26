#include "defs.h"
#include "slot.h"

slotgroupptr initslots()
{
    slotgroupptr returngroup = calloc(1, sizeof(struct slotgroup));
    return returngroup;
}

void displayslots(slotgroupptr slotgrp)
{
    int i = 0;
    for(i=0;i<NUMBEROFSLOTS;++i)
    {
       printf("slot %d: %s\n", i, slotgrp -> slot[i]);
    }
}

char * requestslot(slotgroupptr buffer, int index)
{
    if(buffer)
    {
        return &(buffer -> slot[index][0]);
    }
    else
        return NULL;
}

void destructslots(slotgroupptr slots)
{
    while (slots)
    {
       if (slots)
       {
            free(slots);
       }
    }
}
