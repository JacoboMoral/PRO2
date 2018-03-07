/**
 * @mainpage Pràctica de Pro2:  Gestió de llibres i cites.
 
En aquest programa es gestiona un conjunt de textos amb autor i títol, llibres, i també cites tretes d'aquests llibres. S'utilitzen les classes <em>Cjt_textos</em>, 
<em>Text</em>, <em>Cjt_cites</em> y <em>Cita</em>.

*/

/** @file main.cc
    @brief Programa principal de la pràctica de Pro2.
*/

#ifndef NO_DIAGRAM
#include <sstream>
#include <iostream>
#endif
#include "Cjt_textos.hh"     
#include "Text.hh"               //Redundant, serveix pel diagrama de classes


using namespace std;

int main(){
    string linia, op, seg, sublinia;
    getline(cin,linia);
    Cjt_textos llibre;
    while (linia != "sortir"){
        istringstream iss(linia);
        iss >> op;
        cout << linia << endl;
        if (op == "afegir"){
            iss >> seg;
            if (seg == "text"){
                Text txt;
                llibre.afegir_text(txt,linia);
            }
            else if (seg == "cita"){
            }
        }
        else if(op == "triar"){
            llibre.triar_text(linia);
        }
        else if(op == "eliminar"){
            iss >> seg;
            if(seg == "text"){
          llibre.eliminar_text();
            }
            else if(seg == "cita"){
            }
        }
        else if(op == "substitueix"){
            iss >> op;
            iss >> seg;
            iss >> seg;
            llibre.substitueix_paraula_triat(op,seg);
        }
        else if(op == "textos"){
            llibre.mostrar_textos_autor(linia);
        }
        else if(op == "tots"){
            iss >> seg;
            if(seg == "autors"){
                llibre.tots_autors();
                    
            }
            else if (seg == "textos"){
                llibre.tots_textos();
            }
        }
        else if(op == "info"){
            iss >> seg;
            if (seg == "?"){
                llibre.info();
            }
            else if (seg == "cita"){
            }
        }
        else if(op == "autor"){
        }
        else if(op == "contingut"){
            string tot = "tot";
            llibre.mostrar_contingut(tot,tot); //if x = -1 && y = -1, mostrar contingut = tot l'inverval de frases
        }
        else if(op == "frases"){
            string x,y;
            iss >> x;
            iss >> y;
            llibre.mostrar_contingut(x,y);
        }
        else if(op == "nombre"){
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
    
        do{
    	    getline(cin,linia);
    	}while (linia.empty());
    	cout << endl;
    }
}
