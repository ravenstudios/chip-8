#include "OpCode.h"
#include "Registers.h"
#include "ProgramCounter.h"
#include "IndexRegister.h"
#include <iostream>
#include "Screen.h"
#include "raylib.h"
#include "Memory.h"

OpCode opCode;


OpCode::OpCode(){
   
}

void OpCode::Decode(uint8_t first, uint8_t x, uint8_t y, uint8_t n, uint16_t nn, uint16_t nnn){
   switch (first){
      case 0x1:
         opCode.OP1NNN(nnn);
         break;

      case 0x6:
         opCode.OP6XNN(x, nn);
         break;
      
      case 0x7:
         opCode.OP7XNN(x, nn);
         break;
      
      case 0x8:
         switch (n)
         {
         case 0x0:
            OP8XY0(x, y);
            break;
         case 0x1:
            OP8XY1(x, y);
            break;
         case 0x2:
            OP8XY2(x, y);
            break;
         case 0x3:
            OP8XY3(x, y);
            break;
         case 0x4:
            OP8XY4(x, y);
            break;
         case 0x5:
            OP8XY5(x, y);
            break;
         case 0x6:
            OP8XY6(x, y);
            break;
         case 0x7:
            OP8XY7(x, y);
            break;
         case 0xE:
            OP8XYE(x, y);
            break;
         default:
            break;
         }
         break;
      
      case 0x9:
         OP9XY0(x, y);
         break;
      case 0xA:
         opCode.OPANNN(nnn);
         break;
      case 0xB:
         opCode.OPBNNN(nnn);
         break;
      case 0xC:
         opCode.OPCXNN(x, nn);
         break;
      case 0xD:
         opCode.OPDXYN(x, y, n);
         break;

      default:
         break;
      }
}



void OpCode::OP1NNN(uint16_t address){
   programCounter.SetPC(address);
}


void OpCode::OP6XNN(uint8_t reg, uint8_t val){
   // std::cout << "reg: " << static_cast<int>(reg) << " val:" << static_cast<int>(val) << "\n";
   registers.SetRegister(reg, val);
}

void OpCode::OP7XNN(uint8_t reg, uint8_t val){
   std::cout << "reg: " << static_cast<int>(reg) << " val:" << static_cast<int>(val) << "\n";
   uint8_t current = registers.GetRegister(reg) + val;
   std::cout << "current:" << registers.GetRegister(reg) << "\n";
   registers.SetRegister(reg, current);
}

void OpCode::OP8XY0(uint8_t reg1, uint8_t reg2){
   uint8_t vy = registers.GetRegister(reg2);
   registers.SetRegister(reg1, vy);
}


void OpCode::OP8XY1(uint8_t reg1, uint8_t reg2){
   uint8_t vx = registers.GetRegister(reg1);
   uint8_t vy = registers.GetRegister(reg2);
   uint8_t val = vx | vy;
   registers.SetRegister(reg1, val);
}


void OpCode::OP8XY2(uint8_t reg1, uint8_t reg2){
   uint8_t vx = registers.GetRegister(reg1);
   uint8_t vy = registers.GetRegister(reg2);
   uint8_t val = vx & vy;
   registers.SetRegister(reg1, val);
}


void OpCode::OP8XY3(uint8_t reg1, uint8_t reg2){
   uint8_t vx = registers.GetRegister(reg1);
   uint8_t vy = registers.GetRegister(reg2);
   uint8_t val = vx ^ vy;
   registers.SetRegister(reg1, val);
}


void OpCode::OP8XY4(uint8_t reg1, uint8_t reg2){
   uint8_t vx = registers.GetRegister(reg1);
   uint8_t vy = registers.GetRegister(reg2);
   uint16_t val = vx + vy;
   registers.SetRegister(0xF, val > 255);
   registers.SetRegister(reg1, val & 0xFF);
}


void OpCode::OP8XY5(uint8_t reg1, uint8_t reg2){
   uint8_t vx = registers.GetRegister(reg1);
   uint8_t vy = registers.GetRegister(reg2);
   uint16_t val = vx - vy;
   registers.SetRegister(0xF, vx >= vy);
   registers.SetRegister(reg1, val & 0xFF);
}


void OpCode::OP8XY6(uint8_t reg1, uint8_t reg2){
   uint8_t vx = registers.GetRegister(reg1);
   registers.SetRegister(0xF, vx & 0x01);
   registers.SetRegister(reg1, vx >> 1);
}


void OpCode::OP8XY7(uint8_t reg1, uint8_t reg2){
   uint8_t vx = registers.GetRegister(reg1);
   uint8_t vy = registers.GetRegister(reg2);
   uint16_t val = vy - vx;
   registers.SetRegister(0xF, vy >= vx);
   registers.SetRegister(reg1, val & 0xFF);
}


void OpCode::OP8XYE(uint8_t reg1, uint8_t reg2){
   uint8_t vx = registers.GetRegister(reg1);
   registers.SetRegister(0xF, (vx >> 7) & 0x01);
   registers.SetRegister(reg1, vx << 1);
}

void OpCode::OP9XY0(uint8_t reg1, uint8_t reg2){
   uint8_t vx = registers.GetRegister(reg1);
   uint8_t vy = registers.GetRegister(reg2);
   if(vx == vy){
      return;
   }
   programCounter.IncPC(2);
}  


void OpCode::OPANNN(uint16_t address){
   indexRegister.Set(address);
}


void OpCode::OPBNNN(uint16_t address){
   uint8_t vx = registers.GetRegister(0x0);
   programCounter.SetPC(vx + address);
}


void OpCode::OPCXNN(uint8_t reg, uint8_t nn){
   uint8_t rand = GetRandomValue(0, 255);
   registers.SetRegister(reg, nn & rand);
}


void OpCode::OPDXYN(uint8_t reg1, uint8_t reg2, uint8_t n){
    uint8_t vx = registers.GetRegister(reg1);
    uint8_t vy = registers.GetRegister(reg2);
    uint16_t ir = indexRegister.Get();

    registers.SetRegister(0xF, 0);

    for (uint8_t row = 0; row < n; row++){
        uint8_t spriteByte = memory.GetMemory(ir + row);

        for (uint8_t col = 0; col < 8; col++){
            uint8_t spritePixel = spriteByte & (0x80 >> col);

            if (spritePixel == 0){
                continue;
            }

            uint8_t x = (vx + col) % 64;
            uint8_t y = (vy + row) % 32;

            bool oldPixel = screen.GetPixel(x, y);

            if (oldPixel){
                registers.SetRegister(0xF, 1);
            }

            screen.SetPixel(x, y, !oldPixel);
        }
    }
}

