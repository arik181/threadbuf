#include <pthread.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "defs.h"
#include "queue.h"
#include "slot.h"

#ifndef PRODUCER
#define PRODUCER

typedef struct producer * producerptr;

struct producer 
{
    char * filename;      
    char * slot;
};

void * initproducer(queueptr thequeue, sem_t * fifomutex);

void setfilename(char * filename);
void setslot(char * slot);

int produce(producerptr producer);

#endif // PRODUCER
