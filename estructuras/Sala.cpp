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

Sala cargarSala(string filename){
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
        sala.check=true;
        return sala;
    }
    catch(const std::exception& e)
    {
        std::cerr<< e.what()<<endl;
    } 
}