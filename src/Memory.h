#pragma once
#include <array>
#include <cstdint>
#include <fstream>

class Memory{
    public:
        Memory();
        uint8_t GetMemory(uint16_t address);
        void SetMemory(uint16_t address, uint16_t val);
        void LoadFile(const std::string& filename);

    private:
        std::array<uint8_t, 4096> m_Memory;
};
extern Memory memory;