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


void::ventanaRegistros::on_btnRA_clicked() {
	updateRegister(*txtAL, *txtAH, core0.A);
}
void::ventanaRegistros::on_btnRB_clicked() {
	updateRegister(*txtBL, *txtBH, core0.B);
}
void::ventanaRegistros::on_btnRC_clicked() {
	updateRegister(*txtCL, *txtCH, core0.C);
}
void::ventanaRegistros::on_btnRD_clicked() {
	updateRegister(*txtDL, *txtDH, core0.D);
}
