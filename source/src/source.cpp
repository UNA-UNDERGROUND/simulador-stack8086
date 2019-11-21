#include <iostream>
#include <thread>
#include <string>
#include <sstream>

#include "UI.h"

#include "CPUbase.h"
#include "CPUutils.h"
#include "CPUmem.h"



#include <QApplication>
#include <QQmlApplicationEngine>

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	QQmlApplicationEngine engine;
	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
	return app.exec();
}

using std::cout;
using std::endl;
using std::string;




CPU core0;

void limpiar() {
#ifdef WIN32
	system("cls");
#elif __LINUX__
	system("clear");
#endif // WIN32

}

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

bool salir = false;

void terminalThread(int argc, char** argv) {
	std::stringstream s;
	while (!salir){
		s.clear();
		s.str("");
		string linea;
		string comando;
		string registro;
		string destino;
		string val1;
		if (!std::getline(std::cin, linea)){
			return;
		}

		//convertimos la linea a mayusculas
		for (auto& c : linea) c = toupper(c);

		s << linea;
		std::getline(s, comando, ' ');

		
		if (comando == "CLS") {
			limpiar();
		}
		else if (comando == "PUSH" || comando == "POP"){
			s >> std::skipws >> registro;
			for (auto& c : registro) c = toupper(c);
			cpuReg val=cpuReg::DX;//en caso de error no se realizara modificacion
			bool registroValido = true;
			if (registro == "AX") {
				val = cpuReg::AX;
			}
			else if (registro == "BX") {
				val = cpuReg::BX;
			}
			else if (registro == "CX") {
				val = cpuReg::CX;
			}
			else if (registro == "DX") {
				val = cpuReg::DX;
			}
			else{
				registroValido = false;
				cout << "push y pop solo se pueden realizar con -X, ej: push AX" << endl;
			}

			if (registroValido){
				if (comando == "PUSH") {
					core0.push(val);
					cout << "ejecutado push." << endl;
					cout << "valor de SP:" << core0.SP << endl;
				}
				else
				{
					core0.pop(val);
					cout << "ejecutado pop." << endl;
					cout << "valor de SP:" << core0.SP << endl;
				}
			}



		}
		else if (comando == "MOV") {
			std::getline(s, registro, ',');
			s >> std::skipws >> destino;
			for (auto& c : registro) c = toupper(c);
			for (auto& c : destino) c = toupper(c);
			
			cpuReg source = cpuReg::AX;	//en caso de error se copia sobre si mismo
			cpuReg destiny = cpuReg::AX;	
			bool registroValido = true;
			if (registro == "AX") {
				source = cpuReg::AX;
			}
			else if (registro == "BX") {
				source = cpuReg::BX;
			}
			else if (registro == "CX") {
				source = cpuReg::CX;
			}
			else if (registro == "DX") {
				source = cpuReg::DX;
			}
			else {
				registroValido = false;

			}

			if (destino == "AX") {
				destiny = cpuReg::AX;
			}
			else if (destino == "BX") {
				destiny = cpuReg::BX;
			}
			else if (destino == "CX") {
				destiny = cpuReg::CX;
			}
			else if (destino == "DX") {
				destiny = cpuReg::DX;
			}
			else {
				registroValido = false;
				cout << "asegurese de que la sintaxis sea correcta ej: mov AX, CX" << endl;
			}

			if (registroValido) {

				core0.mov(source, destiny);
				cout << "movido valor." << endl;
			}
			else
			{
				cout << "asegurese de que la sintaxis sea correcta ej: mov AX, CX" << endl;
			}



		}
		else if (comando == "") {

		}
		else{
			cout << "comando no encontrado, use un comando valido como: PUSH AX" << endl;
		}




		updateUI();
	}

}


int main2(int argc, char**argv) {

	//core0.SS = 0x100;
	core0.SP = 0x0008;
	

	#ifdef WIN32
	if (!_putenv("GTK_CSD=0")){
		cout << "Usando decoraciones nativas." << endl;
	}
	#endif


	std::thread t1([argc,argv] {
		//no es la manera mas optima, ni la mas sencilla, pero se puede mejorar a futuro
		terminalThread(argc, argv); 
	});

	int val = UIThread(argc, argv);
	bool salir = true;

	t1.join();
	return val;

}