/*Estructura para manejar el vector principal con los bloques y salas que se asignaran*/

#include "Bloque.hpp"
#include <xlnt/xlnt.hpp>

string asignarSala(SalaXLS sala, int i){

    return sala.edificio[i] + " - " + sala.sala[i]; 
    //Obtengo los datos de las salas y los asigno en vector_final
    /*for(int j=0; j <sala.edificio.size(); j++){
        nombre = sala.edificio[j] + " - " + sala.sala[j];
        nombres.push_back(nombre);
    }
    cout << "SALAS asignadas" << endl;
    return sala.edificio;*/
}


/*vector<Bloque> asignarSalaXLS(SalaXLS sala, Bloque bloques){

    vector<Bloque> vector;

    //Obtengo los datos de las salas y los asigno en vector_final
        for(int j=0; j <sala.edificio.size(); j++){
            bloques.edificio = sala.edificio[j];
            bloques.sala = sala.sala[j];
            vector.push_back(bloques);
        }
        cout << "SALAS asignadas" << endl;
        return vector;
}*/


/*FUNCION QUE VERIFICA LOS PROFESORES DISPONIBLES Y LOS ASIGNA A CADA BLOQUE (POR HOJA)*/
/*void asignarProfesoresDisponibles(CursoXLS curso, DocenteXLS docentes, string nombre_sala){
    
    vector<DocenteXLS> disponibles;
    string codigo_curso;
    Bloque bloques[38]; //bloques donde se guardan los datos para el excel
    int i=1;

    for(int j=0; j<=38; j++){ //ciclos de bloques por hoja

            if(i>=7){ //verifica el contador de bloques diarios, para funcion filtrarbloque
                i=1;
            }
            
            cout << "LLEGO HASTA ACA******************" << endl;

            if(bloques[j].estado==false){ //si el bloque no esta asignado a ningun profesor

                //busco profesores disponibles en el bloque i
                disponibles = filtrarBloque(docentes,i);

                string identificador = disponibles[j].id_docente[j];

                //Busco ramo segun id_docente y lo asigno
                codigo_curso = filtrarCurso(curso, identificador);
                bloques[j].codigo_curso.push_back(codigo_curso); 

                //le cambio el estado a ocupado = true
                bloques[j].estado=true;

                //guardo los nuevos datos en el vector de salida
                //vector_salida.push_back(bloques[j]);
            }
            i++;
    }

    //string sala = bloques[0].edificio + "-" + vector_salida[0].sala;
    //Crea horario en excel (formato de salida) para una sala en especifico
    crearformatoExcel(bloques,nombre_sala);
}*/

Bloque asignarProfesoresDisponibles(CursoXLS curso, DocenteXLS docentes){

    Bloque bloque;
    vector<DocenteXLS> disponibles;
    string codigo_curso;
    int dia=1;

    for(int j=0; j<=38; j++){ //ciclos de bloques por hoja

        //cout << "Celda : " << j + 1 <<endl;

        if(dia>7){ //verifica el contador de bloques diarios, para funcion filtrarbloque
            dia=1;
        }
        
        if(bloque.estado==false){ //si el bloque no esta asignado a ningun profesor
            
            //cout << "LLEGO HASTA ACA******************" << endl;
            
            //obtengo profes disponibles segun un bloque "dia"
            //disponibles = filtrarBloque(docentes,dia);

            string identificador = hallarDisponible(docentes, dia); //obtengo el primero disponible
            //cout << "id_docente disponible: " <<identificador << endl;

            //Busco ramo segun id_docente y lo asigno
            codigo_curso = filtrarCursoPorDocente(curso, identificador);
            //cout << "Curso disponible " << codigo_curso << " y lo imparte el docente " << identificador << endl;


            //cout << codigo_curso << "|" << identificador <<endl ;
            bloque.id_docente.push_back(identificador);
            bloque.codigo_curso.push_back(codigo_curso); 

            if(bloque.id_docente.size()==39){
                    //le cambio el estado a ocupado = true
                bloque.estado=true;
            }

            //guardo los nuevos datos en el vector de salida
            //vector_salida.push_back(bloques[j]);
        }

        dia++;
    }
    //asignarSalaXLS(sala, bloque);
    //cout << bloque.codigo_curso[0]<<endl;
    return bloque;
}

