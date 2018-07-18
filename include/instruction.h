#pragma once

#include "i_cpu.h"

struct Instruction {

};

typedef void (*OpFunction)(uint8_t* operands, ICPU* cpu);

static void nop(uint8_t* operands, ICPU* cpu) {
        cpu->nop(operands);
}

static void jp_nn(uint8_t* operands, ICPU* cpu) {
        cpu->jp_nn(operands);
}

static void cp_n(uint8_t* operands, ICPU* cpu) {
        cpu->cp_n(operands);
}
