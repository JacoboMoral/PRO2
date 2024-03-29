#ifndef MATRIZ_IO_INT	// per evitar errors de compilacio
#define MATRIZ_IO_INT	// quan aquest fitxer s'inclou molts cops	


#include <iostream>
#include <vector>

using namespace std;

typedef vector <vector<int> > Matriz;

void leerMatriz_int(Matriz& m);
/* Pre:  hi ha preparats al canal estandar d'entrada uns enters N 
   i M mes gran que 0 i N*M enters qualssevol */
/* Post: m te N files i cada fila M elements que son successivament 
   els N*M enters qualssevol del canal estandar d'entrada */

void escribirMatriz_int(const Matriz& m) ;
/* Pre: cert */
/* Post: s'han escrit tots els elements de la matriu */

#endif
