#include "main.h"

/*** 
 * threadbuf - 
 * A multithreaded producer/consumer implemented with pthreads.
 *
 * Write a program that implements a producer/consumer buffer problem
 * using pthreads. Producer threads write text into a buffer and Consumer
 * threads read the text out of the buffer and print it to stdout. The 
 * buffer holds 5 slots of 128 characters each, and is accessible to all
 * threads. You will need to synchronize access to the buffer to avoid
 * inconsistent results. Each piece of text should only be written and
 * read exactly once.
 *
 ***/

int main(int argc, char ** argv)
{
// Create 5 consumer threads.
// Create 20 producer threads.
/*** down(mutex2);
* ++writecount; 
* if(writecount == 1)
*   down(readblock);
* up(mutex2);
* down(writeblock);
* access(resource);
* up(writeblock);
* down(mutex2);
* --writecount;
* if (writecount == 0)
*   up (readblock);
* up(mutex2);
* ***/
}

