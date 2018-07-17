#pragma once

#include <map>

#include "instruction.h"

enum class Opcode {
        NOP,
        LD_BC_NN,
        LD_BC_A,
        LD_DE_NN,
        LD_HL_NN,
        LD_SP_NN,
        STOP,

        UNIMPLEMENTED,
};

struct OpcodeInfo {
        uint8_t opcode_byte = 0x00;
        Opcode opcode_ = Opcode::UNIMPLEMENTED;
        uint8_t num_operands_ = 0;
        OpFunction function_ = nullptr;
};


/**
 * The static functions pointed to in the struct take the operands and a CPU
 * reference, and then call a method by the same name in the CPU. This was
 * a roundabout way of being able to look up everything needed for an opcode
 * from a static table. Testing may be needed if performance becomes and issue.
 */
static constexpr OpcodeInfo kOpcodes[] = {

        {    0x00,     Opcode::NOP,        0,        &nop      },
        {    0x01,     Opcode::LD_BC_NN,   0,        &nop      },
        {    0x10,     Opcode::STOP,       0,        nullptr   },

};

static constexpr int kOpcodesSize = sizeof(kOpcodes) / sizeof(OpcodeInfo);

/**
 * find the opcode info index
 */
static constexpr int GetOpcodeIndex(uint8_t opcode_byte) {
        for (uint32_t i = 0; i < kOpcodesSize; i++) {
                if (kOpcodes[i].opcode_byte == opcode_byte) {
                        return i;
                }
        }

        return -1;
}

