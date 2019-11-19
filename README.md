# emuASM
## Instrucciones de instalacion

Para instalar el proyecto sobre windows se recomienda visual studio 2019, aunque 2017 puede funcionar pero dispone de menor soporte y no ha sido probado

## Requisitos
- [**Visual Studio**](https://visualstudio.microsoft.com/es/vs/):en caso de windows
- [**Visual Studio Code**](https://code.visualstudio.com/): (opcional)
- [**vcpkg**](https://github.com/microsoft/vcpkg): gestor de dependencias del proyecto
- [**cmake**](https://cmake.org/): generador de proyectos
- [**ninja**](https://ninja-build.org/): (suele venir incluido con visual studio), (opcional)
- [**redistribuibles de VS**](https://support.microsoft.com/es-es/help/2977003/the-latest-supported-visual-c-downloads):requisito de visual studio
- [**gtkmm3**](https://www.gtkmm.org/en/): wrapper de [GTK3](https://www.gtk.org/) para c++ ,se instala con vcpkg
- [**git**](https://git-scm.com/): nescesario para clonar los repositorios

## configurando visual studio

mediante el instalador se pueden editar los componentes deseados, en la pestaña de componentes individuales es necesario instalar cmake para windows, aunque se puede descargar del siguiente [sitio](https://cmake.org/download/)

## descargando y configurando vcpkg

primero es nescesario descargar vcpkg en la raiz de la siguiente manera(si no se hace es nescesario modificar CMakeLists.txt en /source), aunque la guia completa se encuentra en su [repositorio](https://github.com/microsoft/vcpkg)

```
C:\> git clone https://github.com/Microsoft/vcpkg.git
C:\> cd vcpkg

C:\vcpkg>bootstrap-vcpkg.bat
PS> .\bootstrap-vcpkg.bat
Linux:~/$ ./bootstrap-vcpkg.sh
```
una vez finalizado es importante ejecutar `vcpkg integrate install`, para integrar con las versiones de visual studio soportadas
opcionalmente se agrega al PATH la ruta C:\vcpkg\ y se copia el ejecutable de ninja,




## Descargando y compilando las librerias
para descargar gtkmm bastan con realizar
`vcpkg install gtkmm:x64-windows`, el triplet `x64-windows` indica la plataforma deseada, para mas info ver el repo de [vcpkg](https://github.com/microsoft/vcpkg)

hay que tener en cuenta que este proceso varia segun la conexion del equipo y potencia de este, puede durar unos cuantos minutos


## Clonando el repositorio
importante clonarlo en una ubicacion de facil acceso, ejemplo el escritorio
`git clone https://gitlab.com/ninjaoflight5/emuasm.git`

## Compilando el proyecto
en Visual Studio basta con abrir la carpeta como un proyecto de cmake, en visual studio 2019 deberia detectarse automaticamente y empezar a generar una configuracion apta, este proceso es rapido y no deberia tardar mas de 1 minuto.
> es nescesario que la configuracion elegida sea estrictamente 64 bits, o que concuerde con la instalada previamente en vcpkg

una vez configurado el proyecto este puede compilarse como cualquier otro programa, cmake se encargara de las dependencias de los DLL´s