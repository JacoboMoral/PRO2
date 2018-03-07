/**
 * @mainpage Ejemplo de diseño modular:  Gestión de una lavadora.
 
En este ejemplo se construye un programa modular que ofrece un menú de opciones para gestionar una lavadora. Se introducen las clases <em>Lavadora</em>, <em>Cubeta</em> y <em>Prenda</em>.
*/

/** @file pro2_s8.cc
    @brief Programa principal para el ejercicio <em>Gestión de una lavadora</em>.
*/

// para que el diagrama modular quede bien se han escrito includes redundantes;
// en los ficheros .hh de la documentación de las clases ocurre lo mismo.
#include "Prenda.hh"
#include "Lavadora.hh"
#include "Cubeta.hh"
#include <string>


/** @brief Programa principal para el ejercicio <em>Gestión de una lavadora</em>.
*/
int main (){
  Lavadora lavadora;
  Cubeta cubeta;
  int codigo;
  while (cin >> codigo){
    
    if (codigo == -1){
      string color;
      int max;
      cin >> max >> color;
      if (color == "true") lavadora.inicializar(max,1);
      else lavadora.inicializar(max,0);
    }
    
    if (codigo == -2){
      int peso;
      cin >> peso;
      lavadora.anadir_prenda(peso);
    }
    
    if (codigo == -3){
      string color;
      int peso;
      cin >> peso >> color;
      if (color == "true") cubeta.anadir_prenda(peso);
      else cubeta.anadir_prenda(peso);
    }
  }
  
}
