#pragma once
#include "CPUdefs.h"


class physicalAddress {
private:
	size_t val;
public:

	physicalAddress(const size_t& value = 0x00000);

	const size_t& getAddress() const;

	operator const size_t& () const;
	const physicalAddress operator+(const size_t& o) const;
};

//simulador memoria
//https://wiki.osdev.org/Segmentation

class MemoryArea{
	std::byte memory[0xFFFFF + 1] = {};

public:

	SingleRegister readAddress8(const physicalAddress& address);
	Register16 readAddress16(const physicalAddress& address);
	DataRegister readAddressR(const physicalAddress& address);

	bool writeAddress(const physicalAddress& address, const Register8& data);
	bool writeAddress(const physicalAddress& address, const Register16& data);
	bool writeAddress(const physicalAddress& address, const DataRegister& data);


};


