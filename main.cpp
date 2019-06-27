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
    //cout<<"\nCARGA DE ARCHIVOS EXCEL \n"<<endl;

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

    Bloque objeto_bloque;
    vector<Bloque> vector_final;
    //Bloque objeto;


    //vector_final = asignarSalaXLS(sala, objeto_bloque);

    //cout<<"\n"<<endl;

    /* Desde el archivo DOCENTES:
        creo un vector con los profesores disponibles según un bloque y los asigno*/

    //cout<<"\nFILTRO PROFESORES DISPONIBLES Y LOS ASIGNO A CADA CELDA DEL HORARIO\n"<<endl;

    //asignarProfesoresDisponibles(curso,docente,vector_final);
    //string sala_excel = "M1-101";
    //crearformatoExcel(sala_excel);

    /*for(int i=0; i<=filas_archivo_salasXls; i++){
        objeto = asignarProfesoresDisponibles(curso,docente);
        vector_final.push_back(asignarProfesoresDisponibles(curso,docente));        
    }

    crearformatoExcel(vector_final, sala);*/
    
    /*vector<string> id_docentes;
    vector<string> codigo_curso;
    vector<int> horas_semanales;

    string codigo;
    int hora;*/

    //id_docentes = filtroBloqueDia(2,"Lunes");

    /*for(int i=0; i<id_docentes.size();i++){

        cout << "dato: " << i+1 << endl;
        

        codigo = filtrarCursoPorDocente(curso,id_docentes[i]);
        codigo_curso.push_back(codigo);

        cout << "   id_docente: " << id_docentes[i] << endl;
        cout << "   codigo curso: " << codigo_curso[i] << endl;
        
        hora = filtrarHorasPorCurso(curso,codigo_curso[i]);
        horas_semanales.push_back(hora);
        
        cout << "   horas: " << horas_semanales[i] << endl;
    }*/

    /* --------------------------------------------------------------------------------------
            PRUEBA DE MOSTRAR EL LLENADO DE UNA HOJA COMPLETA DEL EXCEL --> BLOQUE*/

    vector<string> id_docentes;
    vector<string> codigos_cursos;
    vector<int> horas_semanales;
    Bloque objeto;

    id_docentes = filtroBloqueDia(2,"Lunes");

    //obtengo todos los codigos de cursos
    codigos_cursos = obtenerCursos(curso);
    
    //obtengo todas las horas de cada curso
    horas_semanales = obtenerHoras(curso);

    //verifico si la hora de cada curso y su codigo corresponden segun indice
    for(int i=0; i<codigos_cursos.size(); i++){
        cout << "dato: " << i+1 << endl;
        cout << "   codigo-curso: " << codigos_cursos[i] << endl;
        cout << "   horas: " << horas_semanales[i] << endl;
        cout << endl;
    }

    //funcion que asigna y verifica los datos para cada celda del excel
    for(int i=0; i<39; i++){

        validacion(id_docentes, codigos_cursos, horas_semanales, objeto, curso);
    }
    
    return 0;
}