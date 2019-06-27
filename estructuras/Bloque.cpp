/*Estructura para manejar el vector principal con los bloques y salas que se asignaran*/

#include "Bloque.hpp"
#include <xlnt/xlnt.hpp>


Bloque asignarProfesoresDisponibles(CursoXLS curso, DocenteXLS docentes){

    Bloque bloque;
    vector<DocenteXLS> disponibles;
    string codigo_curso;
    int dia=1;

    for(int j=0; j<=38; j++){ //ciclos de bloques por hoja

        if(dia>7){ //verifica el contador de bloques diarios, para funcion filtrarbloque
            dia=1;
        }
        
        if(bloque.estado==false){ //si el bloque no esta asignado a ningun profesor

            string identificador = hallarDisponible(docentes, dia); //obtengo el primero disponible

            //Busco ramo segun id_docente y lo asigno
            codigo_curso = filtrarCursoPorDocente(curso, identificador);

            bloque.id_docente.push_back(identificador);
            bloque.codigo_curso.push_back(codigo_curso); 

            if(bloque.id_docente.size()==39){
                //le cambio el estado a ocupado = true
                bloque.estado=true;
            }
        }

        dia++;
    }
    return bloque;
}

string asignarSala(SalaXLS Sala, int i){ //retorna un strign con el nombre de una sala concreta
    return Sala.edificio[i] + " - " + Sala.sala[i]; 
}

void crearformatoExcel(vector<Bloque> bloques, SalaXLS salas){

    xlnt::workbook excelSalida; //creo un excel de salida
    xlnt::worksheet hoja = excelSalida.active_sheet(); //activo la primera hora

    vector<string> columnas = {"C","D","E","F","G","H"};


    cout << bloques.size() << endl;

    for(int j=0;j<53;j++){ //ciclo por cada sala

        string celda;
        int i;

        //asignar nombre hoja
        hoja.title(asignarSala(salas, j+1));

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

        if(j < 52){
            hoja = excelSalida.create_sheet();
        }
        
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

}*/

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

/* --------------------------------------------------------------------------------------*/

void validacion(vector<string> id_docentes, vector<string> codigos, vector<int> horas, Bloque hoja_excel, CursoXLS curso){

    /*funcion que valida los datos y los guarda en la estructura bloque*/

    //los datos ingresados son para llenar un solo bloque --> hoja del excel

    string codigo_curso;
    int indice;
    int hora;

    for(int i=0; i<id_docentes.size(); i++){
        //busco que curso imparte el docente[i]
        codigo_curso = filtrarCursoPorDocente(curso, id_docentes[i]);
        //busco en que indice de la funcion obtener curso esta el codigo_curso
        for(int j=0; j<codigos.size(); j++){
            if(codigos[i]==codigo_curso){
                indice = j;
            }
        }
        //obtengo las horas del ramo codigo_curso
        hora = horas[indice];
        //hago la validación
        if(hora > 0){
            //guardo los datos en la estructura bloque
            hoja_excel.id_docente.push_back(id_docentes[i]);
            hoja_excel.codigo_curso.push_back(codigos[i]);
            hora--;
        }
        cout << "celda [ " << i+1 << " ]: " << endl;
        cout << hoja_excel.id_docente[i] << " - " << hoja_excel.codigo_curso[i] << endl;
        cout << "al ramo le quedan " << hora << " horas semanales" << endl;

    }

}