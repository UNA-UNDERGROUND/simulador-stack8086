#pragma once

#include <cstdint>
#include <cstddef>




using Register8			= std::byte;
using Register16		= uint16_t;

using SingleRegister	= Register8;
using GeneralRegister	= Register16;

using IndexRegister		= Register16;
using SegmentRegister	= Register16;
using IPRegister		= Register16;

//no vale la pena optimizar en campos de bits
//explicacion: https://devblogs.microsoft.com/oldnewthing/20081126-00/?p=20073
union flagsRegister{
	bool flag[16];
	struct{
		bool CF;  // carry
		bool R1;  // reservado, siempre 1
		bool PF;  // paridad
		bool R3;  // reservado
		bool AF;  // ajuste carry
		bool R5;  // reservado
		bool ZF;  // zero
		bool SF;  // signo
		bool TF;  // trampa
		bool IF;  // interrupciones
		bool DF;  // direccion 1 = abajo 0 = arriba
		bool OF;  // overflow
		bool R12; // reservado, siempre 1
		bool R13; // reservado, siempre 1
		bool R14; // reservado, siempre 1
		bool R15; // reservado, siempre 1
	};
	flagsRegister(void) :
		CF(false),
		R1(true),
		PF(false),
		R3(false),
		AF(false),
		R5(false),
		ZF(false),
		SF(false),
		TF(false),
		IF(false),
		DF(false),
		OF(false),
		R12(true),
		R13(true),
		R14(true),
		R15(true)
	{

	}
};



union DataRegister {
	struct {
		SingleRegister L;
		SingleRegister H;
	};
	Register16 X;
	DataRegister(void) = default;
	DataRegister(const Register16& R) {
		H = (SingleRegister)(R >> (4 * 2));
		L = (SingleRegister)(R);
	}
	DataRegister(const Register8& L, const Register8& H) {
		this->H = H;
		this->L = L;
	}

};




