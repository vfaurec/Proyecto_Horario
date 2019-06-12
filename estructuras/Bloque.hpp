/*La siguiente estructura se encarga de hacer la selección final de la sala, el curso y el profesor*/

#pragma once
#include<vector>
#include<string>
#include<iostream>
#include "SalaXLS.hpp"
#include "CursoXLS.hpp"
#include "DocenteXLS.hpp"
#include "Bloque.hpp"

using namespace std;

struct Bloque {
    string edificio;
    string sala;
    string id_docente;
    string codigo_curso;
    bool estado;
};

//int setPartes(vector<BloqueXLS> bloques);
//void obtenerSala(Bloque bloque[], Sala Sala, string filename);
void asignarSalaXLS(SalaXLS sala, Bloque objeto, vector<Bloque> vector);