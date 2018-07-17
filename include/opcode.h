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

        UNIMPL,
};

struct OpcodeInfo {
        uint8_t opcode_byte_ = 0x00;
        Opcode opcode_ = Opcode::UNIMPL;
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
        {    0x02,     Opcode::UNIMPL,     0,        &nop      },
        {    0x03,     Opcode::UNIMPL,     0,        &nop      },
        {    0x04,     Opcode::UNIMPL,     0,        &nop      },
        {    0x05,     Opcode::UNIMPL,     0,        &nop      },
        {    0x06,     Opcode::UNIMPL,     0,        &nop      },
        {    0x07,     Opcode::UNIMPL,     0,        &nop      },
        {    0x08,     Opcode::UNIMPL,     0,        &nop      },
        {    0x09,     Opcode::UNIMPL,     0,        &nop      },
        {    0x0A,     Opcode::UNIMPL,     0,        &nop      },
        {    0x0B,     Opcode::UNIMPL,     0,        &nop      },
        {    0x0C,     Opcode::UNIMPL,     0,        &nop      },
        {    0x0D,     Opcode::UNIMPL,     0,        &nop      },
        {    0x0E,     Opcode::UNIMPL,     0,        &nop      },
        {    0x0F,     Opcode::UNIMPL,     0,        &nop      },

        /* 0x1X codes */
        {    0x10,     Opcode::STOP,       0,        nullptr   },
        {    0x11,     Opcode::UNIMPL,     0,        &nop      },
        {    0x12,     Opcode::UNIMPL,     0,        &nop      },
        {    0x13,     Opcode::UNIMPL,     0,        &nop      },
        {    0x14,     Opcode::UNIMPL,     0,        &nop      },
        {    0x15,     Opcode::UNIMPL,     0,        &nop      },
        {    0x16,     Opcode::UNIMPL,     0,        &nop      },
        {    0x17,     Opcode::UNIMPL,     0,        &nop      },
        {    0x18,     Opcode::UNIMPL,     0,        &nop      },
        {    0x19,     Opcode::UNIMPL,     0,        &nop      },
        {    0x1A,     Opcode::UNIMPL,     0,        &nop      },
        {    0x1B,     Opcode::UNIMPL,     0,        &nop      },
        {    0x1C,     Opcode::UNIMPL,     0,        &nop      },
        {    0x1D,     Opcode::UNIMPL,     0,        &nop      },
        {    0x1E,     Opcode::UNIMPL,     0,        &nop      },
        {    0x1F,     Opcode::UNIMPL,     0,        &nop      },

        /* 0x2X codes */
        {    0x20,     Opcode::UNIMPL,     0,        &nop      },
        {    0x21,     Opcode::UNIMPL,     0,        &nop      },
        {    0x22,     Opcode::UNIMPL,     0,        &nop      },
        {    0x23,     Opcode::UNIMPL,     0,        &nop      },
        {    0x24,     Opcode::UNIMPL,     0,        &nop      },
        {    0x25,     Opcode::UNIMPL,     0,        &nop      },
        {    0x26,     Opcode::UNIMPL,     0,        &nop      },
        {    0x27,     Opcode::UNIMPL,     0,        &nop      },
        {    0x28,     Opcode::UNIMPL,     0,        &nop      },
        {    0x29,     Opcode::UNIMPL,     0,        &nop      },
        {    0x2A,     Opcode::UNIMPL,     0,        &nop      },
        {    0x2B,     Opcode::UNIMPL,     0,        &nop      },
        {    0x2C,     Opcode::UNIMPL,     0,        &nop      },
        {    0x2D,     Opcode::UNIMPL,     0,        &nop      },
        {    0x2E,     Opcode::UNIMPL,     0,        &nop      },
        {    0x2F,     Opcode::UNIMPL,     0,        &nop      },

