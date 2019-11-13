#include "ventanaRegistros.h"
#include "CPU.h"
#include "CPUutils.h"


extern CPU core0;


ventanaRegistros::ventanaRegistros(
	BaseObjectType* cobject,
	const gtkbuilder& refGlade): 
	Gtk::Window(cobject){
	conectarEventos(refGlade);

}


void ventanaRegistros::conectarEventos(const gtkbuilder& constructor) {
	//cargar widgets
	//botones de registros generales
	constructor->get_widget("btnRA", btnRA);
	constructor->get_widget("btnRB", btnRB);
	constructor->get_widget("btnRC", btnRC);
	constructor->get_widget("btnRD", btnRD);

	//botones de registros de segmento
	constructor->get_widget("btnRCS", btnRCS);
	constructor->get_widget("btnRDS", btnRDS);
	constructor->get_widget("btnRES", btnRES);
	constructor->get_widget("btnRSS", btnRSS);

	//botones de registros de indice
	constructor->get_widget("btnRSI", btnRSI);
	constructor->get_widget("btnRDI", btnRDI);
	constructor->get_widget("btnRBP", btnRBP);
	constructor->get_widget("btnRSP", btnRSS);

	//texto registros generales
	constructor->get_widget("txtAL", txtAL);
	constructor->get_widget("txtAH", txtAH);

	constructor->get_widget("txtBL", txtBL);
	constructor->get_widget("txtBH", txtBH);

	constructor->get_widget("txtCL", txtCL);
	constructor->get_widget("txtCH", txtCH);

	constructor->get_widget("txtDL", txtDL);
	constructor->get_widget("txtDH", txtDH);

	//texto registros de segmento
	constructor->get_widget("txtCS", txtCS);
	constructor->get_widget("txtDS", txtDS);
	constructor->get_widget("txtES", txtES);
	constructor->get_widget("txtSS", txtSS);
	//texto registros de indice
	constructor->get_widget("txtSI", txtSI);
	constructor->get_widget("txtDI", txtDI);
	constructor->get_widget("txtBP", txtBP);
	constructor->get_widget("txtSP", txtSP);


	//inicializacion registros
	//registros generales
	if (txtAL && txtAH && btnRA){
		btnRA->signal_clicked().connect(
			sigc::mem_fun(*this, &ventanaRegistros::on_btnRA_clicked));
		txtAL->set_text(toHex(core0.A.L));
		txtAH->set_text(toHex(core0.A.H));
	}
	if (txtBL && txtBH && btnRB) {
		btnRB->signal_clicked().connect(
			sigc::mem_fun(*this, &ventanaRegistros::on_btnRB_clicked));
		txtBL->set_text(toHex(core0.B.L));
		txtBH->set_text(toHex(core0.B.H));
	}
	if (txtCL && txtCH && btnRC) {
		btnRC->signal_clicked().connect(
			sigc::mem_fun(*this, &ventanaRegistros::on_btnRC_clicked));
		txtCL->set_text(toHex(core0.C.L));
		txtCH->set_text(toHex(core0.C.H));
	}
	if (txtDL && txtDH && btnRD) {
		btnRD->signal_clicked().connect(
			sigc::mem_fun(*this, &ventanaRegistros::on_btnRD_clicked));
		txtDL->set_text(toHex(core0.D.L));
		txtDH->set_text(toHex(core0.D.H));
	}
	//registros de segmento
	if (txtCS && btnRCS){
		btnRCS->signal_clicked().connect(
			sigc::mem_fun(*this, &ventanaRegistros::on_btnRCS_clicked));
		txtCS->set_text(toHex(core0.CS));
	}
	if (txtDS && btnRDS){
		btnRDS->signal_clicked().connect(
			sigc::mem_fun(*this, &ventanaRegistros::on_btnRDS_clicked));
		txtDS->set_text(toHex(core0.DS));
	}
	if (txtES && btnRES){
		btnRES->signal_clicked().connect(
			sigc::mem_fun(*this, &ventanaRegistros::on_btnRES_clicked));
		txtES->set_text(toHex(core0.ES));
	}
	if (txtSS && btnRSS){
		btnRSS->signal_clicked().connect(
			sigc::mem_fun(*this, &ventanaRegistros::on_btnRCS_clicked));
		txtSS->set_text(toHex(core0.SS));
	}

	//registros de indice



}











ventanaRegistros::~ventanaRegistros() {
}






