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
        uint16_t GetCurrentOpCode() const;
        uint8_t GetDelayTimer() const;
        uint8_t GetSoundTimer() const;

        void SetDelayTimer(uint8_t value);
        void SetSoundTimer(uint8_t value);
        void UpdateTimers();


    private:
        uint16_t m_CurrentOpCode = 0;
        uint8_t m_DelayTimer = 0;
        uint8_t m_SoundTimer = 0;

};
extern CPU cpu;