        /* 0x3X codes */
        {    0x30,     Opcode::UNIMPL,     0,        &nop      },
        {    0x31,     Opcode::UNIMPL,     0,        &nop      },
        {    0x32,     Opcode::UNIMPL,     0,        &nop      },
        {    0x33,     Opcode::UNIMPL,     0,        &nop      },
        {    0x34,     Opcode::UNIMPL,     0,        &nop      },
        {    0x35,     Opcode::UNIMPL,     0,        &nop      },
        {    0x36,     Opcode::UNIMPL,     0,        &nop      },
        {    0x37,     Opcode::UNIMPL,     0,        &nop      },
        {    0x38,     Opcode::UNIMPL,     0,        &nop      },
        {    0x39,     Opcode::UNIMPL,     0,        &nop      },
        {    0x3A,     Opcode::UNIMPL,     0,        &nop      },
        {    0x3B,     Opcode::UNIMPL,     0,        &nop      },
        {    0x3C,     Opcode::UNIMPL,     0,        &nop      },
        {    0x3D,     Opcode::UNIMPL,     0,        &nop      },
        {    0x3E,     Opcode::UNIMPL,     0,        &nop      },
        {    0x3F,     Opcode::UNIMPL,     0,        &nop      },

        /* 0x4X codes */
        {    0x40,     Opcode::UNIMPL,     0,        &nop      },
        {    0x41,     Opcode::UNIMPL,     0,        &nop      },
        {    0x42,     Opcode::UNIMPL,     0,        &nop      },
        {    0x43,     Opcode::UNIMPL,     0,        &nop      },
        {    0x44,     Opcode::UNIMPL,     0,        &nop      },
        {    0x45,     Opcode::UNIMPL,     0,        &nop      },
        {    0x46,     Opcode::UNIMPL,     0,        &nop      },
        {    0x47,     Opcode::UNIMPL,     0,        &nop      },
        {    0x48,     Opcode::UNIMPL,     0,        &nop      },
        {    0x49,     Opcode::UNIMPL,     0,        &nop      },
        {    0x4A,     Opcode::UNIMPL,     0,        &nop      },
        {    0x4B,     Opcode::UNIMPL,     0,        &nop      },
        {    0x4C,     Opcode::UNIMPL,     0,        &nop      },
        {    0x4D,     Opcode::UNIMPL,     0,        &nop      },
        {    0x4E,     Opcode::UNIMPL,     0,        &nop      },
        {    0x4F,     Opcode::UNIMPL,     0,        &nop      },

        /* 0x5X codes */
        {    0x50,     Opcode::UNIMPL,     0,        &nop      },
        {    0x51,     Opcode::UNIMPL,     0,        &nop      },
        {    0x52,     Opcode::UNIMPL,     0,        &nop      },
        {    0x53,     Opcode::UNIMPL,     0,        &nop      },
        {    0x54,     Opcode::UNIMPL,     0,        &nop      },
        {    0x55,     Opcode::UNIMPL,     0,        &nop      },
        {    0x56,     Opcode::UNIMPL,     0,        &nop      },
        {    0x57,     Opcode::UNIMPL,     0,        &nop      },
        {    0x58,     Opcode::UNIMPL,     0,        &nop      },
        {    0x59,     Opcode::UNIMPL,     0,        &nop      },
        {    0x5A,     Opcode::UNIMPL,     0,        &nop      },
        {    0x5B,     Opcode::UNIMPL,     0,        &nop      },
        {    0x5C,     Opcode::UNIMPL,     0,        &nop      },
        {    0x5D,     Opcode::UNIMPL,     0,        &nop      },
        {    0x5E,     Opcode::UNIMPL,     0,        &nop      },
        {    0x5F,     Opcode::UNIMPL,     0,        &nop      },

        /* 0x6X codes */
        {    0x60,     Opcode::UNIMPL,     0,        &nop      },
        {    0x61,     Opcode::UNIMPL,     0,        &nop      },
        {    0x62,     Opcode::UNIMPL,     0,        &nop      },
        {    0x63,     Opcode::UNIMPL,     0,        &nop      },
        {    0x64,     Opcode::UNIMPL,     0,        &nop      },
        {    0x65,     Opcode::UNIMPL,     0,        &nop      },
        {    0x66,     Opcode::UNIMPL,     0,        &nop      },
        {    0x67,     Opcode::UNIMPL,     0,        &nop      },
        {    0x68,     Opcode::UNIMPL,     0,        &nop      },
        {    0x69,     Opcode::UNIMPL,     0,        &nop      },
        {    0x6A,     Opcode::UNIMPL,     0,        &nop      },
        {    0x6B,     Opcode::UNIMPL,     0,        &nop      },
        {    0x6C,     Opcode::UNIMPL,     0,        &nop      },
        {    0x6D,     Opcode::UNIMPL,     0,        &nop      },
        {    0x6E,     Opcode::UNIMPL,     0,        &nop      },
        {    0x6F,     Opcode::UNIMPL,     0,        &nop      },

