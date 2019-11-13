#include "CPUutils.h"
#include <sstream>
#include <string>
#include <iomanip>


std::ostream& operator << (std::ostream& o, const Register8& r) {
	char s[2];
	sprintf(s,"%02X",unsigned(r));
	o << s;
	return o;
}
std::ostream& operator << (std::ostream& o, const DataRegister& r) {
	o << std::uppercase << std::hex << r.X;
	return o;
}


std::string toHex(Register8 i)
{
	std::stringstream stream;
	stream << i;
	return stream.str();
}
std::string toHex(Register16 i)
{
	char s[4];
	sprintf(s,"%04X",i);
	return s;
}

bool isHex(const std::string& s) {
	return s.find_first_not_of("0123456789ABCDEF") == std::string::npos;
}

bool toReg(const char*s,Register8& val) {
	char* p;
	Register8 resultado = (Register8)strtol(s, &p, 16);
	if (*p != 0) {
		return false;
	}

	val = resultado;
	return true;
}
bool toReg(const char*s,Register16& val) {
	char* p;
	Register16 resultado = (Register16)strtol(s, &p, 16);
	if (*p != 0) {
		return false;
	}

	val = resultado;
	return true;
}

