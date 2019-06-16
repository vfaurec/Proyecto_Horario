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

/*Cada bloque será una celda
    cada celda contiene una sala especifica (hoja del excel)
    y dentro de esta sala tenemos los bloques disponibles semanales (celda del excel)
    el cual corresponde al largo de los dos vectores restantes en la estructura
    que son profesores y codigos de las asignaturas impartidas*/

struct Bloque {
    string edificio;
    string sala;
    vector<string> id_docente;
    vector<string> codigo_curso;
    bool estado=false;
};

void asignarSalaXLS(SalaXLS sala, Bloque objeto, vector<Bloque> vector);
void asignarProfesoresDisponibles(CursoXLS curso, DocenteXLS docentes, vector<Bloque> vector_salida);
void crearformatoExcel(Bloque objeto, string sala);
//int setPartes(vector<BloqueXLS> bloques);
//void obtenerSala(Bloque bloque[], Sala Sala, string filename);
