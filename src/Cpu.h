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
        std::string GetCurrentOpCode();


    private:
        std::string m_CurrentOpCode = "0000";
};
extern CPU cpu;