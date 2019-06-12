/*Estructura para manejar el vector principal con los bloques y salas que se asignaran*/

#include "Bloque.hpp"
#include "SalaXLS.hpp"
#include <xlnt/xlnt.hpp>

/*int getPartes(BloqueXLS bloqueXLS){
    int partes = bloqueXLS.bloques.size/15;
    int extra = bloqueXLS.bloques.size%15;
    
    if(extra > 0){
        return partes + 1;
    } else {
        return partes;
    }   

}
*/

/*void obtenerSala(Bloque bloque[], Sala Sala,string filename){
    //Al vector de objetos bloques se le asigna una sala a cada uno
    int i;
    for(i=0;i<=41;i++){
        cargarSala(filename);
        bloque[i].edificio = Sala.edificio;
        bloque[i].sala = Sala.sala;
        cout << "Dato [" << i+1 << "]: "<< endl;
        cout << "Edificio: " << &bloque[i].edificio << endl;
        cout << "Sala: " << &bloque[i].sala << endl;
        cout << endl;
    }
}*/

void asignarSalaXLS(SalaXLS sala, Bloque objeto, vector<Bloque> vector){
    //Obtengo los datos de las salas y los asigno en vector_final
        for(int j=0; j <sala.edificio.size(); j++){
            cout << "Bloque "<< j <<endl;
            objeto.edificio = sala.edificio[j];
            objeto.sala = sala.sala[j];
            vector.push_back(objeto);
            cout << "edificio: " << vector[j].edificio<< endl;
            cout << "sala: " << vector[j].sala<<endl;
            cout << "\n ******************** \n"<<endl;
        }
}