#include "cpu.h"
#include <ostream>

namespace std {
	ostream& operator << (ostream& o, const Register8& r) {
		o << unsigned(r);
		return o;
	}
}



