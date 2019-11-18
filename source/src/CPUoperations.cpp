#include "CPUbase.h"






bool CPU::push(const cpuReg& reg) {
	Register16 val;
	SP -= 2;

	switch (reg) {
	case cpuReg::AX: {
		val = A.X;
		break;
	}
	case cpuReg::BX: {
		val = B.X;
		break;
	}
	case cpuReg::CX: {
		val = C.X;
		break;
	}
	case cpuReg::DX: {
		val = D.X;
		break;
	}
	default:
		return false;//no realizar nada
	}
	return mainMemory.writeAddress(physicalAddress(SS, SP), val);

}
bool CPU::pop(const cpuReg& reg) {
	Register16 val = mainMemory.readAddress16(physicalAddress(SS, SP));
	SP += 2;
	switch (reg) {
	case cpuReg::AX: {
		A.X = val;
		break;
	}
	case cpuReg::BX: {
		B.X = val;
		break;
	}
	case cpuReg::CX: {
		C.X = val;
		break;
	}
	case cpuReg::DX: {
		D.X = val;
		break;
	}
	default:
		return false;
	}
	//pop no elimina la memoria
	//mainMemory.writeAddress(physicalAddress(SS, SP), 0x0000);
	return true;
}


bool CPU::mov(const cpuReg& destiny, const cpuReg& source) {

	if (destiny <= cpuReg::DX&& source <= cpuReg::DX) {
		Register16 val;
		switch (source) {
		case cpuReg::AX: {
			val = A.X;
			break;
		}
		case cpuReg::BX: {
			val = B.X;
			break;
		}
		case cpuReg::CX: {
			val = C.X;
			break;
		}
		case cpuReg::DX: {
			val = D.X;
			break;
		}
		default:
			return false;//no realizar nada
		}
		
		switch (destiny) {
		case cpuReg::AX: {
			A.X = val;
			break;
		}
		case cpuReg::BX: {
			B.X = val;
			break;
		}
		case cpuReg::CX: {
			C.X = val;
			break;
		}
		case cpuReg::DX: {
			D.X = val;
			break;
		}
		default:
			return false;
		}
		return true;
	}
	else if(destiny > cpuReg::DX&& source > cpuReg::DX)
	{
		Register8 val;
		switch (source) {
		case cpuReg::AH: {
			val = A.H;
			break;
		}
		case cpuReg::AL: {
			val = A.L;
			break;
		}
		case cpuReg::BH: {
			val = B.H;
			break;
		}
		case cpuReg::BL: {
			val = B.L;
			break;
		}
		case cpuReg::CH: {
			val = C.H;
			break;
		}
		case cpuReg::CL: {
			val = C.L;
			break;
		}
		case cpuReg::DH: {
			val = D.H;
			break;
		}
		case cpuReg::DL: {
			val = D.L;
			break;
		}
		default:
			return false;//no realizar nada
		}

		switch (destiny) {
		case cpuReg::AH: {
			A.H = val;
			break;
		}
		case cpuReg::AL: {
			A.L = val;
			break;
		}
		case cpuReg::BH: {
			B.H = val;
			break;
		}
		case cpuReg::BL: {
			B.L = val;
			break;
		}
		case cpuReg::CH: {
			C.H = val;
			break;
		}
		case cpuReg::CL: {
			C.L = val;
			break;
		}
		case cpuReg::DH: {
			D.H = val;
			break;
		}
		case cpuReg::DL: {
			D.L = val;
			break;
		}

		default:
			return false;
		}
		return true;
	}

	return false;

}

bool CPU::mov(const cpuReg& destiny, const Register16& value) {
	Register16 val = value;
	switch (destiny) {
	case cpuReg::AX: {
		A.X = val;
		break;
	}
	case cpuReg::BX: {
		B.X = val;
		break;
	}
	case cpuReg::CX: {
		C.X = val;
		break;
	}
	case cpuReg::DX: {
		D.X = val;
		break;
	}
	default:
		return false;
	}
	//pop no elimina la memoria
	//mainMemory.writeAddress(physicalAddress(SS, SP), 0x0000);
	return true;
}
bool CPU::mov(const cpuReg& destiny, const Register8&  value) {							//registro-valor (8 bits)

	Register8 val = value;

	switch (destiny) {
	case cpuReg::AH: {
		A.H = val;
		break;
	}
	case cpuReg::AL: {
		A.L = val;
		break;
	}
	case cpuReg::BH: {
		B.H = val;
		break;
	}
	case cpuReg::BL: {
		B.L = val;
		break;
	}
	case cpuReg::CH: {
		C.H = val;
		break;
	}
	case cpuReg::CL: {
		C.L = val;
		break;
	}
	case cpuReg::DH: {
		D.H = val;
		break;
	}
	case cpuReg::DL: {
		D.L = val;
		break;
	}

	default:
		return false;
	}
	return true;
}
bool CPU::mov(const cpuReg& destiny, const Register16& segment, const Register16 index) {	//registro-direccion (segmento,indice)

	if (destiny <= cpuReg::DX){
		Register16 val = mainMemory.readAddress16(physicalAddress(segment, index));
		return mov(destiny, val);
	}
	else if (destiny < cpuReg::DX){
		Register8 val = mainMemory.readAddress8(physicalAddress(segment, index));
		return mov(destiny, val);
	}
	return false;
}
