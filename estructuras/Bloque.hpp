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
    //vector<int> horas_curso; 
    bool estado=false;
};

string asignarSalaXLS(SalaXLS sala, int i);
Bloque asignarProfesoresDisponibles(CursoXLS curso, DocenteXLS docentes);
void crearformatoExcel(vector<Bloque> objeto, SalaXLS salas);

//int setPartes(vector<BloqueXLS> bloques);
//void obtenerSala(Bloque bloque[], Sala Sala, string filename);

/* --------------------------------------------------------------------------------------*/

void validacion(vector<string> id_docentes, vector<string> codigos, vector<int> horas, Bloque hoja_excel, CursoXLS curso);