#pragma once
#include <array>
#include <cstdint>
#include <string>

class Registers{
    public:
    Registers();
    void Update();
    void Draw();
    uint8_t GetRegister(uint8_t r);
    void SetRegister(uint8_t r);

    private:
        std::array<uint8_t, 16> m_Registers;
        std::array<std::string, 16> m_Labels = {
            "V0", "V1", "V2", "V3", "V4", "V5", "V6", "V7", "V8", 
            "V9", "VA", "VB", "VC", "VD", "VE", "VF"
        };
};  
extern Registers registers;