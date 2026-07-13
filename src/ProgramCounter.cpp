#include "ProgramCounter.h"

ProgramCounter programCounter;

ProgramCounter::ProgramCounter(){

}


void ProgramCounter::IncPC(int i){
    if(i > 0 && i < 3){
        m_ProgamCounter += i;
    }
    
}


uint16_t ProgramCounter::GetPC(){
    return m_ProgamCounter;
}


void ProgramCounter::SetPC(uint16_t address){
    m_ProgamCounter = address;
}