#include<iostream>
#include<ostream>
#include<stdlib.h>
#include<xlnt/xlnt.hpp>
#include"estructuras/CursoXLS.hpp"
#include"estructuras/DocenteXLS.hpp"
#include"estructuras/SalaXLS.hpp"
#include"estructuras/Bloque.hpp"

using namespace std;

int main(){
    
    int filas_archivo_salasXls;

    /* VERIFICO LA CARGA DE LOS ARCHIVOS EXCEL */
    cout<<"\nCARGA DE ARCHIVOS EXCEL \n"<<endl;

    DocenteXLS docente = cargarArchivoDocente("archivos/Docentes.xlsx");
    if(!docente.check) cout<<" * ERROR * --> EL archivo DOCENTES no se pudo cargar"<<endl;
        else cout<<"---> Archivo DOCENTES cargado con EXITO"<<endl;

    CursoXLS curso = cargarArchivoCurso("archivos/Cursos.xlsx");
    if(!curso.check) cout<<" * ERROR * --> EL archivo CURSOS no se pudo cargar"<<endl;
        else cout<<"---> Archivo CURSOS cargado con EXITO"<<endl;

    SalaXLS sala = cargarArchivoSalaXLS(filas_archivo_salasXls,"archivos/Salas.xlsx");
    if(!sala.check) cout<<" * ERROR * --> EL archivo SALAS no se pudo cargar"<<endl;
        else cout<<"---> Archivo SALAS cargado con EXITO"<<endl;

    cout<<"\n"<<endl;

     /* Desde el archivo SALAS obtengo:
        edificio, sala
        y las asigno a un vector de estructuras Bloque (vector de salida) */

    cout<<"\nASIGNAR DATOS DE ARCHIVO SALAS A VECTOR BLOQUE\n"<<endl;

    Bloque objeto_bloque;
    vector<Bloque> vector_final;

    asignarSalaXLS(sala, objeto_bloque, vector_final);

    return 0;
}