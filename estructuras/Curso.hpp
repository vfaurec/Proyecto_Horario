#pragma once
#include<vector>
#include<string>
#include<iostream>

using namespace std;

struct Curso
{
    vector<string> codigo;
    vector<string> nombre;
    vector<string> id_docente;
    vector<string> nombre_docente;
    vector<string> apellido_docente;
    vector<string> bloque;
    bool check =false; //verifica carga del documento

};

void mostrarFila(Curso curso, int indice);
void filtrarCurso(Curso curso, string nombre);
Curso cargarCurso(string filename);

