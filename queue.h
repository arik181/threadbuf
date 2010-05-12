#ifndef QUEUE
#define QUEUE

#include "defs.h"

/*** Queue Definition ***/
typedef struct node * nodeptr;
typedef struct queue * queueptr;

struct queue
{
	nodeptr queuefront;
	nodeptr queueback;
    int count;
};

struct node 
{ 
	char filename[MAXLINESIZE];
	nodeptr next; 
	nodeptr prev; 
};

/*** Queue Functions ***/
queueptr initqueue();
void addfile(char * filename, queueptr queue);
void printfiles(queueptr queue);
void destructqueue(queueptr queue);

#endif // QUEUE
