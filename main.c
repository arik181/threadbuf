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
    pthread_mutex_init(&fifomutex);

    // Initialize semaphores
    sem_t consumersemaphore;
    sem_t producersemaphore;

    seminit(consumersemaphore, 0, 0);
    seminit(producersemaphore, 0, 0);

    consumersemaphore = sem_open("consumer","r+",INITIALSEMVALUE)
    producersemaphore = sem_open("producer","r+",INITIALSEMVALUE)

    // Create 20 producer threads.
    pthread_t producertid[MAXPRODUCERS]; 
    pthread_attr_t producerattr[MAXPRODUCERS]; 


    pthread_attr_init(&producerattr[i]);
    pthread_create(&producertid[i],&producerattr[i],produce);
    
    // Create 5 consumer threads.
    pthread_t consumertid[MAXCONSUMERS];
    pthread_attr_t consumerattr[MAXCONSUMERS];

    pthread_attr_init(&consumerattr[j]);
    pthread_create(&consumertid[j],&consumerattr[j],consume);

    // Join all threads
    pthread_join(producertid, NULL);
    pthread_join(consumertid, NULL);
}


