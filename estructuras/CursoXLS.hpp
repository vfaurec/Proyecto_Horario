#pragma once
#include<vector>
#include<string>
#include<iostream>

using namespace std;

struct CursoXLS //estructura que representa el archivo Cursos.xlsx
{
    vector<string> codigo;
    vector<string> nombre;
    vector<string> id_docente;
    vector<string> nombre_docente;
    vector<string> apellido_docente;
    vector<string> bloque;
    bool check =false; //verifica carga exitosa o no del archivo

};

CursoXLS cargarArchivoCurso(string filename);
vector<string> obtenerCursos(CursoXLS Curso);
vector<int> obtenerHoras(CursoXLS Curso);
string filtrarCursoPorDocente(CursoXLS curso, string id_docente);

/* --------------------------------------------------------------------------------------*/

void mostrarFila(CursoXLS curso, int indice);
string filtrarCurso(CursoXLS curso, string identificador);

