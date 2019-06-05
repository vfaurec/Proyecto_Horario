#pragma once
#include<vector>
#include<string>
#include<iostream>

using namespace std;

struct Docente {
    string id_docente;
    string nombre;
    string apellido;
    int horas = 0;
}

/**
 * Struct DocenteRow {
 *  string id_docente;
    string nombre;
    string apellido;
    string bloque1;
    string bloque2;
    string bloque3;
    string bloque4;
    string bloque5;
    string bloque6;
    string bloque7;
 * }
 * vector<DocenteRow> docenteRow
*/

struct DocenteXLS
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

void mostrarFila(DocenteXLS docente, int indice);
void filtrarDocente(DocenteXLS docente, string nombre);
vector<int> filtrarBloque(int bloque);
DocenteXLS cargarArchivoDocente(string filename);