        /* 0x7X codes */
        {    0x70,     Opcode::UNIMPL,     0,        &nop      },
        {    0x71,     Opcode::UNIMPL,     0,        &nop      },
        {    0x72,     Opcode::UNIMPL,     0,        &nop      },
        {    0x73,     Opcode::UNIMPL,     0,        &nop      },
        {    0x74,     Opcode::UNIMPL,     0,        &nop      },
        {    0x75,     Opcode::UNIMPL,     0,        &nop      },
        {    0x76,     Opcode::UNIMPL,     0,        &nop      },
        {    0x77,     Opcode::UNIMPL,     0,        &nop      },
        {    0x78,     Opcode::UNIMPL,     0,        &nop      },
        {    0x79,     Opcode::UNIMPL,     0,        &nop      },
        {    0x7A,     Opcode::UNIMPL,     0,        &nop      },
        {    0x7B,     Opcode::UNIMPL,     0,        &nop      },
        {    0x7C,     Opcode::UNIMPL,     0,        &nop      },
        {    0x7D,     Opcode::UNIMPL,     0,        &nop      },
        {    0x7E,     Opcode::UNIMPL,     0,        &nop      },
        {    0x7F,     Opcode::UNIMPL,     0,        &nop      },

        /* 0x8X codes */
        {    0x80,     Opcode::UNIMPL,     0,        &nop      },
        {    0x81,     Opcode::UNIMPL,     0,        &nop      },
        {    0x82,     Opcode::UNIMPL,     0,        &nop      },
        {    0x83,     Opcode::UNIMPL,     0,        &nop      },
        {    0x84,     Opcode::UNIMPL,     0,        &nop      },
        {    0x85,     Opcode::UNIMPL,     0,        &nop      },
        {    0x86,     Opcode::UNIMPL,     0,        &nop      },
        {    0x87,     Opcode::UNIMPL,     0,        &nop      },
        {    0x88,     Opcode::UNIMPL,     0,        &nop      },
        {    0x89,     Opcode::UNIMPL,     0,        &nop      },
        {    0x8A,     Opcode::UNIMPL,     0,        &nop      },
        {    0x8B,     Opcode::UNIMPL,     0,        &nop      },
        {    0x8C,     Opcode::UNIMPL,     0,        &nop      },
        {    0x8D,     Opcode::UNIMPL,     0,        &nop      },
        {    0x8E,     Opcode::UNIMPL,     0,        &nop      },
        {    0x8F,     Opcode::UNIMPL,     0,        &nop      },

        /* 0x9X codes */
        {    0x90,     Opcode::UNIMPL,     0,        &nop      },
        {    0x91,     Opcode::UNIMPL,     0,        &nop      },
        {    0x92,     Opcode::UNIMPL,     0,        &nop      },
        {    0x93,     Opcode::UNIMPL,     0,        &nop      },
        {    0x94,     Opcode::UNIMPL,     0,        &nop      },
        {    0x95,     Opcode::UNIMPL,     0,        &nop      },
        {    0x96,     Opcode::UNIMPL,     0,        &nop      },
        {    0x97,     Opcode::UNIMPL,     0,        &nop      },
        {    0x98,     Opcode::UNIMPL,     0,        &nop      },
        {    0x99,     Opcode::UNIMPL,     0,        &nop      },
        {    0x9A,     Opcode::UNIMPL,     0,        &nop      },
        {    0x9B,     Opcode::UNIMPL,     0,        &nop      },
        {    0x9C,     Opcode::UNIMPL,     0,        &nop      },
        {    0x9D,     Opcode::UNIMPL,     0,        &nop      },
        {    0x9E,     Opcode::UNIMPL,     0,        &nop      },
        {    0x9F,     Opcode::UNIMPL,     0,        &nop      },

