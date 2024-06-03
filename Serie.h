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

#ifndef Serie_h
#define Serie_h

//Para herencia
#include "Video.h"
//Para composición
#include "Episodio.h"

#include <string>
#include <iostream>
#include <stdio.h> 
using namespace std;


class Serie : public Video {
private:
    Episodio episodios[5];
    int cantidad;

public:
    //Constructores
    Serie();
    Serie(string _iD, string _titulo, int _duracion, string _genero, double _calificacion);

    //Métodos modificadores
    void setEpisodio(int posicion, Episodio episodio);
    void setCantidad(int _cantidad);

    //Métodos de acceso
    Episodio getEpisodio(int posicion);
    int getCantidad();

    //Otros métodos
    double calculaPromedio();
    double calculaDuracion();
    std::string str();
    void agregaEpisodio(Episodio episodio);
};

#endif /* Serie_h */