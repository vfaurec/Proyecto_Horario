#pragma once
#include<vector>
#include<string>
#include<iostream>

using namespace std;

struct CursoXLS
{
    vector<string> codigo;
    vector<string> nombre;
    vector<string> id_docente;
    vector<string> nombre_docente;
    vector<string> apellido_docente;
    vector<string> bloque;
    bool check =false; //verifica carga del documento

};

void mostrarFila(CursoXLS curso, int indice);
//void filtrarCurso(CursoXLS curso, string nombre);
string filtrarCurso(CursoXLS curso, string identificador);
string filtrarCursoPorDocente(CursoXLS curso, string id_docente);
CursoXLS cargarArchivoCurso(string filename);
int filtrarHorasPorCurso(CursoXLS curso, string codigo_curso);

