#include <iostream>
#include <string>
#include <set>
using namespace std;

void inserir_jugadors(set<string> &jugadors){
  string jugador;
  cin >> jugador;
  while (jugador != "."){
    jugadors.insert(jugador);
    cin >> jugador;
  }
}
int main(){
  set<string> jugadors;
  set<string> cap;
  set<string> nombre;
  set<string> totes;
  inserir_jugadors(jugadors);
  int n;
  cin >> n;
  cap = jugadors;
  while (n > 0){
    inserir_jugadors(aux);
    set<string>::iterator it = aux.begin();
    set<string>::iterator it2 = jugadors.begin();
      while(it != aux.end() ){
	while (it2 != jugadors.end() ) {
	  
	if (*it == *it2) cap.erase(it2)
	++it;
	}
      }
    --n;
  }
}











