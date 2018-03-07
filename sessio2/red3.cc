#include "vectorIOEstudiant.hh"

void redondear_vector(vector <Estudiant> &v){
  int n = v.size();
  for (int i = 0; i < n; ++i){
  if (v[i].te_nota())
  v[i].modificar_nota(((int) (10. * (v[i].consultar_nota() + 0.05))) / 10.0);
}
}

int main(){
  int n;
  cin >> n;
  vector <Estudiant> v(n);
  leer_vector(v);
  redondear_vector(v);
  escribir_vector(v);
}