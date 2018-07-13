#pragma once

constexpr uint32_t kRomLogoBegin = 0x104;
constexpr uint32_t kRomLogoLength = 48;

constexpr uint32_t kRomTitleBegin = 0x134;
constexpr uint32_t kRomTitleLength = 11;

constexpr uint32_t kRomManufacturerBegin = 0x13F;
constexpr uint32_t kRomManufacturerLength = 4;

constexpr uint32_t kRomCgbBegin = 0x134;
constexpr uint32_t kRomCgbLength = 1;

constexpr uint32_t kRomNewLicenseeBegin = 0x144;
constexpr uint32_t kRomNewLicenseeLength = 2;

constexpr uint32_t kRomSgbBegin = 0x146;
constexpr uint32_t kRomSgbLength = 1;

constexpr uint32_t kRomCartridgeTypeBegin = 0x147;
constexpr uint32_t kRomCartridgeTypeLength = 1;

constexpr uint32_t kRomSizeBegin = 0x148;
constexpr uint32_t kRomSizeLength = 1;

constexpr uint32_t kRomRamSizeBegin = 0x149;
constexpr uint32_t kRomRamSizeLength = 1;

constexpr uint32_t kRomDestinationCodeBegin = 0x14A;
constexpr uint32_t kRomDestinationCodeLength = 1;

constexpr uint32_t kRomOldLicenseeBegin = 0x14B;
constexpr uint32_t kRomOldLicenseeLength = 1;

constexpr uint32_t kRomMaskRomBegin = 0x14C;
constexpr uint32_t kRomMaskRomLength = 1;

constexpr uint32_t kRomHeaderChecksumBegin = 0x14D;
constexpr uint32_t kRomHeaderChecksumLength = 1;

constexpr uint32_t kRomGlobalChecksumBegin = 0x14E;
constexpr uint32_t kRomGlobalChecksumLength = 2;

