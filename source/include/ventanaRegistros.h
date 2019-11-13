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
	void on_btnRA_clicked();
	void on_btnRB_clicked();
	void on_btnRC_clicked();
	void on_btnRD_clicked();

	//widgets:

	//botones registros generales
	Gtk::Button* btnRA;
	Gtk::Button* btnRB;
	Gtk::Button* btnRC;
	Gtk::Button* btnRD;

	//botones registros de segmento
	Gtk::Button* btnCS;
	Gtk::Button* btnDS;
	Gtk::Button* btnES;
	Gtk::Button* btnSS;

	//botones registro de indices
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
	

	//texto registros generales
	Gtk::Entry* txtAL;
	Gtk::Entry* txtAH;
	Gtk::Entry* txtBL;
	Gtk::Entry* txtBH;
	Gtk::Entry* txtCL;
	Gtk::Entry* txtCH;
	Gtk::Entry* txtDL;
	Gtk::Entry* txtDH;

	//texto registros de segmento
	Gtk::Entry* txtCS;
	Gtk::Entry* txtDS;
	Gtk::Entry* txtES;
	Gtk::Entry* txtSS;

	//texto registros de segmento
	Gtk::Entry* txtSI;
	Gtk::Entry* txtDI;
	Gtk::Entry* txtBP;
	Gtk::Entry* txtSP;


public:

	virtual ~ventanaRegistros();
};


#pragma warning ( pop )



