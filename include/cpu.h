#pragma once

#include <vector>

#include "registers.h"

class CPU {
public:
        CPU();
        ~CPU() { }

        void Bootstrap();
        void Run(const std::vector<uint8_t>& rom_data, const uint32_t size);
        bool HandleOpcode(const uint8_t opcode);

        /**
         * these are the functions to run the opcodes
         */
        //TODO

        Registers registers_;
};

