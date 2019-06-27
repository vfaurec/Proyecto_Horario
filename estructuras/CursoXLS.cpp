/*Estructura para manejar archivo cursos.xlnt*/

#include"CursoXLS.hpp"
#include<xlnt/xlnt.hpp>
#include<string>
#include<stdlib.h>


void mostrarFila(CursoXLS curso, int indice){
    cout<<"codigo: "<<curso.codigo[indice]<<endl;
    cout<<"nombre: "<<curso.nombre[indice]<<endl;
    cout<<"id_docente: "<<curso.id_docente[indice]<<endl;
    cout<<"nombre_docente: "<<curso.nombre_docente[indice]<<endl;
    cout<<"apellido_docente: "<<curso.apellido_docente[indice]<<endl;
    cout<<"bloque: "<<curso.bloque[indice]<<endl;
    cout<<endl;
}

/*void filtrarCurso(CursoXLS curso, string nombre){
    for(int i=1;i<curso.nombre.size();i++){
        if(curso.nombre[i]== nombre){
            mostrarFila(curso,i);
        }
    }
}*/

string filtrarCurso(CursoXLS curso, string identificador){
    for(int i=1;i<curso.nombre.size();i++){
        if(curso.codigo[i] == identificador){
            return curso.codigo[i];
        }else{
            cout << "No existe ningun curso para ese id_docente"<< endl;
        }
    }
}

string filtrarCursoPorDocente(CursoXLS curso, string id_docente){
    string codigo;
    for(int i=0;i<curso.nombre.size();i++){
        if(curso.id_docente[i] == id_docente){
           codigo = curso.codigo[i]; 
        }
    }
    return codigo;
}

CursoXLS cargarArchivoCurso(string filename){
    CursoXLS curso;
    xlnt::workbook archivo;
    try
    {
        archivo.load(filename);
        auto wc = archivo.active_sheet();
        for (auto row : wc.rows(false)) 
        { 
            curso.codigo.push_back(row[0].to_string());
            curso.nombre.push_back(row[1].to_string());
            curso.id_docente.push_back(row[2].to_string());
            curso.nombre_docente.push_back(row[3].to_string());
            curso.apellido_docente.push_back(row[4].to_string());
            curso.bloque.push_back(row[5].to_string());
        }
        curso.check=true;
        return curso;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }  
}

/*int filtrarHorasPorCurso(CursoXLS curso, string codigo_curso){

    int hora_ramo;
    
    for(int i=0;i<curso.codigo.size();i++){
        
        if(curso.codigo[i] == codigo_curso){
            
          hora_ramo = stoi(curso.bloque[i]); 
          
        }
        
    }
    
    return hora_ramo;
}*/

/* --------------------------------------------------------------------------------------*/

vector<string> obtenerCursos(CursoXLS curso){

    vector<string> codigos_cursos;

    /* función que obtiene todos los codigos de los cursos
        en el archivo del excel y los guarda en un vector */

    for(int i=0; i<curso.codigo.size();i++){
        codigos_cursos.push_back(curso.codigo[i]);
    }

    return codigos_cursos;

}

vector<int> obtenerHoras(CursoXLS curso){

    vector<int> horas_semanales;
    int hora;

    /* función que obtiene todas las horas semanales de cada curso 
        en el archivo del excel y los guarda en un vector */

    for(int i=0; i<curso.bloque.size();i++){
        
        hora = stoi(curso.bloque[i]);
        horas_semanales.push_back(hora);
        
    }

    return horas_semanales;

}