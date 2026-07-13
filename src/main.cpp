#include "raylib.h"
#include "Constants.h"
#include "Screen.h"
#include "Registers.h"
#include "Cpu.h"
#include "Buttons.h"
#include <string>
#include "Keypad.h"
Button btn_next = Button(CPU_X_OFFSET, 500, 100, 50, "Next", [](){cpu.ExecuteCycle();});

void update(){
    screen.Update();
    registers.Update();
    btn_next.Update();
    keypad.Update();
}


void draw(){
    BeginDrawing();
    ClearBackground(BLACK);

    screen.Draw();
    registers.Draw();
    cpu.Draw();
    btn_next.Draw();
    keypad.Draw();
    EndDrawing();
    
}


int main()
{
    InitWindow(SCREEN_W, SCREEN_H, "Chip-8");

    while (!WindowShouldClose())
    {
        update();
        draw();
    }

    CloseWindow();

    return 0;
}