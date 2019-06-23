/*Estructura para manejar el vector principal con los bloques y salas que se asignaran*/

#include "Bloque.hpp"
#include <xlnt/xlnt.hpp>

void asignarSalaXLS(SalaXLS sala, Bloque objeto, vector<Bloque> vector){
    //Obtengo los datos de las salas y los asigno en vector_final
        for(int j=0; j <sala.edificio.size(); j++){
            //cout << "Bloque "<< j <<endl;
            objeto.edificio = sala.edificio[j];
            objeto.sala = sala.sala[j];
            vector.push_back(objeto);
            //cout << "edificio: " << vector[j].edificio<< endl;
            //cout << "sala: " << vector[j].sala<<endl;
            //cout << "\n ******************** \n"<<endl;
        }
        cout << "SALAS asignadas" << endl;
}

/*FUNCION QUE VERIFICA LOS PROFESORES DISPONIBLES Y LOS ASIGNA A CADA BLOQUE (POR HOJA)*/
void asignarProfesoresDisponibles(CursoXLS curso, DocenteXLS docentes, vector<Bloque> vector_salida){
    
    vector<DocenteXLS> disponibles;
    string codigo_curso;
    Bloque objeto[38]; //objeto donde se guardan los datos para el excel
    int i=1;

    for(int j=0; j<=38; j++){ //ciclosde bloques por hoja
            if(i>=7){ //verifica el contador de bloques diarios
                i=1;
            }
            cout<<"LLEGO HASTA ACAAAA*************"<<endl;
            if(vector_salida[j].estado==false){ //si el bloque no esta asignado a ningun profesor
                //busco profesores disponibles en el bloque i
                disponibles = filtrarBloque(docentes,i);
                string identificador = disponibles[i].id_docente[i];
                //Busco ramo segun id_docente y lo asigno
                codigo_curso = filtrarCurso(curso, identificador);
                vector_salida[j].codigo_curso.push_back(codigo_curso); 
                //le cambio el estado a ocupado = true
                vector_salida[j].estado=true;
                //guardo los nuevos datos en el vector de salida
                vector_salida.push_back(objeto[j]);
            }
            i++;
    }
    string sala = vector_salida[0].edificio + "-" + vector_salida[0].sala;
    //Crea horario en excel (formato de salida) para una sala en especifico
    crearformatoExcel(objeto,sala);
}

void crearformatoExcel(Bloque objeto[], string nombre_hoja){

    int i;
    string celda;

    xlnt::workbook excelSalida; //creo un excel de salida
    xlnt::worksheet hoja = excelSalida.active_sheet(); //activo la primera hora

    hoja.title(nombre_hoja); //nombre de la sala correspondiente

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

    for(i=0;i<=6;i++){
        celda = objeto[i].id_docente[i] + "-" + objeto[i].codigo_curso[i];
        hoja.cell("C3").value(celda);
        hoja.next_row();
    }
        
    for(i=7;i<=13;i++){
        celda = objeto[i].id_docente[i] + "-" + objeto[i].codigo_curso[i];
        hoja.cell("D3").value(celda);
        hoja.next_row();
    }

    for(i=14;i<=20;i++){
        celda = objeto[i].id_docente[i] + "-" + objeto[i].codigo_curso[i];
        hoja.cell("E3").value(celda);
        hoja.next_row();
    }

    for(i=21;i<=27;i++){
        celda = objeto[i].id_docente[i] + "-" + objeto[i].codigo_curso[i];
        hoja.cell("F3").value(celda);
        hoja.next_row();
    }

    for(i=28;i<=34;i++){
        celda = objeto[i].id_docente[i] + "-" + objeto[i].codigo_curso[i];
        hoja.cell("G3").value(celda);
        hoja.next_row();
    }

    for(i=35;i<=39;i++){
        celda = objeto[i].id_docente[i] + "-" + objeto[i].codigo_curso[i];
        hoja.cell("H3").value(celda);
        hoja.next_row();
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

