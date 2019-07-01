/*Estructura para manejar el vector principal con los bloques y salas que se asignaran*/

#include "Bloque.hpp"
#include <xlnt/xlnt.hpp>
#include <stdlib.h>

int incluido(vector<int> lista, int item) //verifica si un docente esta incluido o no en la lista
{
    for(int i=0; i<lista.size(); i++)
    {
        if( lista[i] == item)
        {
            return i;
        }
    }
    return -1;
}

Bloque validacion(vector<string>& codigos, vector<int>& horas, CursoXLS curso)
{

    //los datos ingresados son para llenar un solo bloque --> hoja del excel 
    vector<int> no_disponibles;
    vector<string> id_docentes;
    Bloque hoja_excel;
    string codigo_curso;
    int indice;
    int periodo;
    string dia;
    int asignado;

    for(int i=0; i<39; i++)
    {
        //cout << "celda: " << i << " | ";
        //obtengo bloque y dia
        dia = obtenerDia(i);
        //cout << "   dia:" << dia << endl;
        periodo = obtenerBloque(i);
        //cout << "   bloque : " << periodo << endl;

        //ingresar a un bloque y hora específica
        id_docentes = filtroBloqueDia( periodo, dia);

        //obtngo un profe  de  formma aleatoria en la lista obtenida en id_docentes
        int random = rand() % id_docentes.size();
            
        //busco que curso imparte el docente[i]
        codigo_curso = filtrarCursoPorDocente( curso, id_docentes[random]);
            
        //busco en que indice de la funcion obtener curso esta el codigo_curso
        for(int j=0; j<codigos.size(); j++)
        {
            if( codigo_curso == codigos[j])
            {
                indice = j;
            }
        }

        if( horas[indice] == 1)
        {
            hoja_excel.id_docente.push_back(id_docentes[i]);
            hoja_excel.codigo_curso.push_back(codigo_curso);
            //cout << " asignado------> " << i+1 << endl;

        }else
        {
            if(horas[indice]>0)
            {
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

int obtenerBloque(int indice) //obtiene el bloque correspondiente segun el indice
{
    int bloque;
    
    if(indice==0 || indice==1 || indice==2 || indice==3 || indice==4 || indice==5)
    {
        return bloque = 1;
    }
    if(indice==6 || indice==7 || indice==8 || indice==9 || indice==10 || indice==11)
    {
        return bloque = 2;
    }
    if(indice==12 || indice==13 || indice==14 || indice==15 || indice==16 || indice==17)
    {
        return bloque = 3;
    }
    if(indice==18 || indice==19 || indice==20 || indice==21 || indice==22 || indice==23)
    {
        return bloque = 4;
    }
    if(indice==24 || indice==25 || indice==26 || indice==27 || indice==28)
    {
        return bloque = 5;
    }
    if(indice==29 || indice==30 || indice==31 || indice==32 || indice==33)
    {
        return bloque = 6;
    }
    if(indice==34 || indice==35 || indice==36 || indice==37 || indice==38)
    {
        return bloque = 7;
    }

}

string obtenerDia(int indice)  //obtiene dia correspondiente segun el indice
{
    string dia;

    if(indice==0 || indice==6 || indice==12 || indice==18 || indice==24 || indice==29 || indice==34)
    {
        return dia = "Lunes";
    }
    if(indice==1 || indice==7 || indice==13 || indice==19 || indice==25 || indice==30 || indice==35)
    {
        return dia = "Martes";
    }
    if(indice==2 || indice==8 || indice==14 || indice==20 || indice==26 || indice==31 || indice==36)
    {
        return dia = "Miércoles";
    }
    if(indice==3 || indice==9 || indice==15 || indice==21 || indice==27 || indice==32 || indice==37)
    {
        return dia = "Jueves";
    }
    if(indice==4 || indice==10 || indice==16 || indice==22 || indice==28 || indice==33 || indice==38)
    {
        return dia = "Viernes";
    }
    if(indice==5 || indice==11 || indice==17 || indice==23){
        return dia = "Sábado";
    }

}

string asignarSala(SalaXLS Sala, int i) //retorna un string con el nombre de una sala concreta
{ 
    return Sala.edificio[i] + " - " + Sala.sala[i]; 
}

void crearformatoExcel(vector<Bloque> bloques, SalaXLS salas) //crea y llena el excel de salida
{

    xlnt::workbook excelSalida; //creo un excel de salida
    xlnt::worksheet hoja = excelSalida.active_sheet(); //activo la primera hora

    vector<string> columnas = {"C","D","E","F","G","H"};
    
    for(int j=0; j<bloques.size(); j++)
    { 
        cout << "SALA: " << j+1 << endl;
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

        /*int bloque = obtenerBloque(j);

        switch (bloque)
        {
        case 1: 
            for(int i=0; i<6; i++){
                celda = bloques[j].id_docente[i] + "-" + bloques[j].codigo_curso[i];
                hoja.cell(columnas[i]+"3").value(celda);
            }  
            hoja.next_row();
            break;
        case 2:
            for(int i=6; i<12; i++){
                celda = bloques[j].id_docente[i] + "-" + bloques[j].codigo_curso[i];
                hoja.cell(columnas[i]+"4").value(celda);
            }
            hoja.next_row();
            break;
        case 3:
            for(int i=12; i<18; i++){
                celda = bloques[j].id_docente[i] + "-" + bloques[j].codigo_curso[i];
                hoja.cell(columnas[i]+"5").value(celda);
            }
            hoja.next_row();
            break;
        case 4:
            for(int i=18; i<24; i++){
                celda = bloques[j].id_docente[i] + "-" + bloques[j].codigo_curso[i];
                hoja.cell(columnas[i]+"6").value(celda);
            }
            hoja.next_row();
            break;
        case 5:
            for(int i=24; i<29; i++){
                celda = bloques[j].id_docente[i] + "-" + bloques[j].codigo_curso[i];
                hoja.cell(columnas[i]+"7").value(celda);
            }
            hoja.next_row();
            break;
        case 6:
            for(int i=29; i<34; i++){
                celda = bloques[j].id_docente[i] + "-" + bloques[j].codigo_curso[i];
                hoja.cell(columnas[i]+"8").value(celda);
            }
            hoja.next_row();
            break;
        case 7:
            for(int i=34; i<39; i++){
                celda = bloques[j].id_docente[i] + "-" + bloques[j].codigo_curso[i];
                hoja.cell(columnas[i]+"9").value(celda);
            }
            hoja.next_row();
            break;
        default:
            break;
        }

        if(j>38){
            hoja = excelSalida.create_sheet();
        }*/

        //bloque 1
        for( i=0; i<=5; i++)
        {
            celda = bloques[j].id_docente[i] + "-" + bloques[j].codigo_curso[i];
            hoja.cell(columnas[i]+"3").value(celda);
            hoja.next_row();
        }

        //bloque 2
        for( i=6; i<=11; i++)
        {
            celda = bloques[j].id_docente[i] + "-" + bloques[j].codigo_curso[i];
            hoja.cell(columnas[i-6]+"4").value(celda);
            hoja.next_row();
        }

        //bloque 3
        for( i=12; i<=17; i++)
        {
            celda = bloques[j].id_docente[i] + "-" + bloques[j].codigo_curso[i];
            hoja.cell(columnas[i-12]+"5").value(celda);
            hoja.next_row();
        }

        //bloque 4
        for( i=18; i<=23; i++)
        {
            celda = bloques[j].id_docente[i] + "-" + bloques[j].codigo_curso[i];
            hoja.cell(columnas[i-18]+"6").value(celda);
            hoja.next_row();
        }

        //bloque 5
        for( i=24; i<=28; i++)
        {
            celda = bloques[j].id_docente[i] + "-" + bloques[j].codigo_curso[i];
            hoja.cell(columnas[i-24]+"7").value(celda);
            hoja.next_row();
        }

        //bloque 6
        for( i=29; i<=33; i++)
        {
            celda = bloques[j].id_docente[i] + "-" + bloques[j].codigo_curso[i];
            hoja.cell(columnas[i-29]+"8").value(celda);
            hoja.next_row();
        }

        //bloque 7
        for( i=34; i<=38; i++)
        {
            celda = bloques[j].id_docente[i] + "-" + bloques[j].codigo_curso[i];
            hoja.cell(columnas[i-34]+"9").value(celda);
            hoja.next_row();
        }

        if( j < bloques.size()){
            hoja = excelSalida.create_sheet();
        }
    }

    excelSalida.save("HORARIOS.xlsx");
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


