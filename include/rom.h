#pragma once

#include <string>
#include <vector>

class Rom {
public:
        Rom(const std::string& filename);
        ~Rom();

        /*
         * methods to load rom data and initialize const member variables
         */
        std::vector<uint8_t> LoadRom(const std::string& filename);
        std::vector<uint8_t> ParseLogo();
        std::string ParseTitle();
        std::string ParseManufacturerCode();
        std::string ParseNewLicenseeCode();

        void PrintBytes(const uint32_t start, const uint32_t end);

        const std::vector<uint8_t> buffer_;
        const int32_t size_;
        
        /*
         * Info and flags from the rom header
         */
        // TODO convert flags to enums
        const std::vector<uint8_t> logo_;
        const std::string title_;
        const std::string manufacturer_code_;
        /* const uint8_t cgb_flag_; */
        const std::string new_licensee_code_;
        /* const uint8_t sgb_flag; */
        /* const uint8_t cartridge_type_; */
        /* const uint8_t rom_size_; */
        /* const uint8_t ram_size_; */
        /* const uint8_t destination_code_; */
        /* const uint8_t old_licensee_code_; */
        /* const uint8_t mask_rom_version_number_; */
        /* const uint8_t header_checksum_; */
        /* const uint16_t global_checksum_; */
};
