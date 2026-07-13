#include "Buttons.h"
#include "raylib.h"


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
        }
    }


    void Button::Draw(){
        DrawRectangle(m_X, m_Y, m_W, m_H, RED);
        DrawText(m_Label.c_str(), m_X + 20, m_Y + 20, 20, WHITE);
    }

    void Button::Click(){
        if (m_Callback){
            m_Callback();
        }
    }

