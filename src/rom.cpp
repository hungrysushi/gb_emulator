#include "rom.h"

#include <fstream>
#include <iostream>
#include <iomanip>
#include <iterator>

#include "types.h"

Rom::Rom(const std::string& filename)
        : buffer_(LoadRom(filename)),
          size_(buffer_.size()),
          /* cartidge header fields */
          logo_(ParseLogo()),
          title_(ParseTitle()),
          manufacturer_code_(ParseManufacturerCode()),
          /* cgb_flag_(ParseCgbFlag()), */
          new_licensee_code_(ParseNewLicenseeCode())
          /* sgb_flag_(ParseSgbFlag()), */
          /* cartridge_type_(ParseCartridgeType()), */
          /* rom_size_(ParseRomSize()), */
          /* ram_size_(ParseRamSize()), */
          /* desination_code_(ParseDestinationCode()), */
          /* old_licensee_code_(ParseOldLicenseeCode()), */
          /* mask_rom_version_number_(ParseMaskRomVersionNumber()), */
          /* header_checksum_(ParseHeaderChecksum()), */
          /* global_checksum_(ParseGlobalChecksum()) { */
{
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

std::vector<uint8_t> Rom::ParseLogo() {

        auto logo_location = buffer_.begin() + kRomLogoBegin;
        return std::vector<uint8_t>(logo_location, logo_location + kRomLogoLength);
}

std::string Rom::ParseTitle() {

        auto title_ascii = buffer_.begin() + kRomTitleBegin;
        return std::string(title_ascii, title_ascii + kRomTitleLength);
}

std::string Rom::ParseManufacturerCode() {

        auto manufacturer_ascii = buffer_.begin() + kRomManufacturerBegin;
        return std::string(manufacturer_ascii, manufacturer_ascii + kRomManufacturerLength);
}

std::string Rom::ParseNewLicenseeCode() {

        auto licensee_ascii = buffer_.begin() + kRomNewLicenseeBegin;
        return std::string(licensee_ascii, licensee_ascii + kRomNewLicenseeLength);
}

std::vector<Instruction> Rom::BuildInstructionList() {
        std::vector<Instruction> instruction_list;

        uint32_t rom_iter = 0;

        while (rom_iter < size_) {

                // TODO
        }

        return instruction_list;
}

// for debugging
void Rom::PrintBytes(const uint32_t start, const uint32_t end) {
        for (uint32_t i = start; i < end; i++) {
                std::cout << std::setfill('0')
                          << std::setw(2)
                          << std::hex
                          << (uint32_t) buffer_[i]
                          << " ";
        }

        std::cout << std::endl;
}
