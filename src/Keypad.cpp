#include "Keypad.h"
#include "Constants.h"
#include <iostream>

Keypad keypad;
Keypad::Keypad(){
   
    for (size_t c = 0; c < 4; c++){
        for (size_t r = 0; r < 4; r++){
            int i = r * 4 + c;
            std::string s = m_KeyLabels[i];
            m_Buttons[i] = Button(
                KEYPAD_X + (BTN_SIZE * c),
                KEYPAD_Y+ (BTN_SIZE * r),
                BTN_SIZE, BTN_SIZE,
                s,
                [this, i](){Keypress(i);}
            );
        }
    }
    
    

}


void Keypad::Update(){
    for (int i = 0; i < 16; i++){
        m_Buttons[i].Update();
        if (m_KeyStates[i] && !m_Buttons[i].GetClick()){
           m_KeyStates[i] = false;
        }
    }
}


void Keypad::Draw(){
    DrawRectangleLines(KEYPAD_X, KEYPAD_Y, KEYPAD_W, KEYPAD_H, WHITE);
    for (Button& button : m_Buttons){
        button.Draw();
    }
}

void Keypad::Keypress(uint8_t key){
    m_KeyStates[key] = true;
}



bool Keypad::GetKey(uint8_t key) const{
    return m_KeyStates[key];
}


const bool* Keypad::GetKeys() const{
    return m_KeyStates;
}   

