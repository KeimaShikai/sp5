#include <sys/wait.h>
#include <unistd.h>
#include <iostream>

int main(int argc, char* argv[])
{
    pid_t pPid;
    std::string sAddress = argv[1];
    for (int i = atoi(argv[2]); i <= atoi(argv[3]); ++i)
    {
        pPid = fork();
        std::cout << "\nPID of the process is " << getpid() << std::endl;
        if (pPid == 0)
        {
            execl("./p1", "./p1", (sAddress + '.' + std::to_string(i)).c_str(), NULL);
            std::cout << std::endl;
            return 0;
        }
        else
        {
            wait(0);
        } 
    }    
    return 0;
}
