#include "ventanaRegistros.h"
#include "CPU.h"
#include "CPUutils.h"


extern CPU core0;


ventanaRegistros::ventanaRegistros(BaseObjectType* cobject, const gtkbuilder& refGlade) : Gtk::Window(cobject),
constructor(refGlade) {
	conectarEventos();

}


void ventanaRegistros::conectarEventos() {

	constructor->get_widget("btnRA", btnRA);
	constructor->get_widget("btnRB", btnRB);
	constructor->get_widget("btnRC", btnRC);
	constructor->get_widget("btnRD", btnRD);

	constructor->get_widget("txtAL", txtAL);
	constructor->get_widget("txtAH", txtAH);

	constructor->get_widget("txtBL", txtBL);
	constructor->get_widget("txtBH", txtBH);

	constructor->get_widget("txtCL", txtCL);
	constructor->get_widget("txtCH", txtCH);

	constructor->get_widget("txtDL", txtDL);
	constructor->get_widget("txtDH", txtDH);
	if (txtAL && txtAH && btnRA){
		btnRA->signal_clicked().connect(sigc::mem_fun(*this, &ventanaRegistros::on_btnRA_clicked));
		txtAL->set_text(toHex(core0.A.L));
		txtAH->set_text(toHex(core0.A.H));
	}
	if (txtBL && txtBH && btnRB) {
		btnRB->signal_clicked().connect(sigc::mem_fun(*this, &ventanaRegistros::on_btnRB_clicked));
		txtBL->set_text(toHex(core0.B.L));
		txtBH->set_text(toHex(core0.B.H));
	}
	if (txtCL && txtCH && btnRC) {
		btnRC->signal_clicked().connect(sigc::mem_fun(*this, &ventanaRegistros::on_btnRC_clicked));
		txtCL->set_text(toHex(core0.C.L));
		txtCH->set_text(toHex(core0.C.H));
	}
	if (txtDL && txtDH && btnRD) {
		btnRD->signal_clicked().connect(sigc::mem_fun(*this, &ventanaRegistros::on_btnRD_clicked));
		txtDL->set_text(toHex(core0.D.L));
		txtDH->set_text(toHex(core0.D.H));
	}



}











ventanaRegistros::~ventanaRegistros() {
}






