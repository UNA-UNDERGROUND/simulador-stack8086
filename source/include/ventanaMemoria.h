#pragma once

#pragma warning( push )
#pragma warning( disable : 4250)



#include <gtkmm/builder.h>
#include <gtkmm/window.h>
#include <gtkmm/entry.h>
#include <gtkmm/button.h>
#include <gtkmm.h>
#include <ventanaRegistros.h>



using gtkbuilder = Glib::RefPtr<Gtk::Builder>;




class ventanaMemoria :public Gtk::Window {


public:

	ventanaMemoria(BaseObjectType* cobject, const gtkbuilder& refGlade);
	void actualizarVista();
	void setVentanaRegistros(ventanaRegistros* v);

private:
	class mColumnas : public Gtk::TreeModel::ColumnRecord
	{
	public:

		mColumnas(){
			add(colDireccion);
			add(colValor);
	
		}

		Gtk::TreeModelColumn<Glib::ustring> colDireccion;
		Gtk::TreeModelColumn<Glib::ustring> colValor;
	};


	void conectarEventos(const gtkbuilder& constructor);



	void on_btnEjecutar_clicked();
	void on_btnIR_clicked();
	void on_btnArriba_clicked();
	void on_btnAbajo_clicked();

	Gtk::Button* btnEjecutar;
	Gtk::Button* btnIR;
	Gtk::Button* btnArriba;
	Gtk::Button* btnAbajo;


	Gtk::Switch* swAccion;
	Gtk::ComboBox* comboRegistro;

	Gtk::Entry* txtDir[4];
	Gtk::Entry* txtVal[4];
	Gtk::Entry* txtDirFisica;

	ventanaRegistros* vRegistros;

	size_t pagina = 0;

public:

	virtual ~ventanaMemoria();
};


#pragma warning ( pop )



