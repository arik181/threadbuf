/*** Buffer/Slot Definition ***/
typedef struct slotgroup * slotgroupptr;
typedef struct char ** slotptr;

struct slotgroup
{
    char slot[NUMBEROFSLOTS][SIZEOFSLOT];
    int fillcount[NUMBEROFSLOTS];
    int inuse[NUMBEROFSLOTS];
};

void initslots(bufferptr bufptr);
slotptr requestslot();

