# CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 3.1)


project (emuASM)
set(CMAKE_CXX_STANDARD 17)

set(GNU_compile_flags
	-fms-extensions
)




set(terminal_src
	src/terminal.cpp
	include/terminal.h
)

set(cpu_src
	src/cpuOperators.cpp
	src/CPUutils.cpp
	src/physicalAddress.cpp
	include/CPU.h
	include/CPUbase.h
	include/CPUdefs.h
	include/CPUmem.h
	include/CPUutils.h
	
)

set(UI_src
	src/UI Loader.cpp
	src/ventanaRegistros.cpp
	src/eventos_ventanaRegistros.cpp
	include/UI.h
	include/ventanaRegistros.h
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
  PRIVATE
	"include/"
)


IF(linux)

	link_directories(${GTKMM_LIBRARY_DIRS})
	include_directories(${GTKMM_INCLUDE_DIRS})
	target_link_libraries(${PROJECT_NAME} ${GTKMM_LIBRARIES})

	if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
		target_compile_options(${PROJECT_NAME} PRIVATE ${GNU_compile_flags})
	endif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")

	set(THREADS_PREFER_PTHREAD_FLAG ON)
		find_package(Threads REQUIRED)
	target_link_libraries(${PROJECT_NAME} Threads::Threads)

ENDIF()


#cmake_minimum_required (VERSION 3.0)
#project (ejemplo)
#add_executable(ejecutable source.cpp)
#install(TARGETS myapp DESTINATION bin)

