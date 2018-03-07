#include "Estudiant.hh"
#include <vector>

int maxim(int a, int b){
  if (a > b) return a;
  else return b;
}

void simplificar_vector(const vector <Estudiant> &v){
  int n = v.size();
  vector <Estudiant> vsimp;
  int i = 0;
  double max;
  while (i < n){
    int dni = v[i].consultar_DNI();
    while ((dni == v[i].consultar_DNI()) and (i < n)){
      if (v[i].te_nota()) max = maxim(v[i].consultar_nota(),max);
      ++i;
    }
    Estudiant est(v[i].consultar_DNI());
    est.afegir_nota(max);
    vsimp.push_back(est);
    max = 0;
  }
  for (int i=0;i<n;++i){
    v[i].escriure();
    cout << endl;
  }
}

int main(){
  int n;
  cin >> n;
  vector <Estudiant> v(n);
  Estudiant est;
  for (int i=0;i<n;++i){
    v[i].llegir();
  }
  simplificar_vector(v);
}