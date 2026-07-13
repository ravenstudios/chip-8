#pragma once
#include "Buttons.h"
#include "raylib.h"
#include <string>

class Keypad{
    public:
        Keypad();
        void Update();
        void Draw();
        bool GetKey(uint8_t key) const;
        const bool* GetKeys() const;
        

    private:
        bool m_KeyStates[16];
        std::string m_KeyLabels[16] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};
        Button m_Buttons[16];
        void Keypress(uint8_t key);
};

extern Keypad keypad;