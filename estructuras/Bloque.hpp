#pragma once
#include<vector>
#include<string>
#include<iostream>
#include "SalaXLS.hpp"
#include "CursoXLS.hpp"
#include "DocenteXLS.hpp"
#include "Bloque.hpp"

using namespace std;

struct Bloque //representa una hoja de salida del excel
{ 
    string edificio;
    string sala;
    vector<string> id_docente;
    vector<string> codigo_curso;
    bool estado=false;
};

Bloque validacion(vector<string>& codigos, vector<int>& horas, CursoXLS curso);
int obtenerBloque(int indice);
string obtenerDia(int indice);
void crearformatoExcel(vector<Bloque> objeto, SalaXLS salas);
string asignarSalaXLS(SalaXLS Sala, int i);



