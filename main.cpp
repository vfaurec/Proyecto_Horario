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
            PRUEBA DE MOSTRAR EL LLENADO DE UNA HOJA COMPLETA DEL EXCEL --> BLOQUE*/

    vector<string> id_docentes;
    vector<string> codigos_cursos;
    vector<int> horas_semanales;
    vector<Bloque> Hojas;
    Bloque hoja_excel;
    string salon;

    

    //obtengo todos los codigos de cursos
    codigos_cursos = obtenerCursos(Curso);
    
    //obtengo todas las horas de cada curso
    horas_semanales = obtenerHoras(Curso);

    
    //verifico si la hora de cada curso y su codigo corresponden segun indice
    /*for(int i=0; i<codigos_cursos.size(); i++){
        cout << "dato: " << i+1 << endl;
        cout << "   codigo-curso: " << codigos_cursos[i] << endl;
        cout << "   horas: " << horas_semanales[i] << endl;
        cout << endl;
    }*/

    //funcion que asigna y verifica los datos para cada celda del excel (39 celdas por hoja)

    for(int i=0; i<filas_archivo_salasXls;i++){

        //cout << "sala: " << i+1 << endl;
        hoja_excel = validacion(codigos_cursos, horas_semanales, Curso);
        
        //cout << "   id_docente: " << hoja_excel.id_docente[i] << endl;
        //cout << "   codigo_curso: " << hoja_excel.codigo_curso[i] << endl;

        Hojas.push_back(hoja_excel);

    }


    cout << "********** creación del excel ***********" << endl;
    
    crearformatoExcel(Hojas,sala);
    
    return 0;
}