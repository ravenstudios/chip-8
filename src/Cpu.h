#pragma once
#include <string>

class CPU{
    public:
        CPU();
        void ExecuteCycle();
        void Fetch();
        void Decode();
        void Draw();
        void DrawStack();
        uint16_t GetCurrentOpCode() const;


    private:
        uint16_t m_CurrentOpCode = 0;
};
extern CPU cpu;