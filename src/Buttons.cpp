#include "Buttons.h"
#include "raylib.h"
#include <iostream>

Button::Button(int x, int y, int w, int h, std::string label, std::function<void()> callback){
    m_X = x;
    m_Y = y;
    m_W = w;
    m_H = h;
    m_Label = label;
    m_Callback = callback;
}

void Button::Update(){
    Rectangle rect{
        static_cast<float>(m_X),
        static_cast<float>(m_Y),
        static_cast<float>(m_W),
        static_cast<float>(m_H)
    };

    if (CheckCollisionPointRec(GetMousePosition(), rect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        Click();
        m_IsClicked = true;
    }
    
    if (m_IsClicked && IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
        m_IsClicked = false;
    }
    
}


void Button::Draw(){
    Color color = m_IsClicked ? DARKGRAY : LIGHTGRAY;
    DrawRectangle(m_X, m_Y, m_W, m_H, color);
    DrawText(m_Label.c_str(), m_X + 20, m_Y + 20, 20, WHITE);
    DrawRectangleLines(m_X, m_Y, m_W, m_H, BLACK);
}

void Button::Click(){
    if (m_Callback){
        m_Callback();
    }
}


bool Button::GetClick(){
    return m_IsClicked;
}