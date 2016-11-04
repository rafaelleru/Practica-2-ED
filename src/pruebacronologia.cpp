#include "../include/Cronologia.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){

  if (argc!=2){
      cout<<"Dime el nombre del fichero con la cronologia"<<endl;
      return 0;
   }

  ifstream f (argv[1]);
  if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
  }

  //    cout << aux;
   
    Cronologia mi_cronologia;//(argv[1]);

    f>>mi_cronologia; //Cargamos en memoria, en el traductor.

   int anio;

   while(anio != -1){
   cout<<"Dime un año a consultar: [-1 para terminar]";
   cin >> anio;
   
   vector<string> eventos = mi_cronologia.getDateEvents(anio);
   
   //  Escribimos 
   cout << anio << ":";
   for (int i=0;i<eventos.size(); ++i)
     cout<<eventos[i]<<';';
   cout<<endl;
   }
   

}
