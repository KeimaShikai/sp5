#include <pthread.h>
#include <iostream>

/*********************/
/////Define  block/////
pthread_mutex_t ptMute;
/*********************/

typedef struct argumenst_for_thread
{
    int iNumber;
    int iBegin;
    int iEnd;
} args;

void* ping(void* data)
{
    args *arg = (args*) data;
    for (int i = arg->iBegin; i <= arg->iEnd; ++i)
    {
        //pthread_mutex_lock(&ptMute);
        std::cout << arg->iNumber << " is here!\n";
        system(("ping -c 1 192.168.0." + (std::to_string(i))).c_str());
        //pthread_mutex_unlock(&ptMute);
    }
    return NULL;
}

int main()
{
    pthread_mutex_init(&ptMute, NULL);

    args aArgs[2];
    aArgs[0] = {1, 1, 10};
    aArgs[1] = {2, 11, 20}; 
    
    pthread_t ptThread_1, ptThread_2;
    
    std::cout << "Let's get started!\n";
    
    pthread_create(&ptThread_1, NULL, ping, &aArgs[0]);
    pthread_create(&ptThread_2, NULL, ping, &aArgs[1]);
    
    pthread_join(ptThread_1, NULL);
    pthread_join(ptThread_2, NULL);
    
    std::cout << "We've done here!\n";
    return 0;
}
