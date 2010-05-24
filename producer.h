#include "defs.h"
#include "queue.h"
#include "slot.h"

#ifndef PRODUCER
#define PRODUCER

typedef struct producer * producerptr;

struct producer 
{
    int tid;
};

producerptr initproducer(char * filename);
int produce(char * filename, char * slot);

#endif // PRODUCER
