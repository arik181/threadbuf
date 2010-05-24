#include "defs.h"

#ifndef QUEUE
#define QUEUE

/*** Queue/Node Definition ***/
typedef struct node * nodeptr;
typedef struct queue * queueptr;
typedef int fifomutex;

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
char * getfile(queueptr queue);
void dequeue(queueptr queue);
void addfile(char * filename, queueptr queue);
void printfiles(queueptr queue);
void destructqueue(queueptr queue);

#endif // QUEUE
