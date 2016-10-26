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

Evento getDatos(const char* line){
  char year [4];
  for(int i=0; i < 4; i++){
    year[i] = line[i];
  }

  int year_t = atoi(year);
  string aux;
  vector<string> eventos;
  
  for(int i=5; line[i] != '\0'; ++i){
    if(line[i] != '#'){
      aux.push_back(line[i]);
    }else{
      //      cout << aux << endl;
      eventos.push_back(aux);
      aux.clear();
    }
  }

  Evento result(year_t, eventos);
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
  // Evento aux;
  while(!toRead.eof()){
    getline(toRead, line);
    const char * line_c = line.c_str();
    Evento aux = getDatos(line_c);
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
  list<Evento>::iterator it = this->cronologia.begin();
  vector<string> ret;
  bool _find = false;
  for(it; it != this->cronologia.end() && !_find; ++it){
    if(it->getDate() == date){
      _find = true;
      ret = it->getEvents();
    }
  }
  return ret;
}

/**
 @brief añade unnuevo acontecimiento a la fecha dada
 @param date el año al que se quiere añadir un evento
 @param event descripcion del evento a añadir
*/
void Cronologia::addEventToDate(int date, string event){
  list<Evento>::iterator it;
  for(it = this->cronologia.begin(); it->getDate() < date; ++it){
    if(it->getDate() == date){
      it->addSingleEvent(event);
    }else{
      Evento aux(date, event);
      this->cronologia.push_back(aux);
      this->cronologia.sort();
    }
  }
}

void Cronologia::addEvent(Evento e){
  this->cronologia.push_back(e);
  this->cronologia.sort();
}


/**
 @brief añade nuevos acontecimiento a la fecha dada
 @param date el año al que se quiere añadir un evento
 @param events descripcion de los eventos a añadir
*/
void Cronologia::addMultipleEventsToDate(int date, vector<string> events){
  list<Evento>::iterator it;
  for(it = this->cronologia.begin(); it->getDate() < date; ++it){
    if(it->getDate() == date){
      it->addEvents(events);
    }else{
      Evento aux(date, events);
      this->cronologia.push_back(aux);
      this->cronologia.sort();
    }
  }
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

  size_t Cronologia::size(){
    return this->cronologia.size();
  }

istream& operator>>(istream& i, Cronologia& c){
  char* line_s = new char[10000];

  while(!i.eof()){
    i.getline(line_s, 10000);
    //cout << line_s << endl;
    c.addEvent(getDatos(line_s));
    }
  return i;
}

  //--------------------------------------------------------------------------------
  //                                   Metodos privados
  //--------------------------------------------------------------------------------
