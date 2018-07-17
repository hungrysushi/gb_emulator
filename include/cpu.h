#pragma once

#include <algorithm>
#include <vector>

#include "i_cpu.h"
#include "opcode.h"
#include "registers.h"


class CPU : ICPU {
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
        void nop(uint8_t* operands) override;

        Registers registers_;
};

