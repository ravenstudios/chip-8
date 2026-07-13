#include "Memory.h"
#include <iostream>

Memory memory;

Memory::Memory(){
    LoadFile("games/glitchGhost.ch8");
}


uint8_t Memory::GetMemory(uint16_t address){
    return m_Memory[address];
}


void Memory::SetMemory(uint16_t address, uint16_t val){
    m_Memory[address] = val;
}




void Memory::LoadFile(const std::string& filename){
    std::ifstream file(filename, std::ios::binary);

    if (!file){
        std::cerr << "Failed to open ROM: " << filename << '\n';
        return;
    }

    // CHIP-8 programs start at 0x200
    file.read(reinterpret_cast<char*>(&m_Memory[0x200]),
              sizeof(m_Memory) - 0x200);

    std::cout << "Loaded "
              << file.gcount()
              << " bytes.\n";
}

