#pragma once
#include<vector>
#include<string>
#include<iostream>

using namespace std;

struct Cursos
{
    vector<string> codigo;
    vector<string> nombre;
    vector<string> id_docente;
    vector<string> nombre_docente;
    vector<string> apellido_docente;
    vector<string> bloque;

};

void mostrarFila(Cursos cursos, int indice);
void filtrarCurso(Cursos cursos, string nombre);

