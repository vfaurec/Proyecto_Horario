#include<string>
#include<stdlib.h>
#include<xlnt/xlnt.hpp>
#include"CursoXLS.hpp"

CursoXLS cargarArchivoCurso(string filename){ //carga archivo Cursos.xlsx

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

vector<string> obtenerCursos(CursoXLS Curso){ //obtiene en un vector los codigos de los cursos

    vector<string> codigos_cursos;

    for(int i=1; i<Curso.codigo.size();i++){
        codigos_cursos.push_back(Curso.codigo[i]);
    }

    return codigos_cursos;

}

vector<int> obtenerHoras(CursoXLS Curso){

    vector<int> horas_semanales;
    int hora;

    /* función que obtiene todas las horas semanales de cada curso 
        en el archivo del excel y los guarda en un vector */

    for(int i=1; i<Curso.bloque.size();i++){
        
        hora = stoi(Curso.bloque[i]);
        horas_semanales.push_back(hora);
        
    }

    return horas_semanales;

}

string filtrarCursoPorDocente(CursoXLS curso, string id_docente){
    string codigo;
    
    for(int i=0;i<curso.codigo.size();i++){
        
        if(curso.id_docente[i] == id_docente){
           codigo = curso.codigo[i]; 
        }
    }
    return codigo;
}

/* --------------------------------------------------------------------------------------*/

void mostrarFila(CursoXLS curso, int indice){
    cout<<"codigo: "<<curso.codigo[indice]<<endl;
    cout<<"nombre: "<<curso.nombre[indice]<<endl;
    cout<<"id_docente: "<<curso.id_docente[indice]<<endl;
    cout<<"nombre_docente: "<<curso.nombre_docente[indice]<<endl;
    cout<<"apellido_docente: "<<curso.apellido_docente[indice]<<endl;
    cout<<"bloque: "<<curso.bloque[indice]<<endl;
    cout<<endl;
}

string filtrarCurso(CursoXLS curso, string identificador){
    for(int i=1;i<curso.nombre.size();i++){
        if(curso.codigo[i] == identificador){
            return curso.codigo[i];
        }else{
            cout << "No existe ningun curso para ese id_docente"<< endl;
        }
    }
}



