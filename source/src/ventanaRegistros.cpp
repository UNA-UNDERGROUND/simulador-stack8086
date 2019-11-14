#include "ventanaRegistros.h"
#include "CPU.h"
#include "CPUutils.h"


extern CPU core0;


ventanaRegistros::ventanaRegistros(
	BaseObjectType* cobject,
	const gtkbuilder& refGlade): 
	Gtk::Window(cobject){
	this->set_title("registros del CPU");
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
	constructor->get_widget("btnRSP", btnRSP);

	//interruptores de banderas
	constructor->get_widget("swCF", swCF);
	constructor->get_widget("swZF", swZF);
	constructor->get_widget("swSF", swSF);
	constructor->get_widget("swOF", swOF);
	constructor->get_widget("swPF", swPF);
	constructor->get_widget("swAF", swAF);
	constructor->get_widget("swIF", swIF);
	constructor->get_widget("swDF", swDF);

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

	//cargar ventanaMemoria
	constructor->get_widget("ventanaMemoria", ventanaMemoria);
	constructor->get_widget("btnMostrar", btnMostrar);

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
	if (txtSI && btnRSI){
		btnRSI->signal_clicked().connect(
			sigc::mem_fun(*this, &ventanaRegistros::on_btnRSI_clicked));
		txtSI->set_text(toHex(core0.SI));
	}
	if (txtDI && btnRDI){
		btnRDI->signal_clicked().connect(
			sigc::mem_fun(*this, &ventanaRegistros::on_btnRDI_clicked));
		txtDI->set_text(toHex(core0.DI));
	}
	if (txtBP && btnRBP){
		btnRBP->signal_clicked().connect(
			sigc::mem_fun(*this, &ventanaRegistros::on_btnRBP_clicked));
		txtBP->set_text(toHex(core0.BP));
	}
	if (txtSP && btnRSP){
		btnRSP->signal_clicked().connect(
			sigc::mem_fun(*this, &ventanaRegistros::on_btnRSP_clicked));
		txtSP->set_text(toHex(core0.SP));
	}

	//banderas del CPU
	if(swCF){
		swCF->set_active(core0.flags.CF);
		swCF->property_active()
		.signal_changed().connect(
			sigc::mem_fun(
				*this, 
				&ventanaRegistros::on_swCF_switch));
	}
	if(swZF){
		swZF->set_active(core0.flags.ZF);
		swZF->property_active()
		.signal_changed().connect(
			sigc::mem_fun(
				*this, 
				&ventanaRegistros::on_swZF_switch));
	}
	if(swSF){
		swSF->set_active(core0.flags.SF);
		swSF->property_active()
		.signal_changed().connect(
			sigc::mem_fun(
				*this, 
				&ventanaRegistros::on_swSF_switch));
	}
	if(swOF){
		swOF->set_active(core0.flags.OF);
		swOF->property_active()
		.signal_changed().connect(
			sigc::mem_fun(
				*this, 
				&ventanaRegistros::on_swOF_switch));
	}
	if(swPF){
		swPF->set_active(core0.flags.PF);
		swPF->property_active()
		.signal_changed().connect(
			sigc::mem_fun(
				*this, 
				&ventanaRegistros::on_swPF_switch));
	}
	if(swAF){
		swAF->set_active(core0.flags.AF);
		swAF->property_active()
		.signal_changed().connect(
			sigc::mem_fun(
				*this, 
				&ventanaRegistros::on_swAF_switch));
	}
	if(swIF){
		swIF->set_active(core0.flags.IF);
		swIF->property_active()
		.signal_changed().connect(
			sigc::mem_fun(
				*this, 
				&ventanaRegistros::on_swIF_switch));
	}
	if(swDF){
		swDF->set_active(core0.flags.DF);
		swDF->property_active()
		.signal_changed().connect(
			sigc::mem_fun(
				*this, 
				&ventanaRegistros::on_swDF_switch));
	}
	

	if (ventanaMemoria && btnMostrar){
		btnMostrar->signal_clicked().connect(
			sigc::mem_fun(*this, &ventanaRegistros::on_btnMostrar_clicked));
	}



}











ventanaRegistros::~ventanaRegistros() {
}






