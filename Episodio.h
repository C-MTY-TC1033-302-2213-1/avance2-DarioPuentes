/*
Nombre: Dario Puentes Díaz
Matrícula: A00838287
Carrera: ITC
Fecha: 02 - Junio - 24
¿Que aprendí?
El uso de la composición para definir clases mas simples a partir de otras y menos dependientes
El overriding permite cambiar el cuerpo a conveniencia de un metodo de otra clase con el mismo encabezado
*/

#ifndef Episodio_h
#define Episodio_h

#include <stdio.h>
#include <string>
using namespace std;

class Episodio {
private:
    string titulo;
    int temporada;
    int calificacion;

public:
    //Constructores
    Episodio();
    Episodio(string _titulo, int _temporada, int _calificacion);

    //Métodos modificadores
    void setTitulo(string _titulo);
    void setTemporada(int _temporada);
    void setCalificacion(int _calificacion);

    //Métodos de acceso
    string getTitulo();
    int getTemporada();
    int getCalificacion();

    //Otros métodos
    std::string str();
};

#endif /* Episodio_h */