/*
Nombre: Dario Puentes Díaz
Matrícula: A00838287
Carrera: ITC
Fecha: 02 - Junio - 24
¿Que aprendí?
La importancia de separar los archivos .h de los .cpp para tener un mejor orden
Los #include son en el .h y este debe llevar header guards
Los .cpp solamente incluyen su respectivo .h
La clase base debe usar protected en lugar de private para que los atributos puedan usarse
El metodo str debe ser virtual para utilizar el string del tipo de apuntador 
*/

#ifndef Video_h
#define Video_h

#include <stdio.h>
#include <string>
using namespace std;

class Video {
protected:
    string iD;
    string titulo;
    int duracion;
    string genero;
    double calificacion;

public:
    //Constructores default
    Video();
    Video(string _iD, string _titulo, int _duracion, string _genero, double _calificacion);

    //Métodos modificadores
    void setId(string _iD);
    void setTitulo(string _titulo);
    void setDuracion(int _duracion);
    void setGenero(string _genero);
    void setCalificacion(double _calificacion);

    //Metodos de acceso
    string getId();
    string getTitulo();
    int getDuracion();
    string getGenero();
    double getCalificacion();

    //Otros metodos
    virtual string str(); //Virtual para utilizar el string del tipo de apuntador
};

#endif /* Video_h */