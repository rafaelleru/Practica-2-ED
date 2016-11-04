#ifndef CRONOLOGIA
#define CRONOLOGIA
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <list>
#include "../include/Evento.h"

using namespace std;

/**
 * @mainpage Cronologia
 * @section Introduccion
 * la biblioteca cronologia desarrollada para la practica 2 de Estructuras de datos 
 * consiste en un conjunto de clases y metodos que permiten manejar hechos historicos
 * ahorrando al programador de aplicacion el tener que hacerlo por el mismo
 */

class Cronologia{
 private:

  /**
   * @page repConjunto Representacion del TDA Cronologia
   * @section invConjunto Invariante de la representacion
   * El invariante es que un Evento no puede ser menos que 5000
   * @section fcAbstraccion Funcion de abstracion
   * Un objeto valido del TDA cronologia presentea un valor de tipo:
   * Evento1, Evento2, Evento3.
   * Estando dichos elementos ordenados en orden creciente de fecha.
   */
  list<Evento> cronologia;
  //  pair<int, vector<string>> parseLine(string line);
 public:
  
  /**
   * @brief crea una nueva cronologia a partir de el archivo identificado en file
   * @param file el nombre del archivo a cargar en cronologia
   */
  Cronologia(char* file);

  /**
   * @brief constructor de una cronologia a partir de un vector de eventos
   * @param events los eventos que contendra la cronologia
   */
  Cronologia(vector<Evento> events);

  /**
   * @brief constructor por defecto
   */
  Cronologia(){};

  /**
   * @brief constructor de copia
   * @param c cronologia de la que se desean copiar los datos para la nueva cronologia
   */
  Cronologia(Cronologia& c);
  
  /**
   * @param destructor por defecto
   */
  ~Cronologia();

  /**
   * @brief devuelve un vector con la descripcion de los eventos que tuvieron lugar
   * en una fecha determinada
   * @param date la fecha de la que se desea conocer los eventos
   * @return Devuelve un vector de strings que contiene los acontecimientos ocurridos en date.
   */
  vector<string> getDateEvents(int date);

  /**
   * @brief añade una nueva descripcion de evento al TDA evento con clave date
   * @param date la fecha(clave) del vento al que se desea añadir la descripcion
   * @param event la descripcion a añadir en el evento
   */
  void addEventToDate(int date, string event);

  /**
   * @brief añade un multiples descripciones de eventos al TDA Evento con clave date
   * @param date la fecha (clave) del evento al que añadir las descripciones
   * @param events vector con las descripciones a añadir
   */
  void addMultipleEventsToDate(int date, vector<string> events);

  /**
   * @brief añade un evento nuevo a la cronologia
   * @param e el evento a añadir
   */
  void addEvent(Evento e);

  /**
   * @brief devuelve el numero de eventos que contiene la cronologia
   * @return Devuelve el numero de eventos almacenados.
   */
  size_t size();
  
  //------------------------------------------------------------------------------
  //                              OPERADORES
  //------------------------------------------------------------------------------

  /**
   * @brief asigna a *this la el contenido de la cronologia c
   * @param c cronologia que se desea asignar en this.
   * @return referencia a la cronologia en la que se ha copiado c.
   */
  Cronologia& operator=(const Cronologia& c);

  /**
   * @brief suma dos cronologias, las concatena
   * @param c la cronologia a concatenar en this
   * @return referencia a la cronologia en la que se ha concatenado c.
   */
  Cronologia& operator+(Cronologia& c);

  /**
   * @brief elimina una cronologia de otra
   * @param c la subcronologia a eliminar de la primera
   * @return Referencia a la cronologia de la que se ha eliminado c.
   */
  Cronologia& operator-(Cronologia& c);

  /**
   * @brief comprueba si dos cronologias son iguales
   * @param c la cronologia con la que se compara
   * @return True si c es igual a this,
   *         False en otro caso.
   */
  bool operator==(const Cronologia& c);

  /**
   * @brief comprueba si dos cronologias son iguales diferentes
   * @param c la cronologia con la que se compara
   * @return devuelve True si c es distinto de this,
   *         False en otro caso.
   */
  bool operator!=(Cronologia& c);

  /**
   * @brief sobrecarga del operador de salida, realiza la salida por o
   * de la cronologia c.
   * @param o referencia a la salida por la que se imprimira la cronologia
   * @param c referencia a la cronologia a imprimira
   * @return referencia a la salida usada.
   */
  friend ostream& operator<<(ostream& o, Cronologia& c);

  /**
   * @brief sobrecarga del operador de entrada, introduce en c el contenido de i
   * @param i referencia a la entrada por la que se leera c.
   * @param c referencia a la cronologia en la que se almacenan los datos de i
   * @return referencia a la entrada usada.
   */
  friend istream& operator>>(istream& i, Cronologia& c);

  //methods for use like a STL TDA (No estan implementados)
  void resize(int newSize);
  void erase();
  void push_back(const Evento& event);
  
};
#endif
