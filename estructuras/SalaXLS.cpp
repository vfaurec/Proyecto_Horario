#include"SalaXLS.hpp"
#include<xlnt/xlnt.hpp>
#include<string>

SalaXLS cargarArchivoSalaXLS(int &filas_archivo_salasXls, string filename){  //cargar el archivo de SalaXLS

    SalaXLS Salas;
    int i=0;
    xlnt::workbook archivo;

    try{   
        archivo.load(filename);
        auto ws = archivo.active_sheet();
            for (auto row : ws.rows(false)) { 
                Salas.edificio.push_back(row[0].to_string());
                Salas.sala.push_back(row[1].to_string());
                i++; 
            }
        filas_archivo_salasXls = i;
        //si la carga se hizo con exito, asigna el estado a true
        Salas.check=true;
        return Salas; 
    }
    //si no se cargó correctamente, lanza una excepción
    catch(const std::exception& e){
        std::cerr<< e.what()<<endl;
    } 
}





