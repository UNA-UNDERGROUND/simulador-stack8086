# CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 3.1)


project (emuASM)
set(CMAKE_CXX_STANDARD 17)


set(terminal_src
	src/Terminal.cpp
)

set(cpu_src
	src/cpuOperators.cpp
	src/CPUutils.cpp
	src/physicalAddress.cpp
)

set(UI_src
	UI Loader.cpp
	${ventanaRegistros}
	ventanaRegistros.cpp
	src/eventos_ventanaRegistros.cpp
)


set(src 	
	src/source.cpp
	${terminal_src}
	${cpu_src}
	${ui_src}
)

add_executable(${PROJECT_NAME} ${src})


target_include_directories(
  ${PROJECT_NAME}
  PUBLIC
	"include/"
)


IF(linux)

	link_directories(${GTKMM_LIBRARY_DIRS})
	include_directories(${GTKMM_INCLUDE_DIRS})
	target_link_libraries(${PROJECT_NAME} ${GTKMM_LIBRARIES})

ENDIF()



#cmake_minimum_required (VERSION 3.0)
#project (ejemplo)
#add_executable(ejecutable source.cpp)
#install(TARGETS myapp DESTINATION bin)

