clear
echo "En proceso..... "
g++ estructuras/CursoXLS.cpp estructuras/DocenteXLS.cpp estructuras/SalaXLS.cpp estructuras/Bloque.cpp main.cpp -o programa -std=c++14 -Ixlnt/include -lxlnt
./programa
echo "******* Abriendo archivo con los horarios *******"
libreoffice HORARIOS.xlsx