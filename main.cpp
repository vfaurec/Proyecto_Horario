#include<iostream>
#include<ostream>
#include<stdlib.h>
#include<xlnt/xlnt.hpp>
#include"estructuras/CursoXLS.hpp"
#include"estructuras/DocenteXLS.hpp"
#include"estructuras/SalaXLS.hpp"
#include"estructuras/Bloque.hpp"

#include <cstdio>
#include <ctime>

using namespace std;

int main(){

    //obtener el tiempo de ejecucion del programa
    std::clock_t start;
    double duration;
    start = std::clock();

    int filas_archivo_salasXls;

    DocenteXLS docente = cargarArchivoDocente("archivos/Docentes.xlsx");
    if(!docente.check) cout<<" * ERROR * --> EL archivo DOCENTES no se pudo cargar"<<endl;
        else cout<<"---> Archivo DOCENTES cargado con EXITO"<<endl;

    CursoXLS Curso = cargarArchivoCurso("archivos/Cursos.xlsx");
    if(!Curso.check) cout<<" * ERROR * --> EL archivo CURSOS no se pudo cargar"<<endl;
        else cout<<"---> Archivo CURSOS cargado con EXITO"<<endl;

    SalaXLS sala = cargarArchivoSalaXLS(filas_archivo_salasXls,"archivos/Salas.xlsx");
    if(!sala.check) cout<<" * ERROR * --> EL archivo SALAS no se pudo cargar"<<endl;
        else cout<<"---> Archivo SALAS cargado con EXITO"<<endl;

    /* --------------------------------------------------------------------------------------
            MOSTRAR EL LLENADO DE UNA HOJA COMPLETA DEL EXCEL --> BLOQUE*/

    vector<string> id_docentes;
    vector<string> codigos_cursos;
    vector<int> horas_semanales;
    vector<Bloque> Hojas;
    Bloque hoja_excel;

    //obtengo todos los codigos de cursos
    codigos_cursos = obtenerCursos(Curso);
    
    //obtengo todas las horas de cada curso
    horas_semanales = obtenerHoras(Curso);

    //funcion que asigna y verifica los datos para cada celda del excel (39 celdas por hoja)
    /*for(int i=0; i<filas_archivo_salasXls;i++)
    {
        cout << "sala: " << i+1 << endl;
        hoja_excel = validacion(codigos_cursos, horas_semanales, Curso);
        Hojas.push_back(hoja_excel);

        for(int j=0;j<Hojas[i].id_docente.size();j++){
            cout << "Dato [ " << j+1 << " ] " << " | ";
            cout << " id_docente " << Hojas[i].id_docente[j] << " | ";
            cout << " codigo_curso " << Hojas[i].codigo_curso[j] << endl;
        }
    }*/

    //pruebas con 4 salas
    for(int i=0; i<4;i++){
        cout << "sala: " << i+1 << endl;
        hoja_excel = validacion(codigos_cursos, horas_semanales, Curso);
        Hojas.push_back(hoja_excel);
    }

    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    cout << duration << " Segundos" <<endl;
    
    crearformatoExcel(Hojas,sala);
    
    return 0;
}