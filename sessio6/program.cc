#include <iostream>
#include <list>
using namespace std;

struct Pair{
  int a;
  int b;
};

void llegir_llista_pair(list<Pair>& l, Pair marca){
  Pair p;
  list<Pair>::iterator it = l.begin();
  cin >> p.a >> p.b; 
  while ((p.a != marca.a) and (p.b != marca.b)) {
    l.insert(it, p);
    cin >> p.a >> p.b;
  }
}

void escriure_llista_pair(const list<Pair>& l) {
  if (not l.empty()) {
    list<Pair>::const_iterator it;
    cout << "[Primero] ";
    for (it = l.begin(); it != l.end(); ++it){
      cout << (*it).a << " " << (*it).b << endl; // si la lista no es de enteros
    }                     // quedara mejor si hacemos endl para cada elemento
    cout << "[Ultimo]";
  } 
  cout << endl;
}

void busqueda (const list<Pair>& l, int n){
  list<Pair>::const_iterator it;
  int amount = 0;
  int suma = 0;
  for (it = l.begin(); it != l.end(); ++it){
    if ((*it).a == n){
      ++amount; 
      suma += (*it).b;
    }
  }
      cout << amount << ' ' << suma << endl; 

}

int main(){
  list<Pair> l;
  list<Pair>::iterator it;
  Pair marca;
  marca.a = 0;
  marca.b = 0;
  llegir_llista_pair(l,marca);
  int n;
  cin >> n;
  cout << n << ' ';
  busqueda(l,n);
}
