#pragma once
#include <array>
#include <cstdint>
#include <string>

class Stack{
    public:
    Stack();
    void Push(uint16_t address);
    uint16_t Pop();
    uint8_t GetSP() const;
    int GetAddress(uint16_t address);

    private:
        std::array<uint16_t, 16> m_Stack;
        uint8_t m_StackPointer = 0;

};  
extern Stack stack;