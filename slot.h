#include "defs.h"
#include "semaphore.h"

#ifndef SLOT
#define SLOT

struct slotgroup
{
    char slot[NUMBEROFSLOTS][SIZEOFSLOT];
    sem_t emptysemaphore;
    sem_t fullsemaphore;
};


/*** Buffer/Slot Definition ***/
typedef struct slotgroup * slotgroupptr;

void destructslots(slotgroupptr slots);
void resetallslotbusystates(slotgroupptr buffer);
slotgroupptr initslots();
char * requestslot(slotgroupptr buffer, int index);

#endif // SLOT
