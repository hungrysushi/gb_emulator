#pragma once

#include <map>

enum class Opcode {
        NOP,
};

struct OpcodeInfo {
        Opcode opcode_;
        uint8_t num_operands;
};

static const std::map<uint8_t, OpcodeInfo> kOpcodeMap = {

        {0x00, {Opcode::NOP, 0}},

};

