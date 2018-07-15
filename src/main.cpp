
#include <iostream>
#include <string>

#include "cpu.h"
#include "rom.h"

int main(int argc, char** argv)
{
        if (argc < 2) {
                std::cout << "Please enter a filename" << std::endl;
                return 0;
        }

        std::string filename(argv[1]);

        Rom rom(filename);
        std::cout << rom.title_ << std::endl;

        // header bytes
        rom.PrintBytes(0x100, 0x14F);
        
        // first few instructions
        rom.PrintBytes(0x150, 0x200);

        CPU cpu;
        cpu.Run(rom.buffer_, rom.size_);

        return 0;
}
