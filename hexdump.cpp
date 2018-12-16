// HexDump - A utility to dump the contents of a file in 
//           a binary format
// Written by Eric D. Bailey
// Copyright (c)2018 Eric D. Bailey

#include <iostream>
#include <fstream>
#include "hexdump.hpp"

const int BufferSize = 4096;    // Buffer size we'll use to read chunks into

int main(int argc, char *argv[])
{
    // Make sure we have enough arguments
    if (argc < 2)
    {
        std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
        return -1;
    }

    // Open the file for binary read
    std::ifstream file(argv[1], std::ios::binary);
    if (file.is_open())
    {
        // We'll use only a 4k buffer to keep memory usage low
        char *buffer = new char[BufferSize];
        std::size_t offset = 0;

        // Read through the file until the end
        while (!file.eof())
        {
            file.read(buffer, BufferSize);  // Read our buffer size in bytes from the file
            PsiborgLib::hex_dump(buffer, file.gcount(), std::cout, offset);
            offset += file.gcount();    // Keep adding to the offset
        }
        
        file.close();   // Make sure to close the file
    }

    return 0;
}

