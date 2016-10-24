#include "../include/Evento.h"
#include <vector>

using namespace std;

Evento::Evento(){
  evento.first = 0;
  evento.second = 
}

Evento::Evento(int date, vector<string> events){
  this->evento.first = date;
}

Evento::Evento(Evento &e){
  this->evento = e.evento;
}

vector<string> Evento::getEvents(){
  return this->evento.second;
}

void Evento::addEvents(vector<string> events){
  this->evento.second.insert(this->evento.second.end(), events.begin(), events.end());
}

void Evento::addSingleEvent(string event){
  this->evento.second.insert(this->evento.second.end(), event);
}

bool Evento::operator==(Evento& e){
  bool igual = false;
  if ( this->evento.first == e.first &&
      this->evento.second.size() == e.second.size() ){
    for(int i=0; i<this->evento.second.size(); ++i){
      if( this->evento.second.at(i) == e.second.at(i) )
	igual = true;
    }
  }

  return igual;
}
