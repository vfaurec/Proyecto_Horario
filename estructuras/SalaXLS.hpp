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
    bool check=false; //verifica carga del documento

};

//void mostrarFila(SalaXLS sala, int indice);
//void filtrarSalaXLS(SalaXLS sala, string edificio);
SalaXLS cargarArchivoSalaXLS(int &filas_archivo_salasXls, string filename);


