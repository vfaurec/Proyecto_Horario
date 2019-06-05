/*Estructura para manejar archivo salas.xlnt*/

#include"Sala.hpp"
#include<xlnt/xlnt.hpp>

void mostrarFila(Sala sala, int indice){
    cout<<"edificio: "<<sala.edificio[indice]<<endl;
    cout<<"sala: "<<sala.sala[indice]<<endl;
    cout<<endl;
}

void filtrarSala(Sala sala, string edificio){
    for(int i=1;i<sala.edificio.size();i++){
        if(sala.edificio[i]== edificio){
            mostrarFila(sala,i);
        }
    }
}

Sala cargarArchivoSala(string filename){ //cargar el archivo de Salas
    Sala sala;
    xlnt::workbook SalasXlsx;
    try
    {   
        SalasXlsx.load(filename);
        auto ws = SalasXlsx.active_sheet();
        for (auto row : ws.rows(false)) 
        { 
            sala.edificio.push_back(row[0].to_string());
            sala.sala.push_back(row[1].to_string());
        }
        //si la carga se hizo con exito, deja el estado de true
        sala.check=true;
        //retorna un objeto de tipo sala
        return sala; 
    }
    //sino se cargó correctamente, lanza una excepción
    catch(const std::exception& e)
    {
        std::cerr<< e.what()<<endl;
    } 
}

Sala datosArchivoSala(){ //función que guarda los datos del archivo sala en un vector
    vector<Sala> salas;
    



    
}


