#include "OpCode.h"
#include "Registers.h"
#include "ProgramCounter.h"
#include "IndexRegister.h"
#include <iostream>
#include "Screen.h"
#include "raylib.h"
#include "Memory.h"
#include "Stack.h"
#include "Keypad.h"
#include "Cpu.h"

OpCode opCode;


OpCode::OpCode(){
   
}

void OpCode::Decode(uint8_t first, uint8_t x, uint8_t y, uint8_t n, uint8_t nn, uint16_t nnn, uint16_t opcode){
   switch (first){
      case 0x0:
         switch (opcode){
            case 0x00E0:
               OP_00E0();
               break;
         
            case 0x00EE:
               OP_00EE();
               break;
            
            default:
               OP_0NNN(nnn);
               break;
         }
         break;
      case 0x1:
         OP_1NNN(nnn);
         break;
      
      case 0x2:
         OP_2NNN(nnn);
         break;

      case 0x3:
         OP_3XNN(x, nn);
         break;

      case 0x4:
         OP_4XNN(x, nn);
         break;

      case 0x5:
         if(n == 0x0){
            OP_5XY0(x, y);
         }
         else{
            std::cerr << "Unknown opcode: " << std::hex << opcode << '\n';
         }
         break;

      case 0x6:
         OP_6XNN(x, nn);
         break;
      
      case 0x7:
         OP_7XNN(x, nn);
         break;
      
      case 0x8:
         switch (n)
         {
         case 0x0:
            OP_8XY0(x, y);
            break;
         case 0x1:
            OP_8XY1(x, y);
            break;
         case 0x2:
            OP_8XY2(x, y);
            break;
         case 0x3:
            OP_8XY3(x, y);
            break;
         case 0x4:
            OP_8XY4(x, y);
            break;
         case 0x5:
            OP_8XY5(x, y);
            break;
         case 0x6:
            OP_8XY6(x, y);
            break;
         case 0x7:
            OP_8XY7(x, y);
            break;
         case 0xE:
            OP_8XYE(x, y);
            break;
         default:
            break;
         }
         break;
      
      case 0x9:
         if(n == 0x0){
            OP_9XY0(x, y);
         }
         else{
            std::cerr << "Unknown opcode: " << std::hex << opcode << '\n';
         }
         
         break;
      case 0xA:
         OP_ANNN(nnn);
         break;
      case 0xB:
         OP_BNNN(nnn);
         break;
      case 0xC:
         OP_CXNN(x, nn);
         break;
      case 0xD:
         OP_DXYN(x, y, n);
         break;
      case 0xE:
         switch (nn){
         case 0x9E:
            OP_EX9E(x);
            break;
         case 0xA1:
            OP_EXA1(x);
            break;
         default:
            break;
         }
         break;
      case 0xF:
         switch (nn){
         case 0x07:
            OP_FX07(x);
            break;
         case 0x0A:
            OP_FX0A(x);
            break;
         case 0x15:
            OP_FX15(x);
            break;
         case 0x18:
            OP_FX18(x);
            break;
         case 0x1E:
            OP_FX1E(x);
            break;
         case 0x29:
            OP_FX29(x);
            break;
         case 0x33:
            OP_FX33(x);
            break;
         case 0x55:
            OP_FX55(x);
            break;
         case 0x65:
            OP_FX65(x);
            break;
         
         default:
            break;
         }
         break;
      default:
         break;
      }
}


void OpCode::OP_0NNN(uint16_t nnn){
   return;
}


void OpCode::OP_00E0(){
   screen.ClearScreen();
}


void OpCode::OP_00EE(){
   uint16_t address = stack.Pop();
   programCounter.SetPC(address);
}


void OpCode::OP_1NNN(uint16_t address){
   programCounter.SetPC(address);
}

void OpCode::OP_2NNN(uint16_t nnn){
   stack.Push(programCounter.GetPC());
   programCounter.SetPC(nnn);
}


void OpCode::OP_3XNN(uint8_t vx, uint8_t nn){
   if(registers.GetRegister(vx) == nn){
      programCounter.IncPC(2);
   }
}


void OpCode::OP_4XNN(uint8_t vx, uint8_t nn){
   if(registers.GetRegister(vx) != nn){
      programCounter.IncPC(2);
   }
}


void OpCode::OP_5XY0(uint8_t vx, uint8_t vy){
   if(registers.GetRegister(vx) == registers.GetRegister(vy)){
      programCounter.IncPC(2);
   }
}


void OpCode::OP_6XNN(uint8_t reg, uint8_t val){
   registers.SetRegister(reg, val);
}

void OpCode::OP_7XNN(uint8_t reg, uint8_t val){
   uint8_t current = registers.GetRegister(reg) + val;
   registers.SetRegister(reg, current);
}

void OpCode::OP_8XY0(uint8_t reg1, uint8_t reg2){
   uint8_t vy = registers.GetRegister(reg2);
   registers.SetRegister(reg1, vy);
}


void OpCode::OP_8XY1(uint8_t reg1, uint8_t reg2){
   uint8_t vx = registers.GetRegister(reg1);
   uint8_t vy = registers.GetRegister(reg2);
   uint8_t val = vx | vy;
   registers.SetRegister(reg1, val);
}