void crearformatoExcel(vector<Bloque> bloques, SalaXLS salas){

    xlnt::workbook excelSalida; //creo un excel de salida
    xlnt::worksheet hoja = excelSalida.active_sheet(); //activo la primera hora

    vector<string> columnas = {"C","D","E","F","G","H"};

    for(int j=0;j<=5;j++){

        string celda;
        int i;

        //asignar nombre hoja
        hoja.title(asignarSala(salas, j));

        hoja.cell("C2").value("Lunes");
        hoja.cell("D2").value("Martes");
        hoja.cell("E2").value("Miercoles");
        hoja.cell("F2").value("Jueves");
        hoja.cell("G2").value("Viernes");
        hoja.cell("H2").value("Sabado");

        hoja.cell("B3").value("Bloque 1");
        hoja.cell("B4").value("Bloque 2");
        hoja.cell("B5").value("Bloque 3");
        hoja.cell("B6").value("Bloque 4");
        hoja.cell("B7").value("Bloque 5");
        hoja.cell("B8").value("Bloque 6");
        hoja.cell("B9").value("Bloque 7");

        //lleno el horario de la semana 

        //bloque 1
        for(i=0;i<=5;i++){
            celda = bloques[j].id_docente[i] + "-" + bloques[j].codigo_curso[i];
            hoja.cell(columnas[i]+"3").value(celda);
            hoja.next_row();
        }

        //bloque 2
        for(i=6;i<=11;i++){
            celda = bloques[j].id_docente[i] + "-" + bloques[j].codigo_curso[i];
            hoja.cell(columnas[i-6]+"4").value(celda);
            hoja.next_row();
        }

        //bloque 3
        for(i=12;i<=17;i++){
            celda = bloques[j].id_docente[i] + "-" + bloques[j].codigo_curso[i];
            hoja.cell(columnas[i-12]+"5").value(celda);
            hoja.next_row();
        }

        //bloque 4
        for(i=18;i<=23;i++){
            celda = bloques[j].id_docente[i] + "-" + bloques[j].codigo_curso[i];
            hoja.cell(columnas[i-18]+"6").value(celda);
            hoja.next_row();
        }

        //bloque 5
        for(i=24;i<=28;i++){
            celda = bloques[j].id_docente[i] + "-" + bloques[j].codigo_curso[i];
            hoja.cell(columnas[i-24]+"7").value(celda);
            hoja.next_row();
        }

        //bloque 6
        for(i=29;i<=33;i++){
            celda = bloques[j].id_docente[i] + "-" + bloques[j].codigo_curso[i];
            hoja.cell(columnas[i-29]+"8").value(celda);
            hoja.next_row();
        }

        //bloque 7
        for(i=34;i<=38;i++){
            
            celda = bloques[j].id_docente[i] + "-" + bloques[j].codigo_curso[i];
            //cout << i << endl;
            hoja.cell(columnas[i-34]+"9").value(celda);
            hoja.next_row();
        }

        //cout << bloques[5].id_docente[38] << endl;
    

        /*for(i=7;i<=13;i++){
            celda = bloques[j].id_docente[i] + "-" + bloques[j].codigo_curso[i];
            hoja.cell("D3").value(celda);
            hoja.next_row();
        }*/

        /*for(i=14;i<=20;i++){
            celda = bloques[j].id_docente[i] + "-" + bloques[j].codigo_curso[i];
            hoja.cell("E3").value(celda);
            hoja.next_row();
        }

        for(i=21;i<=27;i++){
            celda = bloques[j].id_docente[i] + "-" + bloques[j].codigo_curso[i];
            hoja.cell("F3").value(celda);
            hoja.next_row();
        }

        for(i=28;i<=34;i++){
            celda = bloques[j].id_docente[i] + "-" + bloques[j].codigo_curso[i];
            hoja.cell("G3").value(celda);
            hoja.next_row();
        }

        for(i=35;i<=bloques.size();i++){
            celda = bloques[j].id_docente[i] + "-" + bloques[j].codigo_curso[i];
            hoja.cell("H3").value(celda);
            hoja.next_row();
        }*/

        hoja = excelSalida.create_sheet();
    }

    excelSalida.save("HORARIOS.xlsx");
}

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
    //Al vector de bloquess bloques se le asigna una sala a cada uno
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

