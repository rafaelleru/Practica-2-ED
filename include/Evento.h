#ifndef EVENTO
#define EVENTO
#include <vector>
#include <string>
#include <utility> //para usar pair

using namespace std;

class Evento{
 private:
  /*
  @brief pareja de entero y vector de string
  @param int
  @param array de string
  */
  pair<int, vector<string> > evento;
 public:
  /*
  @brief constructor de la clase Evento
  @param int date
  @param array de string events
  */
  Evento(int date, vector<string> events);
  Evento(int date, string event);
  Evento();
  Evento(const Evento& e);
  vector<string> getEvents();
  int getDate();
  void addEvents(vector<string> events);
  void addSingleEvent(string event);

  //operadores
  bool operator<(const Evento& e);
  bool operator>(const Evento& e);
  bool operator==(const Evento& e) const;
  bool operator!=(const Evento& e) const;
  Evento& operator=(const Evento& e);
  friend ostream& operator<<(ostream& o, Evento& e);
  friend istream& operator>>(istream& i, Evento& e);
};

#endif
