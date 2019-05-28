#include <string>

int main(int argc, const char *argv[])
{
    std::string sAddress = argv[1];
    system(("ping -c 1 " + sAddress).c_str());
    return 0;
}
