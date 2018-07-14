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

