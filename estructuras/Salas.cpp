/*Estructura para manejar archivo salas.xlnt*/

#include"Salas.hpp"

void mostrarFila(Salas salas, int indice){
    cout<<"edificio: "<<salas.edificio[indice]<<endl;
    cout<<"sala: "<<salas.sala[indice]<<endl;
    cout<<endl;
}

void filtrarSala(Salas salas, string edificio){
    for(int i=1;i<salas.edificio.size();i++){
        if(salas.edificio[i]== edificio){
            mostrarFila(salas,i);
        }
    }
}