/*
Nombre: Dario Puentes Díaz
Matrícula: A00838287
Carrera: ITC
Fecha: 02 - Junio - 24
*/

#include "Polimorfismo.h"
#include "Pelicula.h"
#include "Serie.h"
#include "Episodio.h"
#include "Video.h"

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <typeinfo>
using namespace std;

Polimorfismo::Polimorfismo(){
    for(int index = 0; index < MAX_VIDEOS; index++){
        arrPtrVideos[index] = nullptr;
    }
    cantidad = 0;
}

//Métodos modificadores 
void Polimorfismo::setPtrVideo(int index, Video *video){
    //Validar index - >= 0 && < cantidad
    if (index >= 0 && index < cantidad){
        //Modificar el apuntador
        arrPtrVideos[index] = video;
    }
}

//Cambia el valor del atributo cantidad
//Deber ser entre 0 ... MAX_VIDEOS - 1
void Polimorfismo::setCantidad(int _cantidad){
    //Validar el valor de cantidad
    if (_cantidad >= 0 && _cantidad <= MAX_VIDEOS){
        cantidad = _cantidad;
    }
}

//Métodos de acceso
Video* Polimorfismo::getPtrVideo(int _index){
    //Validar que exista el index
    if (_index >=0 && _index < cantidad){
        return arrPtrVideos[_index];
    }
    return nullptr;
}

int Polimorfismo::getCantidad(){
    return cantidad;
}

//Otros métodos
void Polimorfismo::reporteInventario(){
    //Declaracion de contadores
    int PeliculasCont, SeriesCont;
    PeliculasCont = 0;
    SeriesCont = 0;
    //Recorrer todo el arreglo de ptr usando un for
    for (int index = 0; index < cantidad; index++){
        // * indirección (ptr) genera el objeto
        if (typeid(*arrPtrVideos[index]) == typeid(Pelicula)){
            PeliculasCont ++;
        }
        else if (typeid(*arrPtrVideos[index]) == typeid(Serie)){
            SeriesCont ++;
        }
        cout << arrPtrVideos[index]->str() << endl;
    }
    //Fuera del for desplegar los totales
    cout << "Peliculas = " << PeliculasCont << endl;
    cout << "Series = " << SeriesCont << endl;
}

void Polimorfismo::reporteCalificacion(double _calificacion){
    //Contador total
    int total;
    //Inicializar el contador
    total = 0;
    for (int index = 0; index < cantidad; index++){
        //Verificar si tiene la calificacion == _calificacion
        if (arrPtrVideos[index]->getCalificacion() == _calificacion){
            cout << arrPtrVideos[index]->str() << endl;
            total ++;
        }
    }
    //Desplegar el total fuera del for
    cout << "Total = " << total << endl;
}

void Polimorfismo::reporteGenero(string _genero){
    int total;
    total = 0;
    for(int index = 0; index < cantidad; index++){
        if (arrPtrVideos[index]->getGenero() == _genero){
            cout << arrPtrVideos[index]->str() << endl;
            total ++;
        }
    }
    cout << "Total = " << total << endl;
}

void Polimorfismo::reportePeliculas(){
    int total;
    total = 0;
    for(int index = 0; index < cantidad; index++){
        if (typeid(*arrPtrVideos[index]) == typeid(Pelicula)){
            cout << arrPtrVideos[index]->str() << endl;
            total ++;
        }
    }

    //Verificar que haya peliculas
    if (total > 0){
        cout << "Total Peliculas = " << total << endl;   
    }
    else {
        cout << "No peliculas" << endl;
    }
}

void Polimorfismo::reporteSeries(){
    int total;
    total = 0;
    for(int index = 0; index < cantidad; index++){
        if (typeid(*arrPtrVideos[index]) == typeid(Serie)){
            cout << arrPtrVideos[index]->str() << endl;
            total ++;
        }
    }

    //Verificar que haya series
    if (total > 0){
        cout << "Total Series = " << total << endl;   
    }
    else {
        cout << "No series" << endl;
    }
}

void Polimorfismo::leerArchivo(string nombre) {
    Serie *arrPtrSeries[50];
    Pelicula *arrPtrPeliculas[50];
    Episodio episodio;
    std::fstream entrada;
    string row[7];
    string line, word;
    int cantidadPeliculas = 0;
    int cantidadSeries = 0;
    int iR = 0, index;
    double promedio;

    entrada.open(nombre, ios::in); // abre el archivo de entrada

    while (getline(entrada, line)) {
        stringstream s(line);
        iR = 0;

        while (getline(s, word, ',')) {
            row[iR++] = word;
        }

        if (row[0] == "P") {
            arrPtrPeliculas[cantidadPeliculas] = new Pelicula(row[1], row[2], stoi(row[3]), row[4], stod(row[5]), stoi(row[6]));
            cantidadPeliculas++;
        } else if (row[0] == "S") {
            arrPtrSeries[cantidadSeries] = new Serie(row[1], row[2], stoi(row[3]), row[4], stod(row[5]));
            cantidadSeries++;
        } else if (row[0] == "E") {
            index = stoi(row[1]) - 500;
            arrPtrSeries[index]->agregaEpisodio(*(new Episodio(row[2], stoi(row[3]), stoi(row[4]))));
        }
    }

    for (int index = 0; index < cantidadSeries; index++) {
        promedio = arrPtrSeries[index]->calculaPromedio();
        arrPtrSeries[index]->setCalificacion(promedio);
        arrPtrSeries[index]->calculaDuracion();
        arrPtrVideos[cantidad++] = arrPtrSeries[index];
    }

    for (int index = 0; index < cantidadPeliculas; index++) {
        arrPtrVideos[cantidad++] = arrPtrPeliculas[index];
    }

    entrada.close();
} 