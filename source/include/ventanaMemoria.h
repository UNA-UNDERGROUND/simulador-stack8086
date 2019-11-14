#pragma once

#pragma warning( push )
#pragma warning( disable : 4250)



#include <gtkmm/builder.h>
#include <gtkmm/window.h>
#include <gtkmm/entry.h>
#include <gtkmm/button.h>
#include <gtkmm/treeview.h>
#include <gtkmm/liststore.h>
#include <gtkmm.h>
#include <gtkmm/treeviewcolumn.h >


using gtkbuilder = Glib::RefPtr<Gtk::Builder>;




class ventanaMemoria :public Gtk::Window {


public:

	ventanaMemoria(BaseObjectType* cobject, const gtkbuilder& refGlade);

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

	Gtk::TreeView* tvDirecciones;
	mColumnas storeMemoria;
	Glib::RefPtr<Gtk::ListStore> refStore;

public:

	virtual ~ventanaMemoria();
};


#pragma warning ( pop )



