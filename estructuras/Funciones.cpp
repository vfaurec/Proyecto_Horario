/*Incluye funciones de carga y verificación, manejo de estructuras*/

#include "Funciones.hpp"

Cursos cargar_archivo_cursos(Cursos cursos){
    xlnt::workbook c;
    c.load("archivos/Cursos.xlsx");
    auto wc = c.active_sheet();
    for (auto row : wc.rows(false)) 
    { 
        cursos.codigo.push_back(row[0].to_string());
        cursos.nombre.push_back(row[1].to_string());
        cursos.id_docente.push_back(row[2].to_string());
        cursos.nombre_docente.push_back(row[3].to_string());
        cursos.apellido_docente.push_back(row[4].to_string());
        cursos.bloque.push_back(row[5].to_string());
    }
    return cursos;
}