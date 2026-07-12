#include "raylib.h"
#include "Constants.h"
#include "Registers.h"

Registers registers;

Registers::Registers(){

}

void Registers::Update(){

}


void Registers::Draw(){
    int x = REGISTER_X_OFFSET;
    int y = REGISTER_Y_OFFSET;
    int padding = 3;
    DrawRectangleLines(x, y, REGISTER_W, REGISTER_H, WHITE);

    for(int i = 0; i < 16; i++){
        std::string text = std::string(m_Labels[i]) + ": " + std::to_string(m_Registers[i]);
        DrawText(text.c_str(), x + padding, y + (i * FONT_SIZE), FONT_SIZE, WHITE);
    }
}


uint8_t Registers::GetRegister(uint8_t r){
    return 0;
}


void Registers::SetRegister(uint8_t r){

}



