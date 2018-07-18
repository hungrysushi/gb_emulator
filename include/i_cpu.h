#pragma once

#include <cstdint>

class ICPU {
public:
        ICPU() {}
        virtual ~ICPU() {}

        virtual void nop(uint8_t* operands) = 0;
        virtual void jp_nn(uint8_t* operands) = 0;
        virtual void cp_n(uint8_t* operands) = 0;
};
