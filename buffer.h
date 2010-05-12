/*** Buffer/Slot Definition ***/
typedef struct buffer * bufferptr;
typedef struct slot * slotptr;

struct slot
{
    char content[SIZEOFSLOT + 1]; // +1, Terminated by \0
    int count;
};

struct buffer
{
    slot slotgroup[NUMBEROFSLOTS];
};

buffer initbuffer();
void writetoslot(char inputchar, slotptr writeslot);
