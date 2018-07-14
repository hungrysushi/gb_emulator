#include "cpu.h"

#include <iostream>

CPU::CPU() {

}

void CPU::Run() {

        std::cout << "Launching rom..." << std::endl;

        Bootstrap();
}

void CPU::Bootstrap() {


}


//------------------------------------------------------------------------------
/**
 * These functions do the actual operations for various opcodes
 */

// 0x00 nop
static void Nop(uint8_t* operands_, CPU& cpu) {
        // do nothing
}

static const std::map<uint8_t, OpcodeFunction> kFunctionMap = {

        {0x00, &Nop},

};
