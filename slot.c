#include "defs.h"
#include "buffer.h"

slotgroupptr initslots()
{
    slotgroup slotgrp;
    slotgroupptr returngroup = &slotgrp;

    int i = 0;
    for(i=0;i<NUMBEROFSLOTS;++i)
    {
        strncpy(slotgrp.slot[i], "\0", 1);
        slotgrp.inuse[i] = 0;
        slotgrp.fillcount[i] = 0;
    }

    return returngroup;
}

slotptr requestslot()
{
    slotptr slot;
    int inuse;
    
    if(bufptr)
    {
        int i = 0;
        for(i=0;i<NUMBEROFSLOTS;++i)
        {
            slot = &(bufptr -> slotgroup[i]);
            inuse = bufptr -> inuse[i]

            if (!inuse)
                break;
        }
    }
    return slot;
}
