/*
Nombre: Dario Puentes Díaz
Matrícula: A00838287
Carrera: ITC
Fecha: 02 - Junio - 24
¿Que aprendí?
Mediante la herencia podemos utilizar y compartir los atributos y métodos de otra clase para derivar una serie de clases de una clase base
La clase derivada debe incluir el .h de la clase base
La manera para heredar es usando ": public (clase base)"
Deben volverse a establecer los atributos de la clase base en los constructores
*/

#ifndef Pelicula_h
#define Pelicula_h

#include "Video.h"
#include <string>
#include <iostream>
#include <stdio.h> 
using namespace std;

// Clase Pelicula es derivada de Video
class Pelicula: public Video{
private:
    int oscares;

public:
    //Constructores default
    Pelicula();
    Pelicula(string _iD, string _titulo, int _duracion, string _genero, double _calificacion, int _oscares);

    //Metodos modificadores
    void setOscares(int _oscares);

    //Metodos de acceso
    int getOscares();

    //Otros metodos
    string str();
};

#endif /* Pelicula_h */