#pragma once
#include "CPUdefs.h"
#include "CPUmem.h"

//https://www.tutorialspoint.com/assembly_programming/assembly_registers.htm
//http://www.exa.unicen.edu.ar/catedras/progens/materiales/arquitectura%208086.pdf
//https://en.wikipedia.org/wiki/X86_instruction_listings#Original_8086/8088_instructions


enum class cpuReg{
	AX,
	BX,
	CX,
	DX,
	AL,
	AH,
	BL,
	BH,
	CL,
	CH,
	DL,
	DH
};

struct CPU {

	DataRegister A;
	DataRegister B;
	DataRegister C;
	DataRegister D;


	IndexRegister SI;
	IndexRegister DI;
	IndexRegister BP;
	IndexRegister SP;

	IPRegister IP;

	SegmentRegister CS;
	SegmentRegister DS;
	SegmentRegister ES;
	SegmentRegister SS;

	flagsRegister flags;

	MemoryArea mainMemory;

	bool push(const cpuReg& val);
	bool pop(const cpuReg& val);
	bool mov(const cpuReg& destiny, const cpuReg& source);								//registro-registro
	bool mov(const cpuReg& destiny, const Register16& value);							//registro-valor (16 bits)
	bool mov(const cpuReg& destiny, const Register8& value);							//registro-valor (8 bits)
	bool mov(const cpuReg& destiny, const Register16& segment, const Register16 index);	//registro-direccion (segmento,indice)

};

using CPU = struct CPU;