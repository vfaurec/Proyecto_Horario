/*Estructura para manejar archivo docentes.xlnt*/

#include"Docentes.hpp"

void mostrarFila(Docentes docentes, int indice){
    cout<<"identificador: "<<docentes.id_docente[indice]<<endl;
    cout<<"nombre: "<<docentes.nombre[indice]<<endl;
    cout<<"apellido: "<<docentes.apellido[indice]<<endl;
    cout<<"bloque 1: "<<docentes.bloque1[indice]<<endl;
    cout<<"bloque 2: "<<docentes.bloque2[indice]<<endl;
    cout<<"bloque 3: "<<docentes.bloque3[indice]<<endl;
    cout<<"bloque 4: "<<docentes.bloque4[indice]<<endl;
    cout<<"bloque 5: "<<docentes.bloque5[indice]<<endl;
    cout<<"bloque 6: "<<docentes.bloque6[indice]<<endl;
    cout<<"bloque 7: "<<docentes.bloque7[indice]<<endl;
    cout<<endl;
}

void filtrarDocente(Docentes docentes, string nombre){
    for(int i=1;i<docentes.nombre.size();i++){
        if(docentes.nombre[i]== nombre){
            mostrarFila(docentes,i);
        }
    }
}