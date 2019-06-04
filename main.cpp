#include<iostream>
#include<stdlib.h>
#include<xlnt/xlnt.hpp>
#include"estructuras/Cursos.hpp"
#include"estructuras/Docentes.hpp"
#include"estructuras/Salas.hpp"
#include"estructuras/Bloque.hpp"

using namespace std;

int main(){
    
    Cursos cursos;
    Docentes docentes;
    Salas salas;
    Bloque bloque;

    xlnt::workbook c;
    c.load("archivos/Cursos.xlsx");
    auto wc = c.active_sheet();
    //std::clog << "Processing spread sheet" << std::endl;
    for (auto row : wc.rows(false)) 
    { 
        /*for (auto cell : row) 
    { 
        std::clog << cell.to_string() << std::endl;
    }*/
        cursos.codigo.push_back(row[0].to_string());
        cursos.nombre.push_back(row[1].to_string());
        cursos.id_docente.push_back(row[2].to_string());
        cursos.nombre_docente.push_back(row[3].to_string());
        cursos.apellido_docente.push_back(row[4].to_string());
        cursos.bloque.push_back(row[5].to_string());
    }
    
    xlnt::workbook d;
    d.load("archivos/Docentes.xlsx");
    auto wd = d.active_sheet();
    //std::clog << "Processing spread sheet" << std::endl;
    for (auto row : wd.rows(false)) 
    { 
        /*for (auto cell : row) 
    { 
        std::clog << cell.to_string() << std::endl;
    }*/
        docentes.id_docente.push_back(row[0].to_string());
        docentes.nombre.push_back(row[1].to_string());
        docentes.apellido.push_back(row[2].to_string());
        docentes.bloque1.push_back(row[3].to_string());
        docentes.bloque2.push_back(row[4].to_string());
        docentes.bloque3.push_back(row[5].to_string());
        docentes.bloque4.push_back(row[6].to_string());
        docentes.bloque5.push_back(row[7].to_string());
        docentes.bloque6.push_back(row[8].to_string());
        docentes.bloque7.push_back(row[9].to_string());
    }

    xlnt::workbook s;
    s.load("archivos/Salas.xlsx");
    auto ws = s.active_sheet();
    //std::clog << "Processing spread sheet" << std::endl;
    for (auto row : ws.rows(false)) 
    { 
        /*for (auto cell : row) 
    { 
        std::clog << cell.to_string() << std::endl;
    }*/
        salas.edificio.push_back(row[0].to_string());
        salas.sala.push_back(row[1].to_string());
    }
    
    /*mostrarFila(cursos,1);
    filtrarCurso(cursos,"Cálculo I");
    mostrarFila(docentes,5);
    filtrarDocente(docentes,"Rene Amador");
    mostrarFila(salas,3);
    filtrarSala(salas,"M3");*/

    //Crear formato de horario salida, un excel me aguanta solo 16 hojas
    xlnt::workbook salida;
    for(int i=0;i<=15;i++){
        xlnt::worksheet hoja = salida.create_sheet();;
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
        salida.save("salida.xlsx");
   

    return 0;
}