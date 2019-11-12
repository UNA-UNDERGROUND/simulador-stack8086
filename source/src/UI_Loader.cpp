#include "ventanaRegistros.h"


#pragma warning( push )
#pragma warning( disable : 4250)


#include <gtkmm/builder.h>
#include <gtkmm/application.h>
#include <glibmm/markup.h>
#include <glibmm/fileutils.h>

#pragma warning( pop )


#include <iostream>

using std::cerr;
using std::endl;

int UIThread(int argc, char** argv) {

	try {
	
		auto app = Gtk::Application::create(argc, argv, "org.gtkmm.emuASM.base");

		gtkbuilder constructor = Gtk::Builder::create_from_file("emuASM.glade");
		ventanaRegistros* ventana = nullptr;
		constructor->get_widget_derived("ventana", ventana);
		//constructor->get_widget("ventana", ventana);


		return app->run(*ventana);

	}
	catch (Glib::FileError & err) {
		std::cerr << "Error al cargar el archivo: " << err.what() << endl;
	}
	catch (const Glib::MarkupError & ex) {
		std::cerr << "Error de formato: " << ex.what() << std::endl;
		return 1;
	}
	catch (const Gtk::BuilderError & ex) {
		std::cerr << "BuilderError: " << ex.what() << std::endl;
		return 1;
	}

	return 0;

}