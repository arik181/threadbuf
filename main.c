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
    // Create a FIFO queue for filenames
    queueptr thequeue = initqueue();
    addfile("in0.txt", thequeue);
    addfile("in1.txt", thequeue);
    addfile("in2.txt", thequeue);
    addfile("in3.txt", thequeue);
    addfile("in4.txt", thequeue);
    addfile("in5.txt", thequeue);
    addfile("in6.txt", thequeue);
    addfile("in7.txt", thequeue);
    addfile("in8.txt", thequeue);
    addfile("in9.txt", thequeue);
    addfile("in10.txt", thequeue);
    addfile("in11.txt", thequeue);
    addfile("in12.txt", thequeue);
    addfile("in13.txt", thequeue);
    addfile("in14.txt", thequeue);
    addfile("in15.txt", thequeue);
    addfile("in16.txt", thequeue);
    addfile("in17.txt", thequeue);
    addfile("in18.txt", thequeue);
    addfile("in19.txt", thequeue);

    // Create the buffer
    slotgroupptr thebuffer = initslots();

    // Create a struct "package" containing both queue and buffer
    packageptr thepackage = initpackage(thequeue, thebuffer);

    // Initialize Semaphores/Mutexes
    sem_init(&(thebuffer -> emptysemaphore), 0, INITIALEMPTYVALUE);
    sem_init(&(thebuffer -> fullsemaphore), 0, INITIALFULLVALUE);
    sem_init(&(thequeue -> fifomutex), 0, INITIALFIFOVALUE);

    // Initialize semaphores
    // Create 20 producer threads.
    pthread_t producertid[MAXPRODUCERS]; 
    pthread_attr_t producerattr[MAXPRODUCERS]; 


    int i = 0;
    for(i=0;i<MAXPRODUCERS;++i)
    {
        pthread_attr_init(&producerattr[i]);
        pthread_create(&producertid[i],&producerattr[i],(void*)produce,thepackage);
    }
    
//  // Create 5 consumer threads.
//  pthread_t consumertid[MAXCONSUMERS];
//  pthread_attr_t consumerattr[MAXCONSUMERS];

//  int j = 0;
//  for(j=0;j<MAXCONSUMERS;++j)
//  {
//      pthread_attr_init(&consumerattr[j]);
//      pthread_create(&consumertid[j],&consumerattr[j],(void *)initconsumer,NULL);
//  }


}


