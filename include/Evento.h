#ifndef EVENTO
#define EVENTO
#include <vector>
#include <string>
#include <utility> //para usar pair

using namespace std;

class Evento{
 private:

  /**
   * @page repConjunto2 Representacion del TDA Evento
   * @section invConjunto Invariante de la representacion
   * El invariante es que la fecha del evento  no puede ser menos que 5000
   * @section fcAbstraccion Funcion de abstracion
   * Un objeto valido del TDA Evento presentea un valor de tipo:
   * año, descripcion de los acontecimientos ocurridos en ese año
   */
  pair<int, vector<string> > evento;
 public:
  /**
   * @brief Constructor de un evento con multiples descriciones 
   * de acontecimientos
   * @param date la fecha en la que sucedieron los acontecimientos
   * @param events las descripciones de los eventos.
   */
  Evento(int date, vector<string> events);

  /**
   * @brief Constructor de evento con una sola descripcion 
   * @param date la fecha en la que sucedio el acontecimiento.
   * @param event la descripcion del evento que se crea.
   */
  Evento(int date, string event);

  Evento();

  /**
   * @brief constructor de copia que crea un evento igual a otro dado
   * @param e el evento que se copia en el nuevo Evento creado.
   */
  Evento(const Evento& e);

  /**
   * @brief devuelve las descripciones de acontecimientos del Evento
   * @return conjunto de descripciones de acontecimientos .
   */
  vector<string> getEvents();

  /**
   * @param devuelve la fecha de los acontecimientos del evento.
   * @return la fecha que caracteriza el evento.
   */
  int getDate();

  /**
   * @brief añade varias descripciones a un evento ya creado
   * @param events los eventos que se quieren añadir
   */
  void addEvents(vector<string> events);

  /**
   * @brief añade una sola descripcion a un Evento
   * @param event la descripcion a añadir.
   */
  void addSingleEvent(string event);

  //operadores

  /**
   * @brief operador de comparacion menor: si la fecha de un evento es menos que la de e
   * devuelve true.
   * @param e el evento con el que se compara.
   * @return true si la fecha de this es menor que la de e.
   *         False en otro caso.
   */
   bool operator<(const Evento& e);

  /**
   * @brief operador de comparacion mayor que.
   * @param e el evento con el que se compara.
   * @return true si la fecha de this es mayor que la de e.
   *         False en otro caso.
   */
  bool operator>(const Evento& e);

  /**
   * @brief operador de comparacion. Devuelve true si dos eventos contienen la misma fecha y
   * las mismas descripciones de acontecimientos.
   * @param e  el operador con el que se compara.
   * @return True si las fehas y descripciones de this y e son iguales.
   *          False en otro caso.
   */
  bool operator==(const Evento& e) const;

  /**
   * @brief operador de comparacion. Comprueba  si dos eventos son diferentes.
   * @param e el evento con el que se compara.
   * @return True si las fechas po descripciones de this y e difieren.
   *         False en caso de que sean iguales.
   */
  bool operator!=(const Evento& e) const;

  /**
   * @brief operador de asignacion. Pone en this el contenido del evento e.
   * @param e evento a copiar.
   * @return referencia al evento en el que se han copiado los datos de e.
   */
  Evento& operator=(const Evento& e);

  /**
   * @brief operador de salida. Gestiona  la salida por o de un evento.
   * @param o referencia la salida por la que sale e.
   * @param e el evento que se imprimira por o.
   * @return referencia a la salida empleada.
   */
  friend ostream& operator<<(ostream& o, Evento& e);

  /**
   * @brief operador de entrada, carga un evento desde i.
   * @param i el canal por el que entra el evento.
   * @param referencia al evento que cargara los datos introducidos por e.
   * @return referencia a la entrada usada.
   */
  friend istream& operator>>(istream& i, Evento& e);
};

#endif
