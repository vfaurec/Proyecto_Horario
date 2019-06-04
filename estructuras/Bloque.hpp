#pragma once
#include<vector>
#include<string>
#include<iostream>
#include "Salas.hpp"

using namespace std;

/*La siguiente estructura se encarga de hacer la selección final de la sala, el curso y el profesor*/

struct Bloque
{
    vector<string> edificio;
    vector<string> sala;
    vector<string> id_docente;
    vector<string> codigo_curso;
    vector<bool> estado;

};
