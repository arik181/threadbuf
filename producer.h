#include "defs.h"

typedef struct producer * producerptr;

struct producer 
{
    int tid;
};

producerptr initproducer();
int openfile();
int produce();

void filetoslot(FILE fd, slotptr writeslot);
void writetoslot(char inputchar, slotptr writeslot);
