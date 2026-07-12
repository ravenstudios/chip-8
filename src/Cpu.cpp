#include "Cpu.h"
#include "raylib.h"
#include "Constants.h"
#include "Stack.h"
#include "Registers.h"
#include "ProgramCounter.h"
#include <string>

CPU cpu;


CPU::CPU(){

}


void CPU::ExecuteCycle(){

}


void CPU::Fetch(){

}


void CPU::Decode(){

}

std::string CPU::GetCurrentOpCode(){
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
    text = "PC: " + std::to_string(programCounter.GetPC());
    DrawText(text.c_str(), x + padding, y + FONT_SIZE, FONT_SIZE, WHITE);
    text = "I: " + std::to_string(registers.GetRegister(0));
    DrawText(text.c_str(), x + padding, y + FONT_SIZE * 2, FONT_SIZE, WHITE);
    text = "SP: " + std::to_string(stack.GetSP());
    DrawText(text.c_str(), x + padding, y + FONT_SIZE * 3, FONT_SIZE, WHITE);
    text = "Opcode: " + m_CurrentOpCode;
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
