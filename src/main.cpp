#include "raylib.h"
#include "Constants.h"
#include "Screen.h"



void update(){
    screen.Update();
}


void draw(){
    BeginDrawing();
    ClearBackground(BLACK);

    screen.Draw();

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