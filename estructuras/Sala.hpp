#pragma once
#include<vector>
#include<string>
#include<iostream>

using namespace std;

struct Sala
{
    vector<string> edificio;
    vector<string> sala;
    bool check =false; //verifica carga del documento

};

void mostrarFila(Sala sala, int indice);
void filtrarSala(Sala sala, string edificio);
Sala cargarArchivoSala(string filename);
//vector<Sala> cargarArchivoSala(string filename, int &numero_filas_sala, vector<Sala> vector_datos_sala);
vector<Sala> datosArchivoSala(vector<Sala> sala_dato, string filename);

