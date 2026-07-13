#include "Memory.h"
#include <iostream>

Memory memory;

Memory::Memory(){
// 0x200: call subroutine at 0x208
    SetMemory(0x200, 0x22);
    SetMemory(0x201, 0x08);

// 0x202: V0 = 10
    SetMemory(0x202, 0x60);
    SetMemory(0x203, 0x0A);

// 0x204: loop forever
    SetMemory(0x204, 0x12);
    SetMemory(0x205, 0x04);

// 0x208: V1 = 20
    SetMemory(0x208, 0x61);
    SetMemory(0x209, 0x14);

// 0x20A: return
    SetMemory(0x20A, 0x00);
    SetMemory(0x20B, 0xEE);
}


uint8_t Memory::GetMemory(uint16_t address){
    std::cout << "address: " << address << "\n";
    return m_Memory[address];
}


void Memory::SetMemory(uint16_t address, uint16_t val){
    m_Memory[address] = val;
}



