#include "CPUmem.h"

physicalAddress::physicalAddress(const size_t& value) : 
	val(value % 0xFFFFF) 
{
}
physicalAddress::physicalAddress(
	const Register16& segment,
	const Register16& address):
	val(segment<<4)
{
	val+=address;
	val%=0xFFFFF;	

}

const size_t& physicalAddress::getAddress() const {
	return val;
}


physicalAddress::operator const size_t& () const{
	return val;
}
const physicalAddress physicalAddress::operator+(const size_t& o) const{
	return physicalAddress(val + o);
}

