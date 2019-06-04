#pragma once
#include<vector>
#include<string>
#include<iostream>

using namespace std;

struct Docentes
{
    vector<string> id_docente;
    vector<string> nombre;
    vector<string> apellido;
    vector<string> bloque1;
    vector<string> bloque2;
    vector<string> bloque3;
    vector<string> bloque4;
    vector<string> bloque5;
    vector<string> bloque6;
    vector<string> bloque7;

};

void mostrarFila(Docentes docentes, int indice);
void filtrarDocente(Docentes docentes, string nombre);