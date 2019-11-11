#include <iostream>
#include <thread>
#include <chrono>


#include "UI.h"

#include "../include/CPUbase.h"
#include "../include/CPUutils.h"
#include "../include/terminal.h"
#include "../include/CPUmem.h"


using std::cout;
using std::endl;





CPU core0;
MemoryArea mainMem;

void mostrarInfoCPU() {
	cout << "---------------------------------------" << endl;
	cout << "AX: " << core0.A << endl;
	cout << "AL: " << "0x" << core0.A.L << endl;
	cout << "AH: " << "0x" << core0.A.H << endl;
	cout << "---------------------------------------" << endl;

	cout << "---------------------------------------" << endl;
	cout << "BX: " << core0.B << endl;
	cout << "BL: " << "0x" << core0.B.L << endl;
	cout << "BH: " << "0x" << core0.B.H << endl;
	cout << "---------------------------------------" << endl;

	cout << "---------------------------------------" << endl;
	cout << "CX: " << core0.C << endl;
	cout << "CL: " << "0x" << core0.C.L << endl;
	cout << "CH: " << "0x" << core0.C.H << endl;
	cout << "---------------------------------------" << endl;

	cout << "---------------------------------------" << endl;
	cout << "DX: " << core0.D << endl;
	cout << "DL: " << "0x" << core0.D.L << endl;
	cout << "DH: " << "0x" << core0.D.H << endl;
	cout << "---------------------------------------" << endl;
}



int main(int argc, char**argv) {

	mainMem.writeAddress(0x0000,0xABCD);

	//mainMem.writeAddress(0x0000, (std::byte)0xCD); //LOW Address
	//mainMem.writeAddress(0x0001, (std::byte)0xAB); //HI Address


	core0.A = mainMem.readAddress16(0x0000);

	#ifdef WIN32
	if (!_putenv("GTK_CSD=0")){
		cout << "Usando decoraciones nativas." << endl;
	}
	#endif

	std::thread([&] {
		terminalThread(argc, argv);
	}).detach();

	return UIThread(argc, argv);

}