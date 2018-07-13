#include "rom.h"

#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>

#include "types.h"

Rom::Rom(const std::string& filename)
        : buffer_(LoadRom(filename)) {

        // parse header to get title, flags, etc
        ParseHeader();
}

Rom::~Rom() {

        delete[] buffer_;
}

uint8_t* Rom::LoadRom(const std::string& filename) {

        // open file
        std::ifstream rom_file;
        rom_file.unsetf(std::ios::skipws);
        rom_file.exceptions(std::ios::failbit | std::ios::badbit);  // fail if the file cannot be read

        rom_file.open(filename, std::ios::binary);

        // get file length
        rom_file.seekg(0, std::ios::end);
        std::streampos length = rom_file.tellg();
        rom_file.seekg(0, std::ios::beg);

        size_ = (int32_t) length;

        // read whole rom to memory
        uint8_t *rom = new uint8_t[length];
        rom_file.read((char*) rom, length);

        return rom;
}

void Rom::ParseHeader() {
        
        // rom title
        const uint8_t* title_ascii = buffer_ + kRomTitleBegin;
        title_ = std::string(title_ascii, title_ascii + kRomTitleLength);

        // TODO parse other parts of the header
}

// for debugging
void Rom::PrintBytes(const uint32_t start, const uint32_t end) {
        for (uint32_t i = start; i < end; i++) {
                std::cout << std::hex << (uint32_t) buffer_[i] << " ";
        }

        std::cout << std::endl;
}
