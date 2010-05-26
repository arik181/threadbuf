#include "queue.h"

/*** Create a queue which stores an arbitrary number of data nodes. 
 * Returns a pointer to the queue.
 ***/
queueptr initqueue()
{
	/*** Allocate memory for a single queue construct ***/
    queueptr queue = (queueptr) calloc(1, sizeof(struct queue));
    queue -> queueback = queue -> queuefront = NULL;
    queue -> count = 0;
	return queue;
}


/*** Add a file to the queue, increment file count ***/
void addfile(char * filename, queueptr queue)
{
    if (queue)
    {
        if (queue -> count == 0)
        {
            queue -> queuefront = queue -> queueback = \
                                 (nodeptr) calloc(1, sizeof(struct node));
            queue -> queueback -> next = NULL;
            queue -> queueback -> prev = NULL;
        }
        else 
        {
            nodeptr tmp = queue -> queueback;
            queue -> queueback = (nodeptr) calloc(1, sizeof(struct node));
            queue -> queueback -> prev = tmp;
            tmp -> next = queue -> queueback;
            queue -> queueback -> next = NULL;
        }

        strncpy(queue -> queueback -> filename, filename, MAXLINESIZE);
        ++queue -> count;
    }
}

char * getfile(queueptr queue)
{
    if (queue && ((queue -> count) > 0))
    {
       if (queue -> queuefront)
       {
            char * filename = calloc(1,(MAXFILENAMESIZE * sizeof(char)));
            strncpy(filename, queue -> queuefront -> filename, SIZEOFSLOT);
            dequeue(queue);
            return filename;
       }
    }

    else return NULL;
}

void dequeue(queueptr queue)
{
    if (queue && ((queue -> count) > 0))
    {
        nodeptr temp = queue -> queuefront;

        if (temp)
        {
            queue -> queuefront = temp -> next;
            if (queue -> queuefront)
                queue -> queuefront -> prev = NULL;
            free(temp);
        }
        --(queue -> count);
    }
}

/*** Print all the filenames in the queue ***/
void printfiles(queueptr queue)
{
    if (queue)
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
}


/*** Free up all memory used by the queue ***/
void destructqueue(queueptr queue)
{
    if (queue)
    {
        nodeptr queueprev = queue -> queuefront;
        nodeptr queuenext = queue -> queuefront;

        while (queuenext)
        {
            queuenext = queuenext -> next;
            free(queueprev);
            queueprev = queuenext;
        }
        free(queue);
    }
}

