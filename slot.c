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

char * requestslot(slotgroupptr slotgrp)
{
    int i = 0;
    while (i < NUMBEROFSLOTS)
    {
        if(slotgrp -> inuse[i] == FALSE)
        {
           slotgrp -> inuse[i] = TRUE;
           return &(slotgrp -> slot[i][0]);
        }
        ++i;
    }
    return NULL;
}

destructslots(slotgroupptr slots)
{
    while (slots)
    {
       if (slots)
       {
            free(slots);
       }
    }
}