        /* 0xAX codes */
        {    0xA0,     Opcode::UNIMPL,     0,        &nop      },
        {    0xA1,     Opcode::UNIMPL,     0,        &nop      },
        {    0xA2,     Opcode::UNIMPL,     0,        &nop      },
        {    0xA3,     Opcode::UNIMPL,     0,        &nop      },
        {    0xA4,     Opcode::UNIMPL,     0,        &nop      },
        {    0xA5,     Opcode::UNIMPL,     0,        &nop      },
        {    0xA6,     Opcode::UNIMPL,     0,        &nop      },
        {    0xA7,     Opcode::UNIMPL,     0,        &nop      },
        {    0xA8,     Opcode::UNIMPL,     0,        &nop      },
        {    0xA9,     Opcode::UNIMPL,     0,        &nop      },
        {    0xAA,     Opcode::UNIMPL,     0,        &nop      },
        {    0xAB,     Opcode::UNIMPL,     0,        &nop      },
        {    0xAC,     Opcode::UNIMPL,     0,        &nop      },
        {    0xAD,     Opcode::UNIMPL,     0,        &nop      },
        {    0xAE,     Opcode::UNIMPL,     0,        &nop      },
        {    0xAF,     Opcode::UNIMPL,     0,        &nop      },

        /* 0xBX codes */
        {    0xB0,     Opcode::UNIMPL,     0,        &nop      },
        {    0xB1,     Opcode::UNIMPL,     0,        &nop      },
        {    0xB2,     Opcode::UNIMPL,     0,        &nop      },
        {    0xB3,     Opcode::UNIMPL,     0,        &nop      },
        {    0xB4,     Opcode::UNIMPL,     0,        &nop      },
        {    0xB5,     Opcode::UNIMPL,     0,        &nop      },
        {    0xB6,     Opcode::UNIMPL,     0,        &nop      },
        {    0xB7,     Opcode::UNIMPL,     0,        &nop      },
        {    0xB8,     Opcode::UNIMPL,     0,        &nop      },
        {    0xB9,     Opcode::UNIMPL,     0,        &nop      },
        {    0xBA,     Opcode::UNIMPL,     0,        &nop      },
        {    0xBB,     Opcode::UNIMPL,     0,        &nop      },
        {    0xBC,     Opcode::UNIMPL,     0,        &nop      },
        {    0xBD,     Opcode::UNIMPL,     0,        &nop      },
        {    0xBE,     Opcode::UNIMPL,     0,        &nop      },
        {    0xBF,     Opcode::UNIMPL,     0,        &nop      },

        /* 0xCX codes */
        {    0xC0,     Opcode::UNIMPL,     0,        &nop      },
        {    0xC1,     Opcode::UNIMPL,     0,        &nop      },
        {    0xC2,     Opcode::UNIMPL,     0,        &nop      },
        {    0xC3,     Opcode::UNIMPL,     0,        &nop      },
        {    0xC4,     Opcode::UNIMPL,     0,        &nop      },
        {    0xC5,     Opcode::UNIMPL,     0,        &nop      },
        {    0xC6,     Opcode::UNIMPL,     0,        &nop      },
        {    0xC7,     Opcode::UNIMPL,     0,        &nop      },
        {    0xC8,     Opcode::UNIMPL,     0,        &nop      },
        {    0xC9,     Opcode::UNIMPL,     0,        &nop      },
        {    0xCA,     Opcode::UNIMPL,     0,        &nop      },
        {    0xCB,     Opcode::UNIMPL,     0,        &nop      },
        {    0xCC,     Opcode::UNIMPL,     0,        &nop      },
        {    0xCD,     Opcode::UNIMPL,     0,        &nop      },
        {    0xCE,     Opcode::UNIMPL,     0,        &nop      },
        {    0xCF,     Opcode::UNIMPL,     0,        &nop      },

