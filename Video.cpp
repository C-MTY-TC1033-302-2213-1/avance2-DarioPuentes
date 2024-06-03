/*
Nombre: Dario Puentes Díaz
Matrícula: A00838287
Carrera: ITC
Fecha: 02 - Junio - 24
*/

#include "Video.h"

//Constructores default
Video::Video(){
    iD = "0000";
    titulo = "Dario Puentes Díaz";
    duracion = 100;
    genero = "Computacion";
    calificacion = 100;
}

Video::Video(string _iD, string _titulo, int _duracion, string _genero, double _calificacion){
    iD = _iD;
    titulo = _titulo;
    duracion = _duracion;
    genero = _genero;
    calificacion = _calificacion;
}

//Métodos modificadores
void Video::setId(string _iD){
    iD = _iD;
}

void Video::setTitulo(string _titulo){
    titulo = _titulo;
}

void Video::setDuracion(int _duracion){
    duracion = _duracion;
}

void Video::setGenero(string _genero){
    genero = _genero;
}

void Video::setCalificacion(double _calificacion){
    calificacion = _calificacion;
}

//Metodos de acceso
string Video::getId(){
    return iD;
}

string Video::getTitulo(){
    return titulo;
}

int Video::getDuracion(){
    return duracion;
}

string Video::getGenero(){
    return genero;
}

double Video::getCalificacion(){
    return calificacion;
}

//Otros metodos
string Video::str(){
    return iD + " " + titulo + " " + std::to_string(duracion) + " " + genero + " " + std::to_string(calificacion);
} 