/*Estructura para manejar archivo salas.xlnt*/

#include"Sala.hpp"
#include<xlnt/xlnt.hpp>
#include<string>

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


Sala cargarArchivoSala(string filename){  //cargar el archivo de Salas
    Sala salas;
    xlnt::workbook SalasXlsx;
    try
    {   
        SalasXlsx.load(filename);
        auto ws = SalasXlsx.active_sheet();
        for (auto row : ws.rows(false)) 
        { 
            salas.edificio.push_back(row[0].to_string());
            salas.sala.push_back(row[1].to_string()); 
        }
        //si la carga se hizo con exito, deja el estado de true
        salas.check=true;
        
        return salas; 
    }
    //sino se cargo correctamente, lanza una excepción
    catch(const std::exception& e)
    {
        std::cerr<< e.what()<<endl;
    } 
}


/*vector<Sala> cargarArchivoSala(string filename, int &numero_filas_sala, vector<Sala> vector_datos_sala){  
//cargar el archivo de Salas y devolver un vector con los datos 
    Sala salas;
    numero_filas_sala=0;
    xlnt::workbook SalasXlsx;
    try
    {   
        SalasXlsx.load(filename);
        auto ws = SalasXlsx.active_sheet();
        for (auto row : ws.rows(false)) 
        { 
            salas.edificio.push_back(row[0].to_string());
            salas.sala.push_back(row[1].to_string());
            vector_datos_sala[numero_filas_sala].edificio = salas.edificio;
            cout<<vector_datos_sala[numero_filas_sala].edificio.back;
            vector_datos_sala[numero_filas_sala].sala = salas.sala;
            numero_filas_sala++;
            
        }
        //si la carga se hizo con exito, deja el estado de true
        vector_datos_sala[numero_filas_sala].check=true;
        
        return vector_datos_sala; 
    }
    //sino se cargó correctamente, lanza una excepción
    catch(const std::exception& e)
    {
        std::cerr<< e.what()<<endl;
    } 
}*/

vector<Sala> datosArchivoSala(vector<Sala> sala_dato, string filename){ 
//función que guarda los datos del archivo sala en un objeto tipo sala y lo retorna
    xlnt::workbook SalasXlsx; 
    Sala salas;
    int i=0;
    SalasXlsx.load(filename);
    auto ws = SalasXlsx.active_sheet();
    auto row = ws.rows();
        //llenar vector 
        for (auto row : ws.rows(false)) 
        { 
            salas.edificio.push_back(row[0].to_string());
            //sala_dato[i].edificio= salas.edificio;
            salas.sala.push_back(row[1].to_string());
            //sala_dato[i].sala = salas.sala;
            sala_dato.push_back(salas);
            i++;
        }
    return sala_dato;
}


