#pragma once
#include <cstdint>

class ProgramCounter{
    public:
        ProgramCounter();
        void IncPC();
        uint16_t GetPC();

    private:
        uint16_t m_ProgamCounter = 0;
};

extern ProgramCounter programCounter;