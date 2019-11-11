#pragma once

#pragma warning( push )
#pragma warning( disable : 4250)

#include <gtkmm/builder.h>
#include <gtkmm/window.h>
#include <gtkmm/entry.h>
#include <gtkmm/button.h>




using gtkbuilder = Glib::RefPtr<Gtk::Builder>;




class ventanaRegistros :public Gtk::Window {


public:


	ventanaRegistros(BaseObjectType* cobject, const gtkbuilder& refGlade);

protected:

	void conectarEventos();


	//Signal handlers:
	//void on_btnSalir_clicked();
	void on_btnRA_clicked();
	void on_btnRB_clicked();
	void on_btnRC_clicked();
	void on_btnRD_clicked();

	//Member widgets:


	Gtk::Button* btnRA;
	Gtk::Button* btnRB;
	Gtk::Button* btnRC;
	Gtk::Button* btnRD;

	Gtk::Entry* txtAL;
	Gtk::Entry* txtAH;
	Gtk::Entry* txtBL;
	Gtk::Entry* txtBH;
	Gtk::Entry* txtCL;
	Gtk::Entry* txtCH;
	Gtk::Entry* txtDL;
	Gtk::Entry* txtDH;

	gtkbuilder constructor;


public:

	virtual ~ventanaRegistros();
};


#pragma warning ( pop )



