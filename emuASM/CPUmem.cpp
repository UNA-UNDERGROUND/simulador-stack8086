#include "CPUmem.h"

Register8 MemoryArea::readAddress8(const physicalAddress& address) {
	return (Register8)memory[address];

}
Register16 MemoryArea::readAddress16(const physicalAddress& address) {
	return readAddressR(address).X;
}
DataRegister MemoryArea::readAddressR(const physicalAddress& address) {
	return DataRegister(readAddress8(address), readAddress8(address + (size_t)1));
}

bool MemoryArea::writeAddress(const physicalAddress& address, const Register8& data) {
	memory[address] = data;
	return true;
}
bool MemoryArea::writeAddress(const physicalAddress& address, const Register16& data) {
	return writeAddress(address, DataRegister(data));
}
bool MemoryArea::writeAddress(const physicalAddress& address, const DataRegister& data) {
	if (address <= (0xFFFF - 1)) {
		memory[address] = data.L;
		memory[address + (size_t)1] = data.H;
		return true;
	}
	return false;
}



