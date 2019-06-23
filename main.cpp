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

    //cout<<"\nASIGNAR DATOS DE ARCHIVO SALAS A VECTOR BLOQUE\n"<<endl;

    Bloque objeto_bloque;
    vector<Bloque> vector_final;
    Bloque objeto;

    vector_final = asignarSalaXLS(sala, objeto_bloque);

    //cout<<"\n"<<endl;

    /* Desde el archivo DOCENTES:
        creo un vector con los profesores disponibles según un bloque y los asigno*/

    cout<<"\nFILTRO PROFESORES DISPONIBLES Y LOS ASIGNO A CADA CELDA DEL HORARIO\n"<<endl;

    //asignarProfesoresDisponibles(curso,docente,vector_final);
    //string sala_excel = "M1-101";
    //crearformatoExcel(sala_excel);

    for(int i=1; i<= filas_archivo_salasXls; i++){
        //cout << "numero de salas: " << filas_archivo_salasXls << endl; 
        string nombre_sala = vector_final[i].edificio + " - " + vector_final[i].sala;
        //cout << "La sala es: " <<nombre_sala << endl;
        objeto = asignarProfesoresDisponibles(curso,docente,vector_final);
        vector_final.push_back(objeto);
        //Crea horario en excel (formato de salida) para una sala en especifico
        
    }

    //crearformatoExcel(vector_final,nombre_sala);
    
    return 0;
}