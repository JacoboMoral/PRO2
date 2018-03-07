node_pila* copia_node_pila_it(node_pila* m){
    if (m == NULL) return NULL;
    else{
        node_pila* n;
        n = new node_pila;
        n->info = m->info;
        n->seguent = NULL;
        m = m->seguent;
        node_pila* aux;
        aux = n;
        node_pila* p;
        p = n;
        while(m != NULL){
            n = new node_pila;
            aux->seguent = n;
            n->info = m->info;
            aux = aux->seguent; //també aux = n;
            n->seguent = NULL;
            m = m->seguent;

        }
        return p;
    }
}














Pila& operator=(const Pila& original) {
  if (this != &original) {
    altura = original.altura;
    esborra_node_pila(primer_node);
    primer_node = copia_node_pila_it(original.primer_node);
  }
  return *this;
}
