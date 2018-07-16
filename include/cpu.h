#pragma once

#include <algorithm>
#include <vector>

#include "opcode.h"
#include "registers.h"

/**
 * find the opcode info index for debugging
 */
static constexpr int GetOpcodeIndex(uint8_t opcode_byte) {
        for (uint32_t i = 0; i < kOpcodesSize; i++) {
                if (kOpcodes[i].opcode_byte == opcode_byte) {
                        return i;
                }
        }

        return -1;
}

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

