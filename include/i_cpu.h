#pragma once

#include <cstdint>

class ICPU {
public:
        ICPU() {}
        virtual ~ICPU() {}

        virtual void nop(uint8_t* operands) = 0;
};
