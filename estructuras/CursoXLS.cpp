/*Estructura para manejar archivo cursos.xlnt*/

#include"CursoXLS.hpp"
#include<xlnt/xlnt.hpp>

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
    for(int i=1;i<curso.nombre.size();i++){
        if(curso.id_docente[i] == id_docente){
            return curso.codigo[i];
        }else{
            //cout << "No existe ningun curso para ese id_docente"<< endl;
        }
    }
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