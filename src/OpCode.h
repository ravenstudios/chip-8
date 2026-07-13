#pragma once
#include <cstdint>

class OpCode{
    public:
        OpCode();
        void Decode(uint8_t first, uint8_t x, uint8_t y, uint8_t n, uint16_t nn, uint16_t nnn, uint16_t opcode);
    private:
        void OP_0NNN(uint16_t nnn);
        void OP_00E0();
        void OP_00EE();
        void OP_1NNN(uint16_t address);
        void OP_2NNN(uint16_t nnn);
        void OP_3XNN(uint16_t vx, uint16_t nn);
        void OP_4XNN(uint8_t vx, uint16_t nn);
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
};  
extern OpCode opCode;