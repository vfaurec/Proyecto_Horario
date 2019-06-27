#pragma once
#include<vector>
#include<string>
#include<iostream>

using namespace std;

struct SalaXLS //estructura que representa el archivo Salas.xlsx
{
    vector<string> edificio;
    vector<string> sala;
    bool check=false; //verifica carga exitosa o no del documento

};

SalaXLS cargarArchivoSalaXLS(int &filas_archivo_salasXls, string filename);






