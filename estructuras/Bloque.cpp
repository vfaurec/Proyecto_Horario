/*Estructura para manejar el vector principal con los bloques y salas que se asignaran*/

#include "Bloque.hpp"
#include <xlnt/xlnt.hpp>

int incluido(vector<int> lista, int item){
    for(int i = 0; i < lista.size() ; i++){
        if(lista[i] == item){
            return i;
        }
    }
    return -1;
}

Bloque validacion(vector<string>& codigos, vector<int>& horas, CursoXLS curso){

    //los datos ingresados son para llenar un solo bloque --> hoja del excel 
    vector<int> no_disponibles;
    vector<string> id_docentes;
    
    Bloque hoja_excel;
    string codigo_curso;
    int indice;
    int periodo;
    string dia;
    int asignado;

        for(int i=0; i<39; i++){

            //cout << "celda: " << i << " | ";

            //obtengo bloque y dia
            dia = obtenerDia(i);
            //cout << "   dia:" << dia << endl;
            periodo = obtenerBloque(i);
            //cout << "   bloque : " << periodo << endl;

            //ingresar a un bloque y hora específica
            id_docentes = filtroBloqueDia(periodo, dia);
            
            //cout <<  "numero de docentes disponibles: " << id_docentes.size() << endl;
            //busco que curso imparte el docente[i]
            codigo_curso = filtrarCursoPorDocente(curso, id_docentes[i]);
            
            //busco en que indice de la funcion obtener curso esta el codigo_curso
            for(int j=0; j<codigos.size(); j++){
                if(codigo_curso==codigos[j]){
                    indice = j;
                }
            }

            if(horas[indice]==1){

                hoja_excel.id_docente.push_back(id_docentes[i]);
                hoja_excel.codigo_curso.push_back(codigo_curso);
                //cout << " asignado------> " << i+1 << endl;

            }else{
            
                if(horas[indice]>0){
                    //guardo los datos en la estructura bloque
                    hoja_excel.id_docente.push_back(id_docentes[i]);
                    hoja_excel.codigo_curso.push_back(codigo_curso);
                    horas[indice]--;
                    //cout << " asignado------> " << i+1 << endl;
                }

            }

        }    
    return hoja_excel;
}

int obtenerBloque(int indice){
    int bloque;
    //indice==0 || indice==1 || indice==2 || indice==3 || indice==4 || indice==5
    if(indice==0 || indice==1 || indice==2 || indice==3 || indice==4 || indice==5){
        return bloque = 1;
    }
    if(indice==6 || indice==7 || indice==8 || indice==9 || indice==10 || indice==11){
        return bloque = 2;
    }
    if(indice==12 || indice==13 || indice==14 || indice==15 || indice==16 || indice==17){
        return bloque = 3;
    }
    if(indice==18 || indice==19 || indice==20 || indice==21 || indice==22 || indice==23){
        return bloque = 4;
    }
    if(indice==24 || indice==25 || indice==26 || indice==27 || indice==28){
        return bloque = 5;
    }
    if(indice==29 || indice==30 || indice==31 || indice==32 || indice==33){
        return bloque = 6;
    }
    if(indice==34 || indice==35 || indice==36 || indice==37 || indice==38){
        return bloque = 7;
    }
}

string obtenerDia(int indice){
    string dia;
    if(indice==0 || indice==6 || indice==12 || indice==18 || indice==24 || indice==29 || indice==34){
        return dia = "Lunes";
    }
    if(indice==1 || indice==7 || indice==13 || indice==19 || indice==25 || indice==30 || indice==35){
        return dia = "Martes";
    }
    if(indice==2 || indice==8 || indice==14 || indice==20 || indice==26 || indice==31 || indice==36){
        return dia = "Miércoles";
    }
    if(indice==3 || indice==9 || indice==15 || indice==21 || indice==27 || indice==32 || indice==37){
        return dia = "Jueves";
    }
    if(indice==4 || indice==10 || indice==16 || indice==22 || indice==28 || indice==33 || indice==38){
        return dia = "Viernes";
    }
    if(indice==5 || indice==11 || indice==17 || indice==23){
        return dia = "Sábado";
    }
}

/* --------------------------------------------------------------------------------------*/


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

string asignarSala(SalaXLS Sala, int i){ //retorna un string con el nombre de una sala concreta
    return Sala.edificio[i] + " - " + Sala.sala[i]; 
}

void crearformatoExcel(vector<Bloque> bloques, SalaXLS salas){

    xlnt::workbook excelSalida; //creo un excel de salida
    xlnt::worksheet hoja = excelSalida.active_sheet(); //activo la primera hora

    vector<string> columnas = {"C","D","E","F","G","H"};


    cout << bloques.size() << endl;

    for(int j=0;j<54;j++){ //ciclo por cada sala

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