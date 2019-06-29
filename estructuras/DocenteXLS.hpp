#pragma once
#include<vector>
#include<string.h>
#include<iostream>

using namespace std;

struct DocenteXLS //estructura que representa al archivo Docentes.xlsx
{
    vector<string> id_docente;
    vector<string> nombre;
    vector<string> apellido;
    vector<string> bloque1;
    vector<string> bloque2;
    vector<string> bloque3;
    vector<string> bloque4;
    vector<string> bloque5;
    vector<string> bloque6;
    vector<string> bloque7;
    bool check =false; //verifica carga exitosa o no del documento

};

DocenteXLS cargarArchivoDocente(string filename);
vector<string> filtroBloqueDia(int bloque, string dia);

/* --------------------------------------------------------------------------------------*/

vector<DocenteXLS> filtrarBloque(DocenteXLS docenteXLS, int bloque);
string hallarDisponible(DocenteXLS docenteXLS, int bloque);

DocenteXLS cargarPorDia(string filename, string dia);

