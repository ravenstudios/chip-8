#include "raylib.h"
#include "Constants.h"
#include "Screen.h"
#include "Registers.h"
#include "Cpu.h"



void update(){
    screen.Update();
    registers.Update();
}


void draw(){
    BeginDrawing();
    ClearBackground(BLACK);

    screen.Draw();
    registers.Draw();
    cpu.Draw();

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