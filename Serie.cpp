/*
Nombre: Dario Puentes Díaz
Matrícula: A00838287
Carrera: ITC
Fecha: 02 - Junio - 24
*/

#include "Serie.h"

//Constructores
Serie::Serie():Video(){
    //solo vamos a inicializar cantidad
    cantidad = 0;
}

Serie::Serie(string _iD, string _titulo, int _duracion, string _genero, double _calificacion) : Video(_iD, _titulo, _duracion, _genero, _calificacion) {
    // solo vamos a inicializar cantidad
    cantidad = 0;
}

//Métodos modificadores
void Serie::setEpisodio(int posicion, Episodio episodio){
    //primero validar que existe ese episodio
    if(posicion >= 0 && posicion < cantidad){
        episodios[posicion] = episodio;
    }
}

void Serie::setCantidad(int _cantidad){
    cantidad = _cantidad;
}

//Métodos de acceso
Episodio Serie::getEpisodio(int posicion){
    //Crea un objeto del tipo Episodio y lo inicializa con el constructor default
    Episodio epi;

    //validar que exista el episodio solicitado (posicion)
    if(posicion >= 0 && posicion < cantidad){
        return episodios[posicion];
    }

    //Si no existe se retorna un default
    return epi;
}

//retorna el valor del atributo cantidad
int Serie::getCantidad(){
    return cantidad;
}

//Otros métodos
double Serie::calculaPromedio(){
    double acum = 0;
    for(int index = 0; index < cantidad; index++){
        acum = acum + episodios[index].getCalificacion();
    }

    //validar que tenga episodios
    if(cantidad > 0){
        return acum / cantidad;
    }
    else{
        return 0;
    }
}

void Serie::calculaDuracion(){
    int totalDuracion = 0;
    for (int index = 0; index < cantidad; index++) {
        totalDuracion += episodios[index].getTemporada();
    }
    totalDuracion = duracion;
}

//Overriding del metodo str() de la clase Base
std::string Serie::str() {
    std::string serieInfo = '\n' + iD + ' ' + titulo + ' ' + std::to_string(duracion) + ' ' + genero + ' ' + std::to_string(calificacion) + ' ' + std::to_string(cantidad);
    if (cantidad > 0) {
        std::string episodiosInfo;
        for (int i = 0; i < cantidad; i++) {
            episodiosInfo =  episodiosInfo + '\n' + episodios[i].getTitulo() + ' ' + std::to_string(episodios[i].getTemporada()) + ' ' + std::to_string(episodios[i].getCalificacion());
        }
        return serieInfo + episodiosInfo;
    }
    return serieInfo;
}

//Agrega un episodio solo si existe espacio
void Serie::agregaEpisodio(Episodio episodio){
    if(cantidad < 5){
        episodios[cantidad++] = episodio;
    }
}