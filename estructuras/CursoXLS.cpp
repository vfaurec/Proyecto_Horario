#include<string>
#include<stdlib.h>
#include<xlnt/xlnt.hpp>
#include"CursoXLS.hpp"

CursoXLS cargarArchivoCurso(string filename) //carga archivo Cursos.xlsx
{ 

    CursoXLS Curso;
    xlnt::workbook archivo;

    try
    {
        archivo.load(filename);
        auto hoja = archivo.active_sheet();

        for (auto row : hoja.rows(false)) 
        { 
            Curso.codigo.push_back(row[0].to_string());
            Curso.nombre.push_back(row[1].to_string());
            Curso.id_docente.push_back(row[2].to_string());
            Curso.nombre_docente.push_back(row[3].to_string());
            Curso.apellido_docente.push_back(row[4].to_string());
            Curso.bloque.push_back(row[5].to_string());
        }

        Curso.check=true;
        return Curso;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }  
}

vector<string> obtenerCursos(CursoXLS Curso) //obtiene en un vector los codigos de los cursos
{ 

    vector<string> codigos_cursos;

    for(int i=1; i<Curso.codigo.size();i++){
        codigos_cursos.push_back(Curso.codigo[i]);
    }

    return codigos_cursos;

}

vector<int> obtenerHoras(CursoXLS Curso) //obtengo horas por cada curso
{

    vector<int> horas_semanales;
    int hora;

    for(int i=1; i<Curso.bloque.size();i++){
        
        hora = stoi(Curso.bloque[i]);
        horas_semanales.push_back(hora);
        
    }

    return horas_semanales;

}

string filtrarCursoPorDocente(CursoXLS curso, string id_docente) //obtengo codiggo del curso segun id_docente
{
    string codigo;
    for(int i=0;i<curso.codigo.size();i++){
        if(curso.id_docente[i] == id_docente){
           codigo = curso.codigo[i]; 
        }
    }
    return codigo;
}



