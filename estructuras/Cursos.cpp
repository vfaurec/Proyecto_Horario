/*Estructura para manejar archivo cursos.xlnt*/

#include"Cursos.hpp"

void mostrarFila(Cursos cursos, int indice){
    cout<<"codigo: "<<cursos.codigo[indice]<<endl;
    cout<<"nombre: "<<cursos.nombre[indice]<<endl;
    cout<<"id_docente: "<<cursos.id_docente[indice]<<endl;
    cout<<"nombre_docente: "<<cursos.nombre_docente[indice]<<endl;
    cout<<"apellido_docente: "<<cursos.apellido_docente[indice]<<endl;
    cout<<"bloque: "<<cursos.bloque[indice]<<endl;
    cout<<endl;
}

void filtrarCurso(Cursos cursos, string nombre){
    for(int i=1;i<cursos.nombre.size();i++){
        if(cursos.nombre[i]== nombre){
            mostrarFila(cursos,i);
        }
    }
}