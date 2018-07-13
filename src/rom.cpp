#include "rom.h"

#include <fstream>
#include <iostream>
#include <iomanip>
#include <iterator>

#include "types.h"

Rom::Rom(const std::string& filename)
        : buffer_(LoadRom(filename)),
          size_(buffer_.size()),
          title_(ParseTitle()) {

        // we parse as much as we can know from the header in the initializer list
        std::cout << size_ << std::endl;
        std::cout << title_ << std::endl;
}

Rom::~Rom() {

}

std::vector<uint8_t> Rom::LoadRom(const std::string& filename) {

        // open file
        std::ifstream rom_file;
        rom_file.unsetf(std::ios::skipws);
        rom_file.exceptions(std::ios::badbit);  // fail if the file cannot be read

        rom_file.open(filename, std::ios::binary);

        // get file length
        rom_file.seekg(0, std::ios::end);
        std::streampos length = rom_file.tellg();
        rom_file.seekg(0, std::ios::beg);


        // read whole rom to memory
        std::vector<uint8_t> rom;
        rom.reserve(length);
        rom.insert(rom.begin(), std::istream_iterator<uint8_t>(rom_file), std::istream_iterator<uint8_t>());

        return rom;
}

std::string Rom::ParseTitle() {

        auto title_ascii = buffer_.begin() + kRomTitleBegin;
        return std::string(title_ascii, title_ascii + kRomTitleLength);
}

// for debugging
void Rom::PrintBytes(const uint32_t start, const uint32_t end) {
        for (uint32_t i = start; i < end; i++) {
                std::cout << std::hex << (uint32_t) buffer_[i] << " ";
        }

        std::cout << std::endl;
}
