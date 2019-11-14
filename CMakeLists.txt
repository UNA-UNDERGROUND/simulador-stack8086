# CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 3.8)
project (emuASM)



message("------------------------------")

IF(UNIX)
	if(NOT APPLE)
		MESSAGE("detectado linux")
		set(linux true)
	endif()	
elseif(WIN32)
	MESSAGE("detectado windows")
	set(windows true)
ENDIF()




IF(linux)

	find_package(PkgConfig REQUIRED)
	pkg_check_modules(GTKMM gtkmm-3.0)

ENDIF()

message("------------------------------")

# Include sub-projects.
add_subdirectory ("source")
