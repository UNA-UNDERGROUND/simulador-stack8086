#include "CPUutils.h"
#include <sstream>
#include <string>
#include <iomanip>



//en ambas funciones en VS se requiere un poco mas de espacio para
//evitar que se detecte una corrupcion de memoria en modo depuracion
//sin embargo en linux funciona perfectamente con el espacio adecuado
std::string toHex(Register8 i)
{
	char s[4];
	sprintf(s, "%02X", unsigned(i));
	return s;
}
std::string toHex(Register16 i)
{
	char s[6];
	sprintf(s,"%04X",i);
	return s;
}
std::string toHex(size_t i) {
	char s[6];
	sprintf(s, "%05X", i);
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
bool toVal(const char* s, size_t& val) {
	char* p;
	size_t resultado = (size_t)strtol(s, &p, 16);
	if (*p != 0) {
		return false;
	}

	val = resultado;
	return true;
}

