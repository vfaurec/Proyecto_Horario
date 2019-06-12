/*Estructura para manejar archivo salas.xlnt*/

#include"SalaXLS.hpp"
#include<xlnt/xlnt.hpp>
#include<string>

void mostrarFila(SalaXLS sala, int indice){
    cout<<"edificio: "<<sala.edificio[indice]<<endl;
    cout<<"sala: "<<sala.sala[indice]<<endl;
    cout<<endl;
}

void filtrarSalaXLS(SalaXLS sala, string edificio){
    for(int i=1;i<sala.edificio.size();i++){
        if(sala.edificio[i]== edificio){
            mostrarFila(sala,i);
        }
    }
}

SalaXLS cargarArchivoSalaXLS(int &filas_archivo_salasXls, string filename){  //cargar el archivo de SalaXLSs
    SalaXLS salas;
    int i=0;
    xlnt::workbook archivo;
    try{   
        archivo.load(filename);
        auto ws = archivo.active_sheet();
            for (auto row : ws.rows(false)) { 
                salas.edificio.push_back(row[0].to_string());
                salas.sala.push_back(row[1].to_string());
                i++; 
            }
        filas_archivo_salasXls = i;
        //si la carga se hizo con exito, deja el estado de true
        salas.check=true;
        return salas; 
    }
    //sino se cargo correctamente, lanza una excepción
    catch(const std::exception& e){
        std::cerr<< e.what()<<endl;
    } 
}




