#pragma once
#include <cstdint>

class OpCode{
    public:
        OpCode();
        void Decode(uint8_t first, uint8_t x, uint8_t y, uint8_t n, uint16_t nn, uint16_t nnn);
    private:
        void OP1NNN(uint16_t address);
        void OP6XNN(uint8_t reg, uint8_t val);
        void OP7XNN(uint8_t reg, uint8_t val);
        void OP8XY0(uint8_t reg1, uint8_t reg2);
        void OP8XY1(uint8_t reg1, uint8_t reg2);
        void OP8XY2(uint8_t reg1, uint8_t reg2);
        void OP8XY3(uint8_t reg1, uint8_t reg2);
        void OP8XY4(uint8_t reg1, uint8_t reg2);
        void OP8XY5(uint8_t reg1, uint8_t reg2);
        void OP8XY6(uint8_t reg1, uint8_t reg2);
        void OP8XY7(uint8_t reg1, uint8_t reg2);
        void OP8XYE(uint8_t reg1, uint8_t reg2);
        void OP9XY0(uint8_t reg1, uint8_t reg2);
        void OPANNN(uint16_t address);
        void OPBNNN(uint16_t address);
        void OPCXNN(uint8_t reg1, uint8_t nn);
        void OPDXYN(uint8_t reg1, uint8_t reg2, uint8_t n);
};  
extern OpCode opCode;