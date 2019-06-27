#include"DocenteXLS.hpp"
#include<xlnt/xlnt.hpp>

DocenteXLS cargarArchivoDocente(string filename){ //carga archivo Docentes.xlsx

    DocenteXLS Docente;
    xlnt::workbook archivo;

    try
    {
        archivo.load(filename);
        auto hoja = archivo.active_sheet();

        for (auto row : hoja.rows(false)) 
        { 
            Docente.id_docente.push_back(row[0].to_string());
            Docente.nombre.push_back(row[1].to_string());
            Docente.apellido.push_back(row[2].to_string());
            Docente.bloque1.push_back(row[3].to_string());
            Docente.bloque2.push_back(row[4].to_string());
            Docente.bloque3.push_back(row[5].to_string());
            Docente.bloque4.push_back(row[6].to_string());
            Docente.bloque5.push_back(row[7].to_string());
            Docente.bloque6.push_back(row[8].to_string());
            Docente.bloque7.push_back(row[9].to_string());
        }

        Docente.check=true;
        return Docente;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

/* --------------------------------------------------------------------------------------*/

string hallarDisponible(DocenteXLS docenteXLS, int bloque){
    string id_disponible;

    string palabra = "DISPONIBLE";
    if(bloque < 8 && bloque > 0){
        switch(bloque){
            case 1:
                for (int i = 0; i < docenteXLS.id_docente.size(); i++){
                    if(docenteXLS.bloque1[i] == palabra){
                        return docenteXLS.id_docente[i];
                    }
                }
                break;
            case 2:
                for (int i = 0; i < docenteXLS.id_docente.size(); i++){
                    if(docenteXLS.bloque2[i] == palabra){
                        return docenteXLS.id_docente[i];
                    }
                }
                break;
            case 3:
                for (int i = 0; i < docenteXLS.id_docente.size(); i++){
                    if(docenteXLS.bloque3[i] == palabra){
                        return docenteXLS.id_docente[i];
                    }
                }
                break;
            case 4:
                for (int i = 0; i < docenteXLS.id_docente.size(); i++){
                    if(docenteXLS.bloque4[i] == palabra){
                        return docenteXLS.id_docente[i];
                    }
                }
                break;
            case 5:
                for (int i = 0; i < docenteXLS.id_docente.size(); i++){
                    if(docenteXLS.bloque5[i] == palabra){
                        return docenteXLS.id_docente[i];
                    }
                }
                break;
            case 6:
                for (int i = 0; i < docenteXLS.id_docente.size(); i++){
                    if(docenteXLS.bloque6[i] == palabra){
                        return docenteXLS.id_docente[i];
                    }
                }
                break;
            case 7:
                for (int i = 0; i < docenteXLS.id_docente.size(); i++){
                    if(docenteXLS.bloque7[i] == palabra){
                        return docenteXLS.id_docente[i];
                    }
                }
                break;
        }
    }
}

vector<DocenteXLS> filtrarBloque(DocenteXLS docenteXLS, int bloque){
    vector<DocenteXLS> disponibles;
    DocenteXLS docente;
    string palabra ="DISPONIBLE";
    if(bloque < 8 && bloque > 0){
        switch(bloque){
            case 1:
                for (int i = 0; i < docenteXLS.id_docente.size(); i++){
                    if(docenteXLS.bloque1[i] == palabra){
                        docente.id_docente[i] = docenteXLS.id_docente[i];
                        disponibles.push_back(docente);
                    }
                }
                break;
            case 2:
                for (int i = 0; i < docenteXLS.id_docente.size(); i++){
                    if(docenteXLS.bloque2[i] == palabra){
                        docente.id_docente[i] = docenteXLS.id_docente[i];
                        disponibles.push_back(docente);
                    }
                }
                break;
            case 3:
                for (int i = 0; i < docenteXLS.id_docente.size(); i++){
                    if(docenteXLS.bloque3[i] == palabra){
                        docente.id_docente[i] = docenteXLS.id_docente[i];
                        disponibles.push_back(docente);
                    }
                }
                break;
            case 4:
                for (int i = 0; i < docenteXLS.id_docente.size(); i++){
                    if(docenteXLS.bloque4[i] == palabra){
                        docente.id_docente[i] = docenteXLS.id_docente[i];
                        disponibles.push_back(docente);
                    }
                }
                break;
            case 5:
                for (int i = 0; i < docenteXLS.id_docente.size(); i++){
                    if(docenteXLS.bloque5[i] == palabra){
                        docente.id_docente[i] = docenteXLS.id_docente[i];
                        disponibles.push_back(docente);
                    }
                }
                break;
            case 6:
                for (int i = 0; i < docenteXLS.id_docente.size(); i++){
                    if(docenteXLS.bloque6[i] == palabra){
                        docente.id_docente[i] = docenteXLS.id_docente[i];
                        disponibles.push_back(docente);
                    }
                }
                break;
            case 7:
                for (int i = 0; i < docenteXLS.id_docente.size(); i++){
                    if(docenteXLS.bloque7[i] == palabra){
                        docente.id_docente[i] = docenteXLS.id_docente[i];
                        disponibles.push_back(docente);
                    }
                }
                break;
        }
    }
    return disponibles;
}

DocenteXLS cargarPorDia(string filename, string dia){
    DocenteXLS docente;
    xlnt::workbook archivo;

    try
    {
        archivo.load(filename);
        auto wd = archivo.sheet_by_title(dia);
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

vector<string> filtroBloqueDia(int bloque, string dia){

    DocenteXLS docente;
    vector<string> id_docentes;
    string palabra = "DISPONIBLE";

    docente = cargarPorDia("archivos/Docentes.xlsx", dia);

    if(bloque < 8 && bloque > 0){
        switch(bloque){
            case 1:
                for (int i = 0; i < docente.id_docente.size(); i++){
                    if(docente.bloque1[i] == palabra){
                        id_docentes.push_back(docente.id_docente[i]);
                    }
                }
                return id_docentes;
                break;
            case 2:
                for (int i = 0; i < docente.id_docente.size(); i++){
                    if(docente.bloque2[i] == palabra){
                        id_docentes.push_back(docente.id_docente[i]);
                    }
                }
                return id_docentes;
                break;
            case 3:
                for (int i = 0; i < docente.id_docente.size(); i++){
                    if(docente.bloque3[i] == palabra){
                        id_docentes.push_back(docente.id_docente[i]);
                    }
                }
                return id_docentes;
                break;
            case 4:
                for (int i = 0; i < docente.id_docente.size(); i++){
                    if(docente.bloque4[i] == palabra){
                        id_docentes.push_back(docente.id_docente[i]);
                    }
                }
                return id_docentes;
                break;
            case 5:
                for (int i = 0; i < docente.id_docente.size(); i++){
                    if(docente.bloque5[i] == palabra){
                        id_docentes.push_back(docente.id_docente[i]);
                    }
                }
                return id_docentes;
                break;
            case 6:
                for (int i = 0; i < docente.id_docente.size(); i++){
                    if(docente.bloque6[i] == palabra){
                        id_docentes.push_back(docente.id_docente[i]);
                    }
                }
                return id_docentes;
                break;
            case 7:
                for (int i = 0; i < docente.id_docente.size(); i++){
                    if(docente.bloque7[i] == palabra){
                        id_docentes.push_back(docente.id_docente[i]);
                    }
                }
                return id_docentes;
                break;
        }
    }
}

