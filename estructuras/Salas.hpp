#pragma once
#include<vector>
#include<string>
#include<iostream>

using namespace std;

struct Salas
{
    vector<string> edificio;
    vector<string> sala;

};

void mostrarFila(Salas salas, int indice);
void filtrarSala(Salas salas, string edificio);