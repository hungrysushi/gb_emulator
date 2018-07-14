#pragma once

#include <map>

#include "registers.h"

class CPU {
public:
        CPU();
        ~CPU() { }

        void Run();
        void Bootstrap();

        Registers registers_;
};

typedef void (*OpcodeFunction)(uint8_t* operands, CPU& cpu);

/**
 * static functions for CPU opcodes
 * must match OpcodeFunction signature
 */
static void Nop(uint8_t* operands, CPU& cpu);


