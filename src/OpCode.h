#pragma once
#include <cstdint>

class OpCode{
    public:
        OpCode();
        void Decode(uint8_t first, uint8_t x, uint8_t y, uint8_t n, uint8_t nn, uint16_t nnn, uint16_t opcode);
    private:
        void OP_0NNN(uint16_t nnn);
        void OP_00E0();
        void OP_00EE();
        void OP_1NNN(uint16_t address);
        void OP_2NNN(uint16_t nnn);
        void OP_3XNN(uint8_t vx, uint8_t nn);
        void OP_4XNN(uint8_t vx, uint8_t nn);
        void OP_5XY0(uint8_t vx, uint8_t vy);
        void OP_6XNN(uint8_t vx, uint8_t val);
        void OP_7XNN(uint8_t vx, uint8_t val);
        void OP_8XY0(uint8_t vx, uint8_t vy);
        void OP_8XY1(uint8_t vx, uint8_t vy);
        void OP_8XY2(uint8_t vx, uint8_t vy);
        void OP_8XY3(uint8_t vx, uint8_t vy);
        void OP_8XY4(uint8_t vx, uint8_t vy);
        void OP_8XY5(uint8_t vx, uint8_t vy);
        void OP_8XY6(uint8_t vx, uint8_t vy);
        void OP_8XY7(uint8_t vx, uint8_t vy);
        void OP_8XYE(uint8_t vx, uint8_t vy);
        void OP_9XY0(uint8_t vx, uint8_t vy);
        void OP_ANNN(uint16_t address);
        void OP_BNNN(uint16_t address);
        void OP_CXNN(uint8_t vx, uint8_t nn);
        void OP_DXYN(uint8_t vx, uint8_t vy, uint8_t n);

        void OP_EX9E(uint8_t vx);
        void OP_EXA1(uint8_t vx);
        void OP_FX07(uint8_t vx);
        void OP_FX0A(uint8_t vx);
        void OP_FX15(uint8_t vx);
        void OP_FX18(uint8_t vx);
        void OP_FX1E(uint8_t vx);
        void OP_FX29(uint8_t vx);
        void OP_FX33(uint8_t vx);
        void OP_FX55(uint8_t vx);
        void OP_FX65(uint8_t vx);

};  
extern OpCode opCode;