#include "ventanaMemoria.h"

#include "CPUutils.h"
#include "CPUbase.h"


extern CPU core0;


ventanaMemoria::ventanaMemoria(
	BaseObjectType* cobject,
	const gtkbuilder& refGlade) :
	Gtk::Window(cobject) {
	this->set_title("memoria del sistema");
	conectarEventos(refGlade);

}


void ventanaMemoria::conectarEventos(const gtkbuilder& constructor) {


	constructor->get_widget("btnEjecutar", btnEjecutar);
	constructor->get_widget("btnIR", btnIR);
	constructor->get_widget("btnArriba", btnArriba);
	constructor->get_widget("btnAbajo", btnAbajo);
	constructor->get_widget("swAccion", swAccion);
	constructor->get_widget("comboRegistro", comboRegistro);

	constructor->get_widget("txtDir1", txtDir[0]);
	constructor->get_widget("txtDir2", txtDir[1]);
	constructor->get_widget("txtDir3", txtDir[2]);
	constructor->get_widget("txtDir4", txtDir[3]);

	constructor->get_widget("txtVal1", txtVal[0]);
	constructor->get_widget("txtVal2", txtVal[1]);
	constructor->get_widget("txtVal3", txtVal[2]);
	constructor->get_widget("txtVal4", txtVal[3]);

	constructor->get_widget("txtDirFisica", txtDirFisica);

	if (btnArriba&&btnAbajo){
		btnArriba->signal_clicked().connect(
			sigc::mem_fun(*this, &ventanaMemoria::on_btnArriba_clicked));
		btnAbajo->signal_clicked().connect(
			sigc::mem_fun(*this, &ventanaMemoria::on_btnAbajo_clicked));
	}

	if (btnEjecutar||swAccion||comboRegistro||txtDirFisica||btnIR){



		for (size_t i = 0; i < 4; i++) {
			if (!txtDir[i] || !txtVal[i])
				return;
		}
	
		btnEjecutar->signal_clicked().connect(
			sigc::mem_fun(*this, &ventanaMemoria::on_btnEjecutar_clicked));
		btnIR->signal_clicked().connect(
			sigc::mem_fun(*this, &ventanaMemoria::on_btnIR_clicked));

		actualizarVista();

	
	}



	


}



void ventanaMemoria::actualizarVista() {
	if (btnEjecutar || swAccion || comboRegistro || txtDirFisica || btnIR) {
		for (size_t i = 0; i < 4; i++) {
			if (!txtDir[i] || !txtVal[i])
				return;
		}

		for (size_t i = 0, j = 0; i < 4; i++) {
			size_t direccion = (pagina * 4 + j)%0xFFFFF;
			txtDir[i]->set_text(toHex(direccion));
			txtVal[i]->set_text(toHex(core0.mainMemory.readAddress16(direccion)));
			j += 2;
		}
	}
}



void ventanaMemoria::setVentanaRegistros(ventanaRegistros* v) {
	vRegistros = v;
}





ventanaMemoria::~ventanaMemoria() {
}






