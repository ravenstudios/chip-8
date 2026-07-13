#pragma once
#include <cstdint>

class ProgramCounter{
    public:
        ProgramCounter();
        void IncPC(int i);
        uint16_t GetPC();
        void SetPC(uint16_t address);

    private:
        uint16_t m_ProgamCounter = 0x200;
};

extern ProgramCounter programCounter;