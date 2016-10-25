#ifndef CRONOLOGIA
#define CRONOLOGIA
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <list>
#include "../include/Evento.h"

using namespace std;

class Cronologia{
 private:
  list<Evento> cronologia;
  //  pair<int, vector<string>> parseLine(string line);
 public:
  Cronologia(char* file);
  Cronologia(vector<Evento> events);
  Cronologia();
  vector<string> getDateEvents(int date);
  void addEventToDate(int date, string event);
  void addMultipleEventsToDate(int date, vector<string> events);
  void addEvent(Evento e);
  size_t size();
  
  //Utils operators for this class
  Cronologia& operator=(const Cronologia& c);
  Cronologia(Cronologia& c);
  ~Cronologia();
  Cronologia& operator+(Cronologia& c);
  Cronologia& operator-(Cronologia& c);
  bool operator==(const Cronologia& c);
  bool operator!=(Cronologia& c);
  friend ostream& operator<<(ostream& o, Cronologia& c);
  friend istream& operator>>(istream& i, Cronologia& c);

  //methods for use like a STL TDA
  void resize(int newSize);
  void erase();
  void push_back(const Evento& event);
  
};
#endif
