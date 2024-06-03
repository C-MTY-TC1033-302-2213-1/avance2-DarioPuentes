/*
Nombre: Dario Puentes Díaz
Matrícula: A00838287
Carrera: ITC
Fecha: 02 - Junio - 24
Los apuntadores permiten guardar la dirección de un atributo y son del mismo tipo
Permiten usar instancias de diferentes clases en un solo metodo
En el polmorfismo se pueden definir todos los métodos en lugar de en el main
*/

#ifndef Polimorfismo_h
#define Polimorfismo_h

#include "Video.h"
#include <stdio.h>
#include <string>
using namespace std;

const int MAX_VIDEOS = 100;

class Polimorfismo{
    private:
    Video *arrPtrVideos[MAX_VIDEOS];
    int cantidad;

    public:
    //Constructores
    Polimorfismo();
    void leerArchivo(string nombre);

    //Métodos modificadores 
    void setPtrVideo(int index, Video *video);
    void setCantidad(int _cantidad);

    //Métodos de acceso
    Video* getPtrVideo(int _index);
    int getCantidad();

    //Otros métodos
    void reporteInventario();
    void reporteCalificacion(double _calificacion);
    void reporteGenero(string _genero);
    void reportePeliculas();
    void reporteSeries();

};

#endif /* Polimorfismo_h */