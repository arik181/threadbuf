#include "queue.h"

/*** Create a queue which stores an arbitrary number of data nodes. 
 * Returns a pointer to the queue.
 ***/
queueptr initqueue()
{
	/*** Allocate memory for a single queue construct ***/
    queue q;
	queueptr qptr = &q; 
    queue -> queueback = queue -> queuefront = NULL;
    count = 0;
	return qptr;
}


/*** Add a file to the queue, increment file count ***/
void addfile(char * filename, queueptr queue)
{
	if (count == 0)
    {
		queue -> queueback = queue -> queuefront = \
                             calloc(1, (sizeof *node));
        queue -> back -> next = NULL;
    }
    else 
    {
        queueptr tmp = queue -> queueback;
		queue -> queueback = calloc(1, (sizeof *node));
        tmp -> next = queueback;
        queue -> queueback -> next = NULL;
    }

	strncpy(queueback -> filename, filename, MAXLINESIZE);
    ++count;
}


/*** Print all the filenames in the queue ***/
void printfiles(queueptr queue)
{
	nodeptr printptr = queue -> queuefront;

	if(printptr)
	{
		while(printptr != NULL && \
                (strncmp(printptr -> filename,"\0",1)))
		{
			printf("%s\n", printptr -> filename);
			printptr = printptr -> next;
		}
	}
}


/*** Free up all memory used by the queue ***/
void destructqueue(queueptr * queue)
{
    if (queue)
    {
        nodeptr queueprev = queue -> queuefront;
        nodeptr queuenext = queue -> queuefront;
    }

    while (queuenext)
    {
        queuenext = queuenext -> next;
        free(queueprev);
    }
 	free(*queue);
}

