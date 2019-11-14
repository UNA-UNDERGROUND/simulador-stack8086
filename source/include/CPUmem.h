#pragma once
#include "CPUdefs.h"


class physicalAddress {
private:
	size_t val;
public:

	physicalAddress(const size_t& value = 0x00000);
	physicalAddress(
		const Register16& segment=0x0000,
		const Register16& address=0x0000);


	const size_t& getAddress() const;

	operator const size_t& () const;
	const physicalAddress operator+(const size_t& o) const;
};

//simulador memoria
//https://wiki.osdev.org/Segmentation

class MemoryArea{
	std::byte memory[0xFFFFF + 1] = {(std::byte)0x00000};

public:

	SingleRegister readAddress8(const physicalAddress& address);
	Register16 readAddress16(const physicalAddress& address);
	DataRegister readAddressR(const physicalAddress& address);

	bool writeAddress(const physicalAddress& address, const Register8& data);
	bool writeAddress(const physicalAddress& address, const Register16& data);
	bool writeAddress(const physicalAddress& address, const DataRegister& data);


};


