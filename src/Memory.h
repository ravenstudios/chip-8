#pragma once
#include <array>
#include <cstdint>

class Memory{
    public:
        Memory();
        uint8_t GetMemory(uint16_t address);
        void SetMemory(uint16_t address, uint16_t val);

    private:
        std::array<uint8_t, 4096> m_Memory;
};
extern Memory memory;