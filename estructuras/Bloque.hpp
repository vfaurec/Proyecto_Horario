/*La siguiente estructura se encarga de hacer la selección final de la sala, el curso y el profesor*/

#pragma once
#include<vector>
#include<string>
#include<iostream>
#include "Sala.hpp"
#include "Bloque.hpp"

using namespace std;

struct Bloque
{
    vector<string> edificio;
    vector<string> sala;
    vector<string> id_docente;
    vector<string> codigo_curso;
    vector<bool> estado;

};

//void obtenerSala(Bloque bloque[], Sala Sala, string filename);