#include "../include/Evento.h"
#include <vector>

using namespace std;

Evento::Evento(){
  evento.first = 0;
}

Evento::Evento(int date, string event){
  this->evento.first = date;
  this->evento.second.push_back(event);
}

Evento::Evento(int date, vector<string> events){
  this->evento.first = date;
  this->evento.second = events;
}

Evento::Evento(const Evento &e){
  this->evento = e.evento;
}

int Evento::getDate(){
  return this->evento.first;
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

bool Evento::operator==(const Evento& e) const {
  bool igual = false;
  if ( this->evento.first == e.evento.first &&
       this->evento.second.size() == e.evento.second.size() ){
    for(int i=0; i<this->evento.second.size(); ++i){
      if( this->evento.second.at(i) == e.evento.second.at(i) )
	igual = true;
    }
  }

  return igual;
}

bool Evento::operator!=(const Evento& e) const {
  return !(*this == e);
}

bool Evento::operator>(const Evento& e){
  return this->evento.first > e.evento.first;
}

bool Evento::operator<(const Evento &e){
  return !(*this > e);
}

Evento& Evento::operator=(const Evento& e){
  if(this != &e){
    this->evento = e.evento;
  }
  return *this;
}

ostream& Evento::operator<<(ostream& o, Evento& e){
  o << e.evento.first;
  for(string s: e.evento.second)
    o << s <<;
  return o;
}

istream& Evento::operator>>(istream& i, Evento& e){
  i >> e.evento.secon;
  return i;
}
