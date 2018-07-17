#pragma once

#include "i_cpu.h"

struct Instruction {

};

typedef void (*OpFunction)(uint8_t* operands, ICPU* cpu);

static void nop(uint8_t* operands, ICPU* cpu) {
        cpu->nop(operands);
}