void OpCode::OP_8XY2(uint8_t reg1, uint8_t reg2){
   uint8_t vx = registers.GetRegister(reg1);
   uint8_t vy = registers.GetRegister(reg2);
   uint8_t val = vx & vy;
   registers.SetRegister(reg1, val);
}


void OpCode::OP_8XY3(uint8_t reg1, uint8_t reg2){
   uint8_t vx = registers.GetRegister(reg1);
   uint8_t vy = registers.GetRegister(reg2);
   uint8_t val = vx ^ vy;
   registers.SetRegister(reg1, val);
}


void OpCode::OP_8XY4(uint8_t reg1, uint8_t reg2){
   uint8_t vx = registers.GetRegister(reg1);
   uint8_t vy = registers.GetRegister(reg2);
   uint16_t val = vx + vy;
   registers.SetRegister(0xF, val > 255);
   registers.SetRegister(reg1, val & 0xFF);
}


void OpCode::OP_8XY5(uint8_t reg1, uint8_t reg2){
   uint8_t vx = registers.GetRegister(reg1);
   uint8_t vy = registers.GetRegister(reg2);
   uint16_t val = vx - vy;
   registers.SetRegister(0xF, vx >= vy);
   registers.SetRegister(reg1, val & 0xFF);
}


void OpCode::OP_8XY6(uint8_t reg1, uint8_t reg2){
   uint8_t vx = registers.GetRegister(reg1);
   registers.SetRegister(0xF, vx & 0x01);
   registers.SetRegister(reg1, vx >> 1);
}


void OpCode::OP_8XY7(uint8_t reg1, uint8_t reg2){
   uint8_t vx = registers.GetRegister(reg1);
   uint8_t vy = registers.GetRegister(reg2);
   uint16_t val = vy - vx;
   registers.SetRegister(0xF, vy >= vx);
   registers.SetRegister(reg1, val & 0xFF);
}


void OpCode::OP_8XYE(uint8_t reg1, uint8_t reg2){
   uint8_t vx = registers.GetRegister(reg1);
   registers.SetRegister(0xF, (vx >> 7) & 0x01);
   registers.SetRegister(reg1, vx << 1);
}

void OpCode::OP_9XY0(uint8_t reg1, uint8_t reg2){
   uint8_t vx = registers.GetRegister(reg1);
   uint8_t vy = registers.GetRegister(reg2);
   if(vx == vy){
      return;
   }
   programCounter.IncPC(2);
}  


void OpCode::OP_ANNN(uint16_t address){
   indexRegister.Set(address);
}


void OpCode::OP_BNNN(uint16_t address){
   uint8_t vx = registers.GetRegister(0x0);
   programCounter.SetPC(vx + address);
}


void OpCode::OP_CXNN(uint8_t reg, uint8_t nn){
   uint8_t randByte = GetRandomValue(0, 255);
   registers.SetRegister(reg, nn & randByte);
}


void OpCode::OP_DXYN(uint8_t reg1, uint8_t reg2, uint8_t n){
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


void OpCode::OP_EX9E(uint8_t vx){
   if (keypad.GetKey(registers.GetRegister(vx))){
      programCounter.IncPC(2);
   }
}


void OpCode::OP_EXA1(uint8_t vx){
   if (!keypad.GetKey(registers.GetRegister(vx))){
      programCounter.IncPC(2);
   }
}


void OpCode::OP_FX07(uint8_t vx){
   registers.SetRegister(vx, cpu.GetDelayTimer());
}


void OpCode::OP_FX0A(uint8_t vx){
   for (uint8_t key = 0; key < 16; key++)
    {
        if (keypad.GetKey(key))
        {
            registers.SetRegister(vx, key);
            return;
        }
    }
    programCounter.IncPC(-2);
}


void OpCode::OP_FX15(uint8_t vx){
   cpu.SetDelayTimer(registers.GetRegister(vx));
}


void OpCode::OP_FX18(uint8_t vx){
   cpu.SetSoundTimer(registers.GetRegister(vx));
}


void OpCode::OP_FX1E(uint8_t vx){
   uint16_t val = registers.GetRegister(vx);
    indexRegister.Set(indexRegister.Get() + val);
}


void OpCode::OP_FX29(uint8_t vx){
   constexpr uint16_t FONT_START = 0x050;
   constexpr uint8_t FONT_HEIGHT = 5;
   uint8_t digit = registers.GetRegister(vx) & 0x0F;
   indexRegister.Set(FONT_START + digit * FONT_HEIGHT);
   
}


void OpCode::OP_FX33(uint8_t vx){
   uint8_t value = registers.GetRegister(vx);
   uint16_t i = indexRegister.Get();

   memory.SetMemory(i,     value / 100);
   memory.SetMemory(i + 1, (value / 10) % 10);
   memory.SetMemory(i + 2, value % 10);
}


void OpCode::OP_FX55(uint8_t vx){
   uint16_t idx = indexRegister.Get();
   for (uint8_t i = 0; i <= vx; i++){
      memory.SetMemory(idx + i, registers.GetRegister(i));
   }
}


void OpCode::OP_FX65(uint8_t vx){
   uint16_t idx = indexRegister.Get();
   for (uint8_t i = 0; i <= vx; i++){
      registers.SetRegister(i, memory.GetMemory(idx + i));
   }
}

