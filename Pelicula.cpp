/*
Nombre: Dario Puentes Díaz
Matrícula: A00838287
Carrera: ITC
Fecha: 02 - Junio - 24
¿Que aprendí?
*/

#include "Pelicula.h"

//Constructores default
Pelicula::Pelicula() : Video(){
    oscares = 100;
}

Pelicula::Pelicula(string _iD, string _titulo, int _duracion, string _genero, double _calificacion, int _oscares) : Video(_iD, _titulo, _duracion, _genero, _calificacion){
    oscares = _oscares;
}

//Metodos modificadores
void Pelicula::setOscares(int _oscares){
    oscares = _oscares;
}

//Metodos de acceso
int Pelicula::getOscares(){
    return oscares;
}

//Otros metodos
string Pelicula::str(){
    //tenemos acceso directo a los atributos de la clase padre porque son protected
    return iD + " " + titulo + " " + std::to_string(duracion) + " " + genero + " " + std::to_string(calificacion) + " " + std::to_string(oscares);
}