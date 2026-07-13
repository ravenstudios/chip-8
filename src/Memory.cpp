#include "Memory.h"
#include <iostream>

Memory memory;

Memory::Memory(){
// Digit 0 at 0x300
    m_Memory[0x300] = 0xF0; // ####....
    m_Memory[0x301] = 0x90; // #..#....
    m_Memory[0x302] = 0x90; // #..#....
    m_Memory[0x303] = 0x90; // #..#....
    m_Memory[0x304] = 0xF0; // ####....

    // Digit 1 at 0x305
    m_Memory[0x305] = 0x20; // ..#.....
    m_Memory[0x306] = 0x60; // .##.....
    m_Memory[0x307] = 0x20; // ..#.....
    m_Memory[0x308] = 0x20; // ..#.....
    m_Memory[0x309] = 0x70; // .###....

    // Digit 2 at 0x30A
    m_Memory[0x30A] = 0xF0; // ####....
    m_Memory[0x30B] = 0x10; // ...#....
    m_Memory[0x30C] = 0xF0; // ####....
    m_Memory[0x30D] = 0x80; // #.......
    m_Memory[0x30E] = 0xF0; // ####....


    // --------------------------------------------------
    // Program starts at 0x200
    // --------------------------------------------------

    // V0 = 5
    m_Memory[0x200] = 0x60;
    m_Memory[0x201] = 0x05;

    // V1 = 10
    m_Memory[0x202] = 0x61;
    m_Memory[0x203] = 0x0A;

    // V2 = V1
    // 8210: V2 = V1
    m_Memory[0x204] = 0x82;
    m_Memory[0x205] = 0x10;

    // V2 += V0
    // V2 becomes 15
    m_Memory[0x206] = 0x82;
    m_Memory[0x207] = 0x04;

    // V3 = 0xAA
    m_Memory[0x208] = 0x63;
    m_Memory[0x209] = 0xAA;

    // V4 = 0xCC
    m_Memory[0x20A] = 0x64;
    m_Memory[0x20B] = 0xCC;

    // V3 = V3 OR V4
    // 0xAA | 0xCC = 0xEE
    m_Memory[0x20C] = 0x83;
    m_Memory[0x20D] = 0x41;

    // V5 = 0xAA
    m_Memory[0x20E] = 0x65;
    m_Memory[0x20F] = 0xAA;

    // V5 = V5 AND V4
    // 0xAA & 0xCC = 0x88
    m_Memory[0x210] = 0x85;
    m_Memory[0x211] = 0x42;

    // V6 = 0xAA
    m_Memory[0x212] = 0x66;
    m_Memory[0x213] = 0xAA;

    // V6 = V6 XOR V4
    // 0xAA ^ 0xCC = 0x66
    m_Memory[0x214] = 0x86;
    m_Memory[0x215] = 0x43;

    // V7 = 200
    m_Memory[0x216] = 0x67;
    m_Memory[0x217] = 0xC8;

    // V8 = 100
    m_Memory[0x218] = 0x68;
    m_Memory[0x219] = 0x64;

    // V7 += V8
    // 200 + 100 = 300
    // V7 becomes 44, VF becomes 1
    m_Memory[0x21A] = 0x87;
    m_Memory[0x21B] = 0x84;

    // V9 = 5
    m_Memory[0x21C] = 0x69;
    m_Memory[0x21D] = 0x05;

    // VA = 10
    m_Memory[0x21E] = 0x6A;
    m_Memory[0x21F] = 0x0A;

    // V9 = V9 - VA
    // 5 - 10 wraps to 251, VF = 0
    m_Memory[0x220] = 0x89;
    m_Memory[0x221] = 0xA5;

    // VB = 0x81
    m_Memory[0x222] = 0x6B;
    m_Memory[0x223] = 0x81;

    // Shift VB right
    // VB becomes 0x40, VF = 1
    m_Memory[0x224] = 0x8B;
    m_Memory[0x225] = 0x06;

    // VC = 0x81
    m_Memory[0x226] = 0x6C;
    m_Memory[0x227] = 0x81;

    // Shift VC left
    // VC becomes 0x02, VF = 1
    m_Memory[0x228] = 0x8C;
    m_Memory[0x229] = 0x0E;

    // VD = random number masked with 0x0F
    // Result will be between 0 and 15
    m_Memory[0x22A] = 0xCD;
    m_Memory[0x22B] = 0x0F;


    // --------------------------------------------------
    // Draw digit 0 at x=5, y=5
    // --------------------------------------------------

    // V0 = 5
    m_Memory[0x22C] = 0x60;
    m_Memory[0x22D] = 0x05;

    // V1 = 5
    m_Memory[0x22E] = 0x61;
    m_Memory[0x22F] = 0x05;

    // I = 0x300
    m_Memory[0x230] = 0xA3;
    m_Memory[0x231] = 0x00;

    // Draw 5-byte sprite at V0, V1
    m_Memory[0x232] = 0xD0;
    m_Memory[0x233] = 0x15;


    // --------------------------------------------------
    // Draw digit 1 at x=15, y=5
    // --------------------------------------------------

    // V0 = 15
    m_Memory[0x234] = 0x60;
    m_Memory[0x235] = 0x0F;

    // I = 0x305
    m_Memory[0x236] = 0xA3;
    m_Memory[0x237] = 0x05;

    // Draw sprite
    m_Memory[0x238] = 0xD0;
    m_Memory[0x239] = 0x15;


    // --------------------------------------------------
    // Draw digit 2 at x=25, y=5
    // --------------------------------------------------

    // V0 = 25
    m_Memory[0x23A] = 0x60;
    m_Memory[0x23B] = 0x19;

    // I = 0x30A
    m_Memory[0x23C] = 0xA3;
    m_Memory[0x23D] = 0x0A;

    // Draw sprite
    m_Memory[0x23E] = 0xD0;
    m_Memory[0x23F] = 0x15;


    // --------------------------------------------------
    // Endless loop
    // --------------------------------------------------

    m_Memory[0x240] = 0x12;
    m_Memory[0x241] = 0x40;
}


uint8_t Memory::GetMemory(uint16_t address){
    std::cout << "address: " << address << "\n";
    return m_Memory[address];
}


void Memory::SetMemory(uint16_t){

}



