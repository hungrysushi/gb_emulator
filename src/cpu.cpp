#include "cpu.h"

#include <iostream>
#include <iomanip>

#include "instruction.h"

CPU::CPU() {

        Bootstrap();
}

void CPU::Bootstrap() {

        // TODO
        registers_.ProgramCounter() = 0x100;
}

void CPU::Run(const std::vector<uint8_t>& rom_data, const uint32_t size) {

        std::cout << "Launching rom..." << std::endl;

        // read instructions from buffer
        while (registers_.ProgramCounter() != size) {

                // read an opcode byte
                uint8_t opcode = rom_data[registers_.ProgramCounter()];

                if (!HandleOpcode(opcode)) {
                        break;
                }
        }
}

bool CPU::HandleOpcode(const uint8_t opcode_byte) {

        int opcode_index = GetOpcodeIndex(opcode_byte);

        if (opcode_index != -1) {
                OpcodeInfo opcode = kOpcodes[opcode_index];

                // TODO execute opcode function
                // opcode function will handle updating PC and registers
                
                opcode.function_(nullptr, this);
                
                return false;
        } else {

                std::cout << "Unimplemented instruction: "
                        << std::setfill('0')
                        << std::setw(2)
                        << std::hex
                        << (uint32_t) opcode_byte << std::endl;

                return false;
        }

        return true;
}

void CPU::nop(uint8_t* operands) {
        // nop does nothing
        std::cout << "NOP" << std::endl;

        registers_.ProgramCounter() ++;
}
