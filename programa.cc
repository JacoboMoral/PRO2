#include <sstream>
#include <string>
#include <iostream>
using namespace std;


int main(){
  string linia, op, seg;
  getline(cin,linia);
  istringstream iss(linia);
  iss >> op;
  while (op != "sortir"){
    cout << linia << endl;
    if (op == "afegir"){
      iss >> seg;
      if (seg == "text"){
	string titulo
	cin >> titulo
	string autor
	string contingut
	cin >> autor
	cin >> contingut
	afegir_text(titulo, autor, contingut) 
      }
      else if (seg == "cita"){
      }
    }
    else if(op == "triar"){
      
    }
    else if(op == "eliminar"){
      iss >> seg;
      if(seg == "text"){
      }
      else if(seg == "cita"){
      }
    }
    else if(op == "substitueix"){
    }
    else if(op == "textos"){
    }
    else if(op == "tots"){
      iss >> seg;
      if(seg == "autors"){
      }
      else if (seg == "textos"){
      }
    }
    else if(op == "info"){
      iss >> seg;
      if (seg == "?"){
      }
      else if (seg == "cita"){
      }
    }
    else if(op == "autor"){
    }
    else if(op == "contingut"){
    }
    else if(op == "frases"){
    }
    else if(op == "nombre"){
      iss >> seg;
      iss >> seg;
      if (seg == "frases"){
      }
      else if(seg == "paraules"){
      }
    }
    else if(op == "taula"){
    }
    else if(op == "cites"){
      iss >> seg;
      if (seg == "autor"){
      }
      else if (seg == "?"){
      }
    }
    else if(op == "totes"){
    }
    else cout << "error" << endl;
    
    getline(cin, linia);
    iss.str(linia);
    iss >> op;
  }
}
