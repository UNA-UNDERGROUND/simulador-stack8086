# CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 3.1)


project (emuASM CXX)
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
	src/CPUmem.cpp
	include/CPU.h
	include/CPUbase.h
	include/CPUdefs.h
	include/CPUmem.h
	include/CPUutils.h
	
)

set(UI_src
	src/UI_Loader.cpp
	src/ventanaRegistros.cpp
	src/eventos_ventanaRegistros.cpp
	include/UI.h
	include/ventanaRegistros.h
	
)


set(src 	
	src/source.cpp
	${terminal_src}
	${cpu_src}
	${UI_src}
)





add_executable(${PROJECT_NAME} ${src})


target_include_directories(
  ${PROJECT_NAME}
  PRIVATE
	"include/"
)

if(windows)



	set(GTKMM_LIBRARY_DIR
		"C:/vcpkg/installed/x64-windows/lib/gtkmm.lib"
		"C:/vcpkg/installed/x64-windows/lib/glibmm.lib"
		"C:/vcpkg/installed/x64-windows/lib/glib-2.0.lib"
		"C:/vcpkg/installed/x64-windows/lib/sigc-2.0.lib"
		"C:/vcpkg/installed/x64-windows/lib/atkmm.lib"
	)


	find_path(GTKMM_INCLUDE_DIR NAMES gtkmm)

	include_directories(${GTKMM_INCLUDE_DIR})




	link_directories(${GTKMM_LIBRARY_DIR})
	

	target_link_libraries(${PROJECT_NAME} ${GTKMM_LIBRARY_DIR})

endif()


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


#add_custom_command(
#        TARGET foo POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy
#                ${CMAKE_SOURCE_DIR}/UI/emuASM
#                ${CMAKE_CURRENT_BINARY_DIR}/input.txt)

add_custom_command(
		TARGET ${PROJECT_NAME} PRE_BUILD
               COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${CMAKE_SOURCE_DIR}/UI/ 
				   $<TARGET_FILE_DIR:${PROJECT_NAME}>
				   
				   )

#cmake_minimum_required (VERSION 3.0)
#project (ejemplo)
#add_executable(ejecutable source.cpp)
#install(TARGETS myapp DESTINATION bin)

