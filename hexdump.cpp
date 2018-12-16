// HexDump - A utility to dump the contents of a file in 
//           a binary format

#include <iostream>
#include <fstream>
#include "hexdump.hpp"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
        return -1;
    }

    std::ifstream file(argv[1], std::ios::binary);
    if (file.is_open())
    {
        char *buffer = new char[4096];
        std::size_t offset = 0;
        while (!file.eof())
        {
            file.read(buffer, 4096);
            PsiborgLib::hex_dump(buffer, file.gcount(), std::cout, offset);
            offset += file.gcount();
        }
        file.close();
    }

    return 0;
}

