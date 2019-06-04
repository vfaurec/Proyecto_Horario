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
Sala cargarSala(string filename);