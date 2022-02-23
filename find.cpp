#include "find_file.h"

int main(int argc, char* argv[])
{
    std::string path = "/";
    std::string filename = argv[1];
    search(path, filename);
}
