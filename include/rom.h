#pragma once

#include <string>

class Rom {
public:
        Rom(const std::string& filename);
        ~Rom();

        uint8_t* LoadRom(const std::string& filename);
        void ParseHeader();
        void ParseTitle();
        void PrintBytes(const uint32_t start, const uint32_t end);

        const uint8_t *buffer_ = nullptr;
        int32_t size_;
        
        /*
         * Info and flags from the rom header
         */
        std::string title_;
};
