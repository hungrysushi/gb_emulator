#include "cpu.h"

#include <iostream>
#include <iomanip>

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

bool CPU::HandleOpcode(const uint8_t opcode) {

        switch (opcode) {
                default:
                        std::cout << "Unimplemented instruction: "
                                  << std::setfill('0')
                                  << std::setw(2)
                                  << std::hex
                                  << (uint32_t) opcode << std::endl;
                        return false;
                        break;
        }

        return true;
}
