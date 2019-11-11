#pragma once
#include <string>
#include "CPUdefs.h"

std::ostream& operator << (std::ostream& o, const Register8& r);
std::ostream& operator << (std::ostream& o, const DataRegister& r);

bool isHex(const std::string& s);


std::string toHex(Register8 i);
bool toReg(const char* s,Register8& val);

