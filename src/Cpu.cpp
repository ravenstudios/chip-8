#include "Cpu.h"
#include "raylib.h"
#include "Constants.h"
#include "Stack.h"
#include "Memory.h"
#include "Registers.h"
#include "ProgramCounter.h"
#include <string>
#include <iostream>
#include "OpCode.h"
#include "IndexRegister.h"

CPU cpu;


CPU::CPU(){

}


void CPU::ExecuteCycle(){
    Fetch();
    Decode();

}


void CPU::Fetch(){
    uint16_t pc = programCounter.GetPC();

    uint8_t highByte = memory.GetMemory(pc);
    uint8_t lowByte  = memory.GetMemory(pc + 1);

    m_CurrentOpCode =
        (static_cast<uint16_t>(highByte) << 8) |
        lowByte;

    programCounter.IncPC(2);

    // std::cout << "Opcode: "
    //           << std::hex << m_CurrentOpCode
    //           << std::dec << '\n';
}


void CPU::Decode(){
    uint16_t opcode = m_CurrentOpCode;

    uint8_t first = (opcode & 0xF000) >> 12;
    uint8_t x     = (opcode & 0x0F00) >> 8;
    uint8_t y     = (opcode & 0x00F0) >> 4;
    uint8_t n     = opcode & 0x000F;

    uint8_t nn    = opcode & 0x00FF;
    uint16_t nnn  = opcode & 0x0FFF;

    std::cout
    << "First: " << static_cast<int>(first)
    << " x: "    << static_cast<int>(x)
    << " y: "    << static_cast<int>(y)
    << " n: "    << static_cast<int>(n)
    << " nn: "   << static_cast<int>(nn)
    << " nnn: "  << nnn
    << '\n';


    opCode.Decode(first, x, y, n, nn, nnn, opcode);
}

uint16_t CPU::GetCurrentOpCode() const{
    return m_CurrentOpCode;
}


void CPU::Draw(){
    DrawStack();
    int x = CPU_X_OFFSET;
    int y = CPU_Y_OFFSET;
    int padding = 5;


    std::string text;
    DrawRectangleLines(x, y, CPU_W, CPU_H, WHITE);
    DrawText("CPU STATE", x + padding, y, FONT_SIZE, WHITE);
    text = TextFormat("PC: %04X", programCounter.GetPC());
    DrawText(text.c_str(), x + padding, y + FONT_SIZE, FONT_SIZE, WHITE);
    text = "I: " + std::to_string(indexRegister.Get());
    DrawText(text.c_str(), x + padding, y + FONT_SIZE * 2, FONT_SIZE, WHITE);
    text = "SP: " + std::to_string(stack.GetSP());
    DrawText(text.c_str(), x + padding, y + FONT_SIZE * 3, FONT_SIZE, WHITE);
    text = TextFormat("Opcode: %04X", m_CurrentOpCode);
    DrawText(text.c_str(), x + padding, y + FONT_SIZE * 4, FONT_SIZE, WHITE);
}

void CPU::DrawStack(){
    int x =  STACK_X_OFFSET;
    int y =  STACK_Y_OFFSET;
    int padding = 5;

    std::string text;
    DrawRectangleLines(x, y, STACK_W, STACK_H, WHITE);

    for(int i = 0; i < 16; i++){
        text = TextFormat("%02X: ", i);
        DrawText(text.c_str(), x + padding, y + FONT_SIZE * i, FONT_SIZE, WHITE);
        text = TextFormat("%04X: ", stack.GetAddress(i));
        DrawText(text.c_str(), x + padding + (FONT_SIZE * 2), y + FONT_SIZE * i, FONT_SIZE, WHITE);
    }
   
}
