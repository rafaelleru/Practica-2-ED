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

Evento getDatos(string line){
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
      //cout << aux << endl;
      //events.push_back(aux);
      aux.clear();
    }
  }
  
  result.addEvents(year, events);
  return result;
}

/**
   @brief Crea un nuevo objeto cronologia a partir de un archivo
   que contiene datos y fechas en el formato <fecha>#evento#evento
   @param file archivo que contiene los datos de la cronologia
 */
Cronologia::Cronologia(char* file){
  ifstream toRead (file);
  string line;
  Evento aux;
  while(!toRead.eof()){
    getline(toRead, line);
    Evento aux(getDatos(line));
    this->cronologia.push_front(aux);
    }
}
/**
   @brief Crea una nueva cronologia a partir de un vector de eventos
   @param events Los eventos que se quieren añadir a la cronologia
*/
Cronologia::Cronologia(vector<Evento> events){
  for(Evento e: events){
    this->cronologia.push_front(e);
    this->cronologia.sort();
  }
}

/**
   @brief libera memoria
*/

Cronologia::~Cronologia(){
}

/**
 @brief funcion que devuelve los eventos que ocurrieron en una fecha dada
 @date fecha de la que se quieren conocer los enventos
 @return array de string que contiene la descripcion de los eventos
*/
vector<string> Cronologia::getDateEvents(int date){
  if(date < this->cronologia.size()/2){
    list<Evento>::iterator it = this->cronologia.begin();
    for(it; it->getDate() <= date; ++it){
      if(it->getDate() == date){
	return it->getEvents();
      }
    }
  }else{
    list<Evento>::iterator it = this->cronologia.end();
    for(it; it->getDate() < date; --it){
      if(it->getDate() == date){
	return it->getEvents();
      }
    }
  } 
}

/**
 @brief añade unnuevo acontecimiento a la fecha dada
 @param date el año al que se quiere añadir un evento
 @param event descripcion del evento a añadir
*/
void Cronologia::addEventToDate(int date, string event){
  for(Evento e: cronologia){
  }
}


/**
 @brief añade nuevos acontecimiento a la fecha dada
 @param date el año al que se quiere añadir un evento
 @param events descripcion de los eventos a añadir
*/
void Cronologia::addMultipleEventsToDate(int date, vector<string> events){
  
}

/**
   @brief Operador de asignacion
   @param c cronologia a asignar en this
*/
Cronologia& Cronologia::operator=(const Cronologia& c){
  if(this != &c){
    this->cronologia = c.cronologia;
  }
  return *this;
}

/**
   @brief devuelve si los dos vectores de eventos son iguales, ya que entonces
   el vector de claves sera igual.
   @param c la cronologia con la que se compara
*/
bool Cronologia::operator==(const Cronologia& c){
  return this->cronologia == c.cronologia;
}




ostream& operator<<(ostream& o, Cronologia& c){
  for(Evento e: c.cronologia){
    o << e.getDate() << endl;
    for(string s: e.getEvents()){
      o << s << endl;
    }
    o << endl;
  }

  return o;
}



  //--------------------------------------------------------------------------------
  //                                   Metodos privados
  //--------------------------------------------------------------------------------
