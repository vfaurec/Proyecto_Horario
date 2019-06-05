#pragma once
#include<vector>
#include<string>
#include<iostream>

using namespace std;

// Excel SalaXLS
struct SalaXLS
{
    vector<string> edificio;
    vector<string> sala;
    bool check =false; //verifica carga del documento

};



void mostrarFila(SalaXLS sala, int indice);
void filtrarSalaXLS(SalaXLS sala, string edificio);
SalaXLS cargarArchivoSalaXLS(string filename);
//vector<SalaXLS> cargarArchivoSalaXLS(string filename, int &numero_filas_sala, vector<SalaXLS> vector_datos_sala);
vector<SalaXLS> datosArchivoSalaXLS(vector<SalaXLS> sala_dato, string filename);

