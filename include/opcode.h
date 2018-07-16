#pragma once

#include <map>

enum class Opcode {
        NOP,
        STOP,

        UNIMPLEMENTED,
};

struct OpcodeInfo {
        uint8_t opcode_byte = 0x00;
        Opcode opcode_ = Opcode::UNIMPLEMENTED;
        uint8_t num_operands = 0;
};


static constexpr OpcodeInfo kOpcodes[] = {

        {0x00, Opcode::NOP, 0},
        {0x10, Opcode::STOP, 0},

};

static constexpr int kOpcodesSize = sizeof(kOpcodes) / sizeof(OpcodeInfo);
