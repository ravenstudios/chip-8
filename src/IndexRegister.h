#pragma once
#include <cstdint>


class IndexRegister{
    public:
        IndexRegister();
        uint16_t Get();
        void Set(uint16_t v);
    private:
        uint16_t m_IndexRegister = 0;
};

extern IndexRegister indexRegister;