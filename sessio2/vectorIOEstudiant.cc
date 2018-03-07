#include "vectorIOEstudiant.hh"

void leer_vector(vector <Estudiant> &v){
  int n = v.size();
  Estudiant est;
  for (int i = 0; i < n; ++i){
    est.llegir();
    v[i] = est;
  }
}

void escribir_vector(const vector <Estudiant> &v){
  int n = v.size();
  Estudiant est;
  for (int i = 0; i < n; ++i){
    est = v[i];
    est.escriure();
  }
}
