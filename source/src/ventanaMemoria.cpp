#include "ventanaMemoria.h"

#include "CPUutils.h"
#include "CPUmem.h"
#include <gtkmm.h>

extern MemoryArea mainMem;


ventanaMemoria::ventanaMemoria(
	BaseObjectType* cobject,
	const gtkbuilder& refGlade) :
	Gtk::Window(cobject) {
	this->set_title("memoria del sistema");
	conectarEventos(refGlade);

}


void ventanaMemoria::conectarEventos(const gtkbuilder& constructor) {


	constructor->get_widget("tvDirecciones", tvDirecciones);


	if (tvDirecciones){
		refStore = Gtk::ListStore::create(storeMemoria);
		tvDirecciones->set_model(refStore);

		//Fill the TreeView's model
		for (size_t i = 0; i < 10; i++){
			Gtk::TreeModel::Row row = *(refStore->append());
			row[storeMemoria.colDireccion] = "abc";
			row[storeMemoria.colValor] = "abc";
		}

		tvDirecciones->append_column("ID", storeMemoria.colDireccion);
		tvDirecciones->append_column("Name", storeMemoria.colValor);

	}


}











ventanaMemoria::~ventanaMemoria() {
}






