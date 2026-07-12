#pragma once

struct Pixel{
    int x;
    int y;
    bool is_active = false;
};

class Screen{
    public:
        Screen();
        void Update();
        void Draw();

    private:
        static const int m_COLS = 64;
        static const int m_ROWS = 32;
        Pixel m_Pixels[m_COLS][m_ROWS];
};

extern Screen screen;