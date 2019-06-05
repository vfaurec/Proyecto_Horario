/*Estructura para manejar archivo docentes.xlnt*/

#include"Docente.hpp"
#include<xlnt/xlnt.hpp>

void mostrarFila(Docente docente, int indice){
    cout<<"identificador: "<<docente.id_docente[indice]<<endl;
    cout<<"nombre: "<<docente.nombre[indice]<<endl;
    cout<<"apellido: "<<docente.apellido[indice]<<endl;
    cout<<"bloque 1: "<<docente.bloque1[indice]<<endl;
    cout<<"bloque 2: "<<docente.bloque2[indice]<<endl;
    cout<<"bloque 3: "<<docente.bloque3[indice]<<endl;
    cout<<"bloque 4: "<<docente.bloque4[indice]<<endl;
    cout<<"bloque 5: "<<docente.bloque5[indice]<<endl;
    cout<<"bloque 6: "<<docente.bloque6[indice]<<endl;
    cout<<"bloque 7: "<<docente.bloque7[indice]<<endl;
    cout<<endl;
}

void filtrarDocente(Docente docente, string nombre){
    for(int i=1;i<docente.nombre.size();i++){
        if(docente.nombre[i]== nombre){
            mostrarFila(docente,i);
        }
    }
}

Docente cargarArchivoDocente(string filename){
    Docente docente;
    xlnt::workbook DocentesXlsx;
    try
    {
        DocentesXlsx.load(filename);
        auto wd = DocentesXlsx.active_sheet();
        for (auto row : wd.rows(false)) 
        { 
            docente.id_docente.push_back(row[0].to_string());
            docente.nombre.push_back(row[1].to_string());
            docente.apellido.push_back(row[2].to_string());
            docente.bloque1.push_back(row[3].to_string());
            docente.bloque2.push_back(row[4].to_string());
            docente.bloque3.push_back(row[5].to_string());
            docente.bloque4.push_back(row[6].to_string());
            docente.bloque5.push_back(row[7].to_string());
            docente.bloque6.push_back(row[8].to_string());
            docente.bloque7.push_back(row[9].to_string());
            }
        docente.check=true;
        return docente;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
    
    