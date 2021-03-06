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

                if (!HandleOpcode(opcode, rom_data)) {
                        break;
                }
        }
}

bool CPU::HandleOpcode(const uint8_t opcode_byte, const std::vector<uint8_t>& rom_data) {

        int opcode_index = GetOpcodeIndex(opcode_byte);
        OpcodeInfo opcode = kOpcodes[opcode_index];

        if (opcode.opcode_ != Opcode::UNIMPL) {

                // TODO execute opcode function
                // opcode function will handle updating PC and registers
                
                uint8_t *operands = new uint8_t[opcode.num_operands_];
                auto begin_operands = rom_data.begin() + registers_.ProgramCounter() + 1;
                std::copy(begin_operands, begin_operands + opcode.num_operands_, operands);
                
                opcode.function_(operands, this);

                delete[] operands;
                return true;
        } else {

                std::cout << "Unimplemented instruction: "
                        << std::setfill('0')
                        << std::setw(2)
                        << std::hex
                        << (uint32_t) opcode.opcode_byte_ << std::endl;

                return false;
        }

        return true;
}

void CPU::nop(uint8_t* operands) {
        // nop does nothing
        std::cout << "NOP" << std::endl;

        registers_.ProgramCounter() ++;
}

// 0xc3 nn nn
void CPU::jp_nn(uint8_t* operands) {
        std::cout << "JP_NN" << std::endl;

        // lower byte is read first
        uint16_t new_pc = (uint16_t) operands[0] | (operands[1] << 8);

        registers_.ProgramCounter() = new_pc;
}

// 0xfe nn
void CPU::cp_n(uint8_t* operands) {
        std::cout << "CP_N" << std::endl;

        uint16_t compare_val = (uint16_t) registers_.A() - operands[0];

        if (compare_val == 0) {
                registers_.SetZeroFlag();
        } else {
                registers_.ClearZeroFlag();
        }

        registers_.SetAddSubFlag();

        // half carry flag
        // if lower nibble of A is less than lower nibble of operand, then a carry must have occurred
        if ((registers_.A() & 0x0f ) < (operands[0] & 0x0f)) {
                registers_.SetHalfCarryFlag();
        } else {
                registers_.ClearHalfCarryFlag();
        }

        if (registers_.A() < operands[0]) {
                registers_.SetCarryFlag();
        } else {
                registers_.ClearCarryFlag();
        }

        registers_.ProgramCounter() += 2;
}
