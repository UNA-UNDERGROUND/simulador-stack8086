#include <iostream>



#include "UI.h"

#include "CPUbase.h"
#include "CPUutils.h"
#include "CPUmem.h"


using std::cout;
using std::endl;





CPU core0;

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

	core0.SS = 0x100;
	core0.SP = 0xFFFE;
	

	#ifdef WIN32
	if (!_putenv("GTK_CSD=0")){
		cout << "Usando decoraciones nativas." << endl;
	}
	#endif



	return UIThread(argc, argv);

}