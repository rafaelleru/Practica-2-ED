#ifndef EVENTO
#define EVENTO
#include <vector>
#include <string>
#include <utility> //para usar pair

using namespace std;

class Evento{
 private:
  //Un evento es un par de año y acontecimientos
  pair<int, vector<string> > evento;
 public:
  Evento(int date, vector<string> events);
  Evento();
  Evento(Evento& e);
  vector<string> getEvents();
  int getDate();
  void addEvents(int year, vector<string> events);
  void addSingleEvent(string event);

  //operadores
  bool operator==(Evento& e);
  bool operator!=(Evento& e);
  Evento& operator=(Evento& e);
  friend ostream& operator<<(ofstream& o, Evento& e);
  friend istream& operator>>(ifstream& i, Evento& e);
};

#endif
