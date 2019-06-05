#include<iostream>
#include<ostream>
#include<stdlib.h>
#include<xlnt/xlnt.hpp>
#include"estructuras/CursoXLS.hpp"
#include"estructuras/DocenteXLS.hpp"
#include"estructuras/SalaXLS.hpp"
#include"estructuras/Bloque.hpp"


using namespace std;

int main(){
    
    //Bloque bloque[42];
    int filas_archivo_salas;
    

    DocenteXLS docente = cargarArchivoDocente("archivos/Docentes.xlsx");
    CursoXLS curso = cargarArchivoCurso("archivos/Cursos.xlsx");
    SalaXLS sala = cargarArchivoSala("archivos/Salas.xlsx");

    //*******************************

    SalaXLS datos_sala;

    datos_sala = datosArchivoSala(datos_sala,"archivos/Salas.xlsx");

        for (int i=0;i<=datos_sala.size();i++) { 
            cout<<"Dato ["<<i+1<<"]: "<<endl;
            /*for(int j=0; j<=datos_sala[i].edificio.size();j++){
                cout<<"Edificio: "<<datos_sala[i].edificio[j]<<endl;
                cout<<"Sala: "<<datos_sala[i].sala[j]<<endl;
            }*/
            mostrarFila(datos_sala[i],i);
            cout<<endl;
        }
    

    //*******************************

    
    if(docente.check==false){
        cout<<"ERROR: EL archivo DOCENTES no se pudo cargar"<<endl;
    }
    if(curso.check==false){
        cout<<"ERROR: EL archivo CURSOS no se pudo cargar"<<endl;
    }
    if(!sala.check){
        cout<<"ERROR: EL archivo SALAS no se pudo cargar"<<endl;
    }
    
    return 0;
}