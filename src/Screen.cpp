#include "Screen.h"
#include "raylib.h"
#include "Constants.h"
#include <iostream>

Screen screen;

Screen::Screen(){
    ClearScreen();
}


void Screen::Update(){

}


void Screen::Draw(){
    Color color;
    for(int c = 0; c < m_COLS; c++){
        for(int r = 0; r < m_ROWS; r++){
            if(m_Pixels[c][r].is_active){
                color = WHITE;
            }
            else{
                color = BLACK;
            }

            int x = m_Pixels[c][r].x * BS + SCREEN_X_OFFSET;
            int y = m_Pixels[c][r].y * BS + SCREEN_Y_OFFSET;
            // std::cout << "X:" << x << "\n";
            
            DrawRectangle(x, y, BS, BS, color);
            DrawRectangleLines(x, y, BS, BS, WHITE);
        }
    }
}

void Screen::SetPixel(int x, int y, bool active){
    m_Pixels[x][y].is_active = active;
}

 bool Screen::GetPixel(int x, int y){
    return  m_Pixels[x][y].is_active;
 }

 void Screen::ClearScreen(){
   for(int c = 0; c < m_COLS; c++){
        for(int r = 0; r < m_ROWS; r++){
            m_Pixels[c][r].x = c;
            m_Pixels[c][r].y = r;
            m_Pixels[c][r].is_active = false;
        }
    }
 }