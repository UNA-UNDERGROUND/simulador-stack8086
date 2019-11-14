#pragma once
#include "CPUdefs.h"
#include "CPUmem.h"

//https://www.tutorialspoint.com/assembly_programming/assembly_registers.htm
//http://www.exa.unicen.edu.ar/catedras/progens/materiales/arquitectura%208086.pdf
//https://en.wikipedia.org/wiki/X86_instruction_listings#Original_8086/8088_instructions


enum cpuReg{
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

	void push(const cpuReg& val);
	void pop(const cpuReg& val);


};

using CPU = struct CPU;