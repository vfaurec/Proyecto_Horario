#pragma once
#include<vector>
#include<string>
#include<iostream>

using namespace std;

struct Docente
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
    bool check =false; //verifica carga del documento

};

void mostrarFila(Docente docente, int indice);
void filtrarDocente(Docente docente, string nombre);
Docente cargarDocente(string filename);