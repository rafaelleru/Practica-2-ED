#ifndef CRONOLOGIA
#define CRONOLOGIA
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include "../include/Evento.h"

using namespace std;

class Cronologia{
 private:
  vector<*Evento> claves;
  vector<Evento> cronologia;
  //  pair<int, vector<string>> parseLine(string line);
 public:
  Cronologia(char* file);
  Cronologia();
  vector<string> getDateEvents(int date);
  void addEventToDate(int date, string event);
  void addMultipleEventsToDate(int date, vector<string> events);

  //Utils operators for this class
  Cronologia& operator=(Cronologia& c);
  Cronologia(Cronologia& c);
  //~Cronologia();
  Cronologia& operator+(Cronologia& c);
  Cronologia& operator-(Cronologia& c);
  bool operator==(Cronologia& c);
  bool operator!=(Cronologia& c);
  friend ostream& operator<<(ostream& o, Cronologia& c);
  friend ifstream& operator>>(ifstream& i, Cronologia& c);
};
#endif
