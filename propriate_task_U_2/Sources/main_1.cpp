#include <pthread.h>
#include <iostream>

typedef struct argumenst_for_thread
{
    std::string sAddress;
    int iBegin;
    int iEnd;
} args;

void* ping(void* data)
{
    args *arg = (args*) data;
    for (int i = arg->iBegin; i <= arg->iEnd; ++i)
    {
        system(("ping -c 1 " + (arg->sAddress + '.' + std::to_string(i))).c_str());
    }
    return NULL;
}

int main(int argc, const char *argv[])
{
    args aArgs = {argv[1], atoi(argv[2]), atoi(argv[3])}; 
    pthread_t ptThread;
    std::cout << "Let's get started!\n";
    pthread_create(&ptThread, NULL, ping, &aArgs);
    pthread_join(ptThread, NULL);
    std::cout << "He's dead now!\n";
    return 0;
}
