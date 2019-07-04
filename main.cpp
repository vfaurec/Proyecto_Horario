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

int main( int argc, char* argv[]){

    //paso de parámetros y validación de argumentos

    string args_auxiliar;
    string argumentos;
    int contador_archivos = 0;

    for(int i=1; i<argc; i++){
        //cout << "el argumento " << i << " es: " << argv[i] << endl;
        args_auxiliar = argv[i];
        if(args_auxiliar == "-s" && i!=argc-1)
        {
            argumentos = argv[i+1];
            contador_archivos++;
        }
        if(args_auxiliar == "-c" && i!=argc-1)
        {
            argumentos = argv[i+1];
            contador_archivos++;
        }
        if(args_auxiliar == "-d" && i!=argc-1)
        {
            argumentos = argv[i+1];
            contador_archivos++;
        }
    }

    cout << endl;
    if(contador_archivos < 3)
    {
        cout << "FALTAN ARGUMENTOS" << endl;
        return 0;
    }else{
        if(argc > 7)
        {
            cout << "SOBRAN ARGUMENTOS" << endl;
            return 0;
        }
    }

    //obtener el tiempo de ejecución del programa

    std::clock_t start;
    double duration;
    start = std::clock();

    //carga de archivos.xlsx

    int filas_archivo_salasXls = 0;

    DocenteXLS docente = cargarArchivoDocente("archivos/Docentes.xlsx");
    if(!docente.check) cout<<" * ERROR * --> EL archivo DOCENTES no se pudo cargar"<<endl;
        else cout<<"---> Archivo DOCENTES cargado con EXITO"<<endl;

    CursoXLS Curso = cargarArchivoCurso("archivos/Cursos.xlsx");
    if(!Curso.check) cout<<" * ERROR * --> EL archivo CURSOS no se pudo cargar"<<endl;
        else cout<<"---> Archivo CURSOS cargado con EXITO"<<endl;

    SalaXLS sala = cargarArchivoSalaXLS(filas_archivo_salasXls,"archivos/Salas.xlsx");
    if(!sala.check) cout<<" * ERROR * --> EL archivo SALAS no se pudo cargar"<<endl;
        else cout<<"---> Archivo SALAS cargado con EXITO"<<endl;

    //llenado de bloques y validación de hojas del excel

    vector<string> codigos_cursos;
    vector<int> horas_semanales;
    vector<Bloque> Hojas;
    Bloque hoja_excel;

    //obtengo todos los codigos de cursos y horas correspondientes a cada uno

    codigos_cursos = obtenerCursos(Curso);
    horas_semanales = obtenerHoras(Curso);

    //asigna y verifica los datos para cada celda del excel (39 celdas por hoja)

    for(int i=0; i<53; i++)
    {
        cout << endl << "SALA ------------> " << i+1 << endl;
        hoja_excel = validacion(codigos_cursos, horas_semanales, Curso);
        Hojas.push_back(hoja_excel);
    }


    //tiempo de ejecución del programa

    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    cout << "El programa demora " << duration << " Segundos" <<endl;
    
    //llenado en excel ----> HORARIOS.XLSX

    crearformatoExcel(Hojas,sala);
    
    return 0;
}