        /* 0xDX codes */
        {    0xD0,     Opcode::UNIMPL,     0,        &nop      },
        {    0xD1,     Opcode::UNIMPL,     0,        &nop      },
        {    0xD2,     Opcode::UNIMPL,     0,        &nop      },
        {    0xD3,     Opcode::UNIMPL,     0,        &nop      },
        {    0xD4,     Opcode::UNIMPL,     0,        &nop      },
        {    0xD5,     Opcode::UNIMPL,     0,        &nop      },
        {    0xD6,     Opcode::UNIMPL,     0,        &nop      },
        {    0xD7,     Opcode::UNIMPL,     0,        &nop      },
        {    0xD8,     Opcode::UNIMPL,     0,        &nop      },
        {    0xD9,     Opcode::UNIMPL,     0,        &nop      },
        {    0xDA,     Opcode::UNIMPL,     0,        &nop      },
        {    0xDB,     Opcode::UNIMPL,     0,        &nop      },
        {    0xDC,     Opcode::UNIMPL,     0,        &nop      },
        {    0xDD,     Opcode::UNIMPL,     0,        &nop      },
        {    0xDE,     Opcode::UNIMPL,     0,        &nop      },
        {    0xDF,     Opcode::UNIMPL,     0,        &nop      },

        /* 0xEX codes */
        {    0xE0,     Opcode::UNIMPL,     0,        &nop      },
        {    0xE1,     Opcode::UNIMPL,     0,        &nop      },
        {    0xE2,     Opcode::UNIMPL,     0,        &nop      },
        {    0xE3,     Opcode::UNIMPL,     0,        &nop      },
        {    0xE4,     Opcode::UNIMPL,     0,        &nop      },
        {    0xE5,     Opcode::UNIMPL,     0,        &nop      },
        {    0xE6,     Opcode::UNIMPL,     0,        &nop      },
        {    0xE7,     Opcode::UNIMPL,     0,        &nop      },
        {    0xE8,     Opcode::UNIMPL,     0,        &nop      },
        {    0xE9,     Opcode::UNIMPL,     0,        &nop      },
        {    0xEA,     Opcode::UNIMPL,     0,        &nop      },
        {    0xEB,     Opcode::UNIMPL,     0,        &nop      },
        {    0xEC,     Opcode::UNIMPL,     0,        &nop      },
        {    0xED,     Opcode::UNIMPL,     0,        &nop      },
        {    0xEE,     Opcode::UNIMPL,     0,        &nop      },
        {    0xEF,     Opcode::UNIMPL,     0,        &nop      },

        /* 0xFX codes */
        {    0xF0,     Opcode::UNIMPL,     0,        &nop      },
        {    0xF1,     Opcode::UNIMPL,     0,        &nop      },
        {    0xF2,     Opcode::UNIMPL,     0,        &nop      },
        {    0xF3,     Opcode::UNIMPL,     0,        &nop      },
        {    0xF4,     Opcode::UNIMPL,     0,        &nop      },
        {    0xF5,     Opcode::UNIMPL,     0,        &nop      },
        {    0xF6,     Opcode::UNIMPL,     0,        &nop      },
        {    0xF7,     Opcode::UNIMPL,     0,        &nop      },
        {    0xF8,     Opcode::UNIMPL,     0,        &nop      },
        {    0xF9,     Opcode::UNIMPL,     0,        &nop      },
        {    0xFA,     Opcode::UNIMPL,     0,        &nop      },
        {    0xFB,     Opcode::UNIMPL,     0,        &nop      },
        {    0xFC,     Opcode::UNIMPL,     0,        &nop      },
        {    0xFD,     Opcode::UNIMPL,     0,        &nop      },
        {    0xFE,     Opcode::UNIMPL,     0,        &nop      },
        {    0xFF,     Opcode::UNIMPL,     0,        &nop      },
};

static constexpr int kOpcodesSize = sizeof(kOpcodes) / sizeof(OpcodeInfo);

/**
 * find the opcode info index
 */
static constexpr int GetOpcodeIndex(uint8_t opcode_byte) {
        for (uint32_t i = 0; i < kOpcodesSize; i++) {
                if (kOpcodes[i].opcode_byte_ == opcode_byte) {
                        return i;
                }
        }

        return -1;
}

