#include "CPUbase.h"






void CPU::push(const cpuReg& val) {
	switch (val) {
	case AX: {
		mainMemory.writeAddress(physicalAddress(SS, SP), A.X);
		SP -= 2;
		break;
	}
	case BX: {
		mainMemory.writeAddress(physicalAddress(SS, SP), B.X);
		SP -= 2;
		break;
	}
	case CX: {
		mainMemory.writeAddress(physicalAddress(SS, SP), C.X);
		SP -= 2;
		break;
	}
	case DX: {
		mainMemory.writeAddress(physicalAddress(SS, SP), D.X);
		SP -= 2;
		break;
	}
	case AL: {
		mainMemory.writeAddress(physicalAddress(SS, SP), A.L);
		SP -= 1;
		break;
	}
	case AH: {
		mainMemory.writeAddress(physicalAddress(SS, SP), A.H);
		SP -= 1;
		break;
	}
	case BL: {
		mainMemory.writeAddress(physicalAddress(SS, SP), B.L);
		SP -= 1;
		break;
	}
	case BH: {
		mainMemory.writeAddress(physicalAddress(SS, SP), B.H);
		SP -= 1;
		break; 
	}
	case CL: {
		mainMemory.writeAddress(physicalAddress(SS, SP), C.L);
		SP -= 1;
		break;
	}
	case CH: {
		mainMemory.writeAddress(physicalAddress(SS, SP), C.H);
		SP -= 1;
		break;
	}
	case DL: {
		mainMemory.writeAddress(physicalAddress(SS, SP), D.L);
		SP -= 1;
		break;}
	case DH: {
		mainMemory.writeAddress(physicalAddress(SS, SP), D.H);
		SP -= 1;
		break;
	}
	default:
		return;

	}
}
void CPU::pop(const cpuReg& val) {
	switch (val) {
	case AX: {
		A.X = mainMemory.readAddress16(physicalAddress(SS, SP) - 2);
		SP += 2;
		break;
	}
	case BX: {
		B.X = mainMemory.readAddress16(physicalAddress(SS, SP) - 2);
		SP += 2;
		break;
	}
	case CX: {
		C.X = mainMemory.readAddress16(physicalAddress(SS, SP) - 2);
		SP += 2;
		break;
	}
	case DX: {
		D.X = mainMemory.readAddress16(physicalAddress(SS, SP) - 2);
		SP += 2;
		break;
	}
	case AH: {
		A.H = mainMemory.readAddress8(physicalAddress(SS, SP) - 2);
		SP += 1;
		break;
	}
	case AL: {
		A.L = mainMemory.readAddress8(physicalAddress(SS, SP) - 2);
		SP += 1;
		break;
	}
	case BH: {
		B.H = mainMemory.readAddress8(physicalAddress(SS, SP) - 2);
		SP += 1;
		break;
	}
	case BL: {
		B.L = mainMemory.readAddress8(physicalAddress(SS, SP) - 2);
		SP += 1;
		break;
	}
	case CH: {
		C.H = mainMemory.readAddress8(physicalAddress(SS, SP) - 2);
		SP += 1;
		break;
	}
	case CL: {
		C.L = mainMemory.readAddress8(physicalAddress(SS, SP) - 2);
		SP += 1;
		break;
	}
	case DH: {
		D.H = mainMemory.readAddress8(physicalAddress(SS, SP) - 2);
		SP += 1;
		break;
	}
	case DL: {
		D.L = mainMemory.readAddress8(physicalAddress(SS, SP) - 2);
		SP += 1;
		break;
	}

	default:
		return;
	}
	mainMemory.writeAddress(physicalAddress(SS, SP), 0x0000);
}

