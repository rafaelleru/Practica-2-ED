#include "../include/Evento.h"
#include <vector>

using namespace std;

Evento::Evento(int date, vector<string> events){
  this->evento.first = date;
  this->evento.second = events;
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
