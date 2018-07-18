#pragma once

#include <cstdint>

constexpr int kZeroFlagBit = 7;
constexpr int kAddSubFlagBit = 6;
constexpr int kHalfCarryFlagBit = 5;
constexpr int kCarryFlagBit = 4;

class Registers {
public:
        Registers() { }
        ~Registers() { }

        uint16_t& AF() { return *((uint16_t*) af_); }
        uint16_t& BC() { return *((uint16_t*) bc_); }
        uint16_t& DE() { return *((uint16_t*) de_); }
        uint16_t& HL() { return *((uint16_t*) hl_); }
        uint16_t& StackPointer() { return sp_; }
        uint16_t& ProgramCounter() { return pc_; }

        // first index is the "high" byte, second is the "low" byte
        uint8_t& Flags() { return af_[1]; }
        uint8_t& A() { return af_[0]; } 
        uint8_t& B() { return bc_[0]; }
        uint8_t& C() { return bc_[1]; }
        uint8_t& D() { return de_[0]; }
        uint8_t& E() { return de_[1]; }
        uint8_t& H() { return hl_[0]; }
        uint8_t& L() { return hl_[1]; }

        // set/clear flags individually
        void SetZeroFlag() { af_[1] |= (0x1 << kZeroFlagBit); }
        void ClearZeroFlag() { af_[1] &= ~(0x1 << kZeroFlagBit); }
        void SetAddSubFlag() { af_[1] |= (0x1 << kAddSubFlagBit); }
        void ClearAddSubFlag() { af_[1] &= ~(0x1 << kAddSubFlagBit); }
        void SetHalfCarryFlag() { af_[1] |= (0x1 << kHalfCarryFlagBit); }
        void ClearHalfCarryFlag() { af_[1] &= ~(0x1 << kHalfCarryFlagBit); }
        void SetCarryFlag() { af_[1] |= (0x1 << kCarryFlagBit); }
        void ClearCarryFlag() { af_[1] &= ~(0x1 << kCarryFlagBit); }

private:
        uint8_t af_[2] = { 0x00 };
        uint8_t bc_[2] = { 0x00 };
        uint8_t de_[2] = { 0x00 };
        uint8_t hl_[2] = { 0x00 };

        uint16_t sp_ = 0x0000;
        uint16_t pc_ = 0x0000;
};
