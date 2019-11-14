#include "ventanaRegistros.h"

#include "CPU.h"
#include "CPUutils.h"


extern CPU core0;


void updateRegister(Gtk::Entry& txtL, Gtk::Entry& txtH, DataRegister& R) {
	toReg(txtL.get_text().c_str(), R.L);
	toReg(txtH.get_text().c_str(), R.H);
	txtL.set_text(toHex(R.L));
	txtH.set_text(toHex(R.H));
}
void updateRegister(Gtk::Entry& txtR, Register16& R) {
	toReg(txtR.get_text().c_str(), R);
	txtR.set_text(toHex(R));
}

//registros generales
void ventanaRegistros::on_btnRA_clicked() {
	updateRegister(*txtAL, *txtAH, core0.A);
}
void ventanaRegistros::on_btnRB_clicked() {
	updateRegister(*txtBL, *txtBH, core0.B);
}
void ventanaRegistros::on_btnRC_clicked() {
	updateRegister(*txtCL, *txtCH, core0.C);
}
void ventanaRegistros::on_btnRD_clicked() {
	updateRegister(*txtDL, *txtDH, core0.D);
}
//registros de segmento
void ventanaRegistros::on_btnRCS_clicked() {
	updateRegister(*txtCS, core0.CS);
}
void ventanaRegistros::on_btnRDS_clicked() {
	updateRegister(*txtDS, core0.DS);
}
void ventanaRegistros::on_btnRES_clicked() {
	updateRegister(*txtES, core0.ES);
}
void ventanaRegistros::on_btnRSS_clicked() {
	updateRegister(*txtSS, core0.SS);
}

//registros de indice
void ventanaRegistros::on_btnRSI_clicked() {
	updateRegister(*txtSI, core0.SI);
}
void ventanaRegistros::on_btnRDI_clicked() {
	updateRegister(*txtDI, core0.DI);
}
void ventanaRegistros::on_btnRBP_clicked() {
	updateRegister(*txtBP, core0.BP);
}
void ventanaRegistros::on_btnRSP_clicked() {
	updateRegister(*txtSP, core0.SP);
}

//banderas del CPU
void ventanaRegistros::on_swCF_switch(){
	core0.flags.CF=swCF->get_active();
}
void ventanaRegistros::on_swZF_switch(){
	core0.flags.ZF=swZF->get_active();
}
void ventanaRegistros::on_swSF_switch(){
	core0.flags.SF=swSF->get_active();
}
void ventanaRegistros::on_swOF_switch(){
	core0.flags.OF=swOF->get_active();
}
void ventanaRegistros::on_swPF_switch(){
	core0.flags.PF=swPF->get_active();
}
void ventanaRegistros::on_swAF_switch(){
	core0.flags.AF=swAF->get_active();
}
void ventanaRegistros::on_swIF_switch(){
	core0.flags.IF=swIF->get_active();
}
void ventanaRegistros::on_swDF_switch(){
	core0.flags.DF=swDF->get_active();
}

