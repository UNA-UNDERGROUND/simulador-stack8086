#include <iostream>



#include "UI.h"

#include "CPUbase.h"
#include "CPUutils.h"
#include "CPUmem.h"


using std::cout;
using std::endl;





CPU core0;
MemoryArea mainMem;

#ifdef WIN32

#include <Windows.h>

int main(int argc, char** argv);
int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR szCmdLine,        
	_In_ int iCmdShow){
	return main(0, {});
}



#endif // windows



int main(int argc, char**argv) {

	physicalAddress dirA(0x0001, 0x0000);
	physicalAddress dirB(0x0000, 0x0010);

	mainMem.writeAddress(dirA,0xABCD);

	//mainMem.writeAddress(0x0000, (std::byte)0xCD); //LOW Address
	//mainMem.writeAddress(0x0001, (std::byte)0xAB); //HI Address


	core0.A = mainMem.readAddress16(dirB);

	#ifdef WIN32
	if (!_putenv("GTK_CSD=0")){
		cout << "Usando decoraciones nativas." << endl;
	}
	#endif



	return UIThread(argc, argv);

}