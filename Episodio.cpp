/*
Nombre: Dario Puentes Díaz
Matrícula: A00838287
Carrera: ITC
Fecha: 20 - Mayo _ 24
*/

#include "Episodio.h"

//Constructores
Episodio::Episodio(){
    titulo = "1 umbrella academy";
    temporada = 0;
    calificacion = 0;
}

Episodio::Episodio(string _titulo, int _temporada, int _calificacion){
    titulo = _titulo;
    temporada = _temporada;
    calificacion = _calificacion;
}

//Métodos modificadores
void Episodio::setTitulo(string _titulo){
    titulo = _titulo;
}
void Episodio::setTemporada(int _temporada){
    temporada = _temporada;
}
void Episodio::setCalificacion(int _calificacion){
    calificacion = _calificacion;
}

//Métodos de acceso
string Episodio::getTitulo(){
    return titulo;
}
int Episodio::getTemporada(){
    return temporada;
}
int Episodio::getCalificacion(){
    return calificacion;
}

//Otros métodos
std::string Episodio::str(){
    return titulo + " " + std::to_string(temporada) + " " + std::to_string(calificacion);  
}