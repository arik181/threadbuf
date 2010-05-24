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
    sem_t * emptysemaphore;
    sem_t * fullsemaphore;
    sem_t * fifomutex;

    // Initialize Semaphores/Mutexes
    sem_init(emptysemaphore, 0, NUMBEROFSLOTS);
    sem_init(fullsemaphore, 0, NUMBEROFSLOTS);
    sem_init(fifomutex, 0, NUMBEROFSLOTS);

    emptysemaphore = sem_open("empty",O_CREAT,"r+",INITIALEMPTYVALUE);
    fullsemaphore = sem_open("full",O_CREAT,"r+",INITIALFULLVALUE);
    fifomutex = sem_open("fifo",O_CREAT,"r+",INITIALFIFOVALUE);


    // Create a FIFO queue for filenames
    queueptr thequeue = initqueue();
    addfile("in0.txt", thequeue);

    // Initialize semaphores
    // Create 20 producer threads.
    pthread_t producertid[MAXPRODUCERS]; 
    pthread_attr_t producerattr[MAXPRODUCERS]; 


    int i = 0;
    for(i=0;i<MAXPRODUCERS;++i)
    {
        pthread_attr_init(&producerattr[i]);
        void * args[2];
        args[0] = thequeue;
        args[1] = fifomutex;
        pthread_create(&producertid[i],&producerattr[i],(void *)initproducer,args);
    }
    
    // Create 5 consumer threads.
    pthread_t consumertid[MAXCONSUMERS];
    pthread_attr_t consumerattr[MAXCONSUMERS];

    int j = 0;
    for(j=0;j<MAXCONSUMERS;++j)
    {
        pthread_attr_init(&consumerattr[j]);
        pthread_create(&consumertid[j],&consumerattr[j],(void *)initconsumer,NULL);
    }

    // Join all threads
    int k = 0;
    for(k=0;k<MAXPRODUCERS;++k)
    {
        pthread_join(producertid[k], NULL);
    }
    int l = 0;
    for(l=0;l<MAXCONSUMERS;++l)
    {
        pthread_join(consumertid[l], NULL);
    }



}


