#include "ventanaMemoria.h"
#include "ventanaRegistros.h"

#include "CPU.h"
#include "CPUutils.h"
#include "ventanaRegistros.h"

extern CPU core0;



void ventanaMemoria::on_btnEjecutar_clicked() {
	//asumimos que la posicion equivale a la lista enumerada en cpuReg
	if (swAccion->get_active()){//pop
		int val = comboRegistro->get_active_row_number();

		if (val >= 0) {
			core0.pop((cpuReg)val);
		}
	}
	else//push
	{
		int val = comboRegistro->get_active_row_number();

		if (val>=0){
			core0.push((cpuReg)val);
		}

		

	}

	actualizarVista();
	if (vRegistros){
		vRegistros->actualizarVista();
	}
}

void ventanaMemoria::on_btnIR_clicked() {
	size_t val;
	if (toVal(txtDirFisica->get_text().c_str(),val)){
		if (val <= 0xFFFFF){
			pagina = val / 4;
		}
		actualizarVista();
	}
}

void ventanaMemoria::on_btnArriba_clicked() {
	pagina++;
	actualizarVista();
}


void ventanaMemoria::on_btnAbajo_clicked() {
	pagina--;
	actualizarVista();
}

