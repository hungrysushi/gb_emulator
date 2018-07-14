
#include <iostream>
#include <string>

#include "rom.h"

int main(int argc, char** argv)
{
        if (argc < 2) {
                std::cout << "Please enter a filename" << std::endl;
                return 0;
        }

        std::string filename(argv[1]);

        Rom rom(filename);

        // header bytes
        /* rom.PrintBytes(0x100, 0x14F); */
        
        // first few instructions
        rom.PrintBytes(0x150, 0x200);

        return 0;
}
