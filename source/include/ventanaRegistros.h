#pragma once

#pragma warning( push )
#pragma warning( disable : 4250)



#include <gtkmm/builder.h>
#include <gtkmm/window.h>
#include <gtkmm/entry.h>
#include <gtkmm/button.h>
#include <gtkmm/switch.h>


using gtkbuilder = Glib::RefPtr<Gtk::Builder>;




class ventanaRegistros :public Gtk::Window {


public:

	ventanaRegistros(BaseObjectType* cobject, const gtkbuilder& refGlade);

protected:

	void conectarEventos(const gtkbuilder& constructor);


	//señales de eventos:
	//registros generales
	void on_btnRA_clicked();
	void on_btnRB_clicked();
	void on_btnRC_clicked();
	void on_btnRD_clicked();

	//registros de segmento
	void on_btnRCS_clicked();
	void on_btnRDS_clicked();
	void on_btnRES_clicked();
	void on_btnRSS_clicked();

	//registros de segmento
	void on_btnRSI_clicked();
	void on_btnRDI_clicked();
	void on_btnRBP_clicked();
	void on_btnRSP_clicked();


	//widgets:
	//botones
	//registros generales
	Gtk::Button* btnRA;
	Gtk::Button* btnRB;
	Gtk::Button* btnRC;
	Gtk::Button* btnRD;

	//registros de segmento
	Gtk::Button* btnRCS;
	Gtk::Button* btnRDS;
	Gtk::Button* btnRES;
	Gtk::Button* btnRSS;

	//registro de indices
	Gtk::Button* btnRSI;
	Gtk::Button* btnRDI;
	Gtk::Button* btnRBP;
	Gtk::Button* btnRSP;

	//banderas del procesador
	Gtk::Switch* swCF;
	Gtk::Switch* swZF;
	Gtk::Switch* swSF;
	Gtk::Switch* swOF;
	Gtk::Switch* swPF;
	Gtk::Switch* swAF;
	Gtk::Switch* swIF;
	Gtk::Switch* swDF;
	
	//texto
	//registros generales
	Gtk::Entry* txtAL;
	Gtk::Entry* txtAH;
	Gtk::Entry* txtBL;
	Gtk::Entry* txtBH;
	Gtk::Entry* txtCL;
	Gtk::Entry* txtCH;
	Gtk::Entry* txtDL;
	Gtk::Entry* txtDH;

	//registros de segmento
	Gtk::Entry* txtCS;
	Gtk::Entry* txtDS;
	Gtk::Entry* txtES;
	Gtk::Entry* txtSS;

	//registros de segmento
	Gtk::Entry* txtSI;
	Gtk::Entry* txtDI;
	Gtk::Entry* txtBP;
	Gtk::Entry* txtSP;


public:

	virtual ~ventanaRegistros();
};


#pragma warning ( pop )



