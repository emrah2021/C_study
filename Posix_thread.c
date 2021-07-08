#include <stdio.h>
#include <pthread.h>

int counter = 0;

pthread_mutex_t lock;

void* thread_func(void* arg)
{
    pthread_mutex_lock(&lock);
    ++counter;
    printf("Job %d has started\n", counter);
    
    for(int i = 0; i<1000000; i++)
        ;
        
    printf("Job %d has finished\n", counter);
    pthread_mutex_unlock(&lock);
    
    return NULL;
}

int main()
{
    pthread_t p1; 
    pthread_t p2;
    
    pthread_mutex_init(&lock, NULL);
    
    pthread_create(&p1, NULL, &thread_func, NULL);
    pthread_create(&p2, NULL, &thread_func, NULL);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    
    pthread_mutex_destroy(&lock);

    return 0;
}
