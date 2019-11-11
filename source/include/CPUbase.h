#pragma once
#include "CPUdefs.h"

//https://www.tutorialspoint.com/assembly_programming/assembly_registers.htm
//http://www.exa.unicen.edu.ar/catedras/progens/materiales/arquitectura%208086.pdf
//https://en.wikipedia.org/wiki/X86_instruction_listings#Original_8086/8088_instructions

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

};

using CPU = struct CPU;