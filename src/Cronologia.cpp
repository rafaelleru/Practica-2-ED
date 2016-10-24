#include "../include/Cronologia.h"
#include "../include/Evento.h"
#include <fstream>
#include <map>
#include <utility>
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>

using namespace std;

Evento& getDatos(string line){
  vector<string> events;
  Evento result;

  
  int year = atoi(line.substr(0, 4).c_str());
  line.erase(line.begin(), line.begin() + 4);

  // TODO: es raro a ver si se puede hacermejor
  const char* cosa = line.c_str();
  string aux;
  for(int i=0; i < line.length(); ++i){
    if(cosa[i] != '#'){
      char added = cosa[i];
      aux += added;
    } else {
      events.push_back(aux);
    }
  }
  cout << aux << endl;
  events.push_back(aux);
  aux.clear();
  
  result.addEvents(year, events);
  return result;
}

/**
 @brief Crea un nuevo objeto cronologia a partir de un archivo
 que contiene datos y fechas en el formato <fecha>#evento#evento
 @param file archivo que contiene los datos de la cronologia
 */
Cronologia::Cronologia(char* file){
  claves = new Evento[2016];
  ifstream toRead (file);
  string line;
  Evento aux;
  while(!toRead.eof()){
    getline(toRead, line);
    //cout << cronologia.size() << endl;
    aux = getDatos(line);
    int year = aux.getDate();
    this->claves[year] = aux;
    this->cronologia.push_back(aux);
    cout << cronologia.size() << endl;
  }
}

/**
 @brief funcion que devuelve los eventos que ocurrieron en una fecha dada
 @date fecha de la que se quieren conocer los enventos
 @return array de string que contiene la descripcion de los eventos
*/
vector<string> Cronologia::getDateEvents(int date){
  vector<string> result;
  //cout << this->cronologia.size() << endl;
  //result = *(claves[date]).getEvents(date);
  return result;
}

/**
 @brief añade unnuevo acontecimiento a la fecha dada
 @param date el año al que se quiere añadir un evento
 @param event descripcion del evento a añadir
*/
void Cronologia::addEventToDate(int date, string event){
  //  cronologia[date].push_back(event);
}


/**
 @brief añade nuevos acontecimiento a la fecha dada
 @param date el año al que se quiere añadir un evento
 @param events descripcion de los eventos a añadir
*/
void Cronologia::addMultipleEventsToDate(int date, vector<string> events){
  //  cronologia[date].insert(cronologia[date].begin(), events.begin(), events.end() -1);
}


  




  //--------------------------------------------------------------------------------
  //                                   Metodos privados
  //--------------------------------------------------------------------------------
