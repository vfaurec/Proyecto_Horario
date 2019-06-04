#include<iostream>
#include<stdlib.h>
#include<xlnt/xlnt.hpp>
#include"estructuras/Curso.hpp"
#include"estructuras/Docente.hpp"
#include"estructuras/Sala.hpp"
#include"estructuras/Bloque.hpp"

using namespace std;

int main(){
    
    Bloque bloque;

    Docente docente = cargarDocente("archivos/Docentes.xlsx");
    Curso curso = cargarCurso("archivos/Cursos.xlsx");
    Sala sala = cargarSala("archivos/Salas.xlsx");
    
    if(docente.check==false){
        cout<<"ERROR: EL archivo DOCENTES no se pudo cargar"<<endl;
    }
    if(curso.check==false){
        cout<<"ERROR: EL archivo CURSOS no se pudo cargar"<<endl;
    }
    if(sala.check==false){
        cout<<"ERROR: EL archivo SALAS no se pudo cargar"<<endl;
    }

    /*FUNCIONES DE PRUEBA
    mostrarFila(sala,3);
    filtrarSala(sala,"M3");
    mostrarFila(curso,1);
    filtrarCurso(curso,"Cálculo I");
    mostrarFila(docente,5);
    filtrarDocente(docente,"Rene Amador");*/
    
    /*Crear formato de horario salida, un excel me aguanta solo 16 hojas
    xlnt::workbook salida;
    for(int i=0;i<=15;i++){
        xlnt::worksheet hoja = salida.create_sheet();
        hoja.cell("C2").value("LUNES");
        hoja.cell("D2").value("MARTES");
        hoja.cell("E2").value("MIERCOLES");
        hoja.cell("F2").value("JUEVES");
        hoja.cell("G2").value("VIERNES");
        hoja.cell("H2").value("SABADO");
        hoja.cell("B3").value("Bloque 1");
        hoja.cell("B4").value("Bloque 2");
        hoja.cell("B5").value("Bloque 3");
        hoja.cell("B6").value("Bloque 4");
        hoja.cell("B7").value("Bloque 5");
        hoja.cell("B8").value("Bloque 6");
        hoja.cell("B9").value("Bloque 7");
    }
        salida.save("salida.xlsx");*/
    
    return 0;
}