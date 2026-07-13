#include "IndexRegister.h"

IndexRegister indexRegister;

IndexRegister::IndexRegister(){

}


uint16_t IndexRegister::Get(){
    return m_IndexRegister;
}


void IndexRegister::Set(uint16_t v){
    m_IndexRegister = v;
}


