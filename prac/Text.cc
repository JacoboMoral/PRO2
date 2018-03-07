#include "Text.hh"
using namespace std;


Text::Text(){
}


Text::~Text(){
}




int Text::substituir_paraula(string original, string nova) {
    int cont = 0;
    for(int i = 0; i < contingut.size(); ++i){
        int size = original.size();
        int pos = contingut[i].find(original);
        while(pos != -1){
            char c = contingut[i][pos + size];
            if (c == ' ') contingut[i].replace(pos, original.size(), nova);
            cout << nova << endl;
            pos = contingut[i].find(original, pos + nova.size());
		    ++cont;
	    }
    }
    return cont;
}







void Text::llegir_contingut(){
    string n;
    cin >> n;
    bool next = 0;
    bool first = 1;
    int i = 0;
    while(n != "****"){
        if (first){
            contingut.push_back(n);
            first = 0;
        }
        else if (next){
            contingut.push_back(n);
            next = 0;
        }
        else if ((n[n.size()-1] == '.') or (n[n.size()-1] == '?') or (n[n.size()-1] == '!')){
            next = 1;
            contingut[i] += " " + n;
            ++i;
        }
        else {
            contingut[i] += " " + n;
        }
        cin >> n;
    }
}

vector<string>Text::consultar_frases() const{
	return contingut;
}


int Text::nombre_frases() const{
     return contingut.size();
}
 

int Text::nombre_paraules() const{
	string op;
	int cont = 0;
	for (int i = 0; i < contingut.size(); ++i){
		istringstream iss (contingut[i]);
		while (iss >> op) ++cont;
	}
    return cont;
}
 
void Text::escriu_taula_freq(){
    
}

void Text::escriure_contingut(int x, int y){
    if ((x == -1) and (y == -1)){
        for (int i = 0; i < contingut.size(); ++i){
            cout << i+1 << " " << contingut[i] << endl;
        }
	}
    else {
	    if ((x >= 0) and (x <= y) and (y < contingut.size())){
		    for (int i = x; i <= y; ++i){
                cout << i << " " << contingut[i-1] << endl;
		    }
	    }
	    else cout << "error" << endl;
    }
}


void Text::frases_paraules_consecutives_text(string &expressio){
    for(int i = 0; i < contingut.size(); ++i){
        string paraules = contingut[i];
    	string op,ap;
    	int aux = 0;
    	string par;
    	
    	int cont = 0;
    	string express = expressio;
    	istringstream ss (express);
    	istringstream oo (paraules);
    	while (ss >> op){
    	    ++cont;
    	}
    	while (oo >> par){
    	    ++aux;
    	}
    	cout << cont << endl;
    	istringstream iss (paraules);
    	int count = 0;
    	while ((iss >> op) and (count < cont)){
    	    if ((op[op.size()-1] == ':') or (op[op.size()-1] == '.') or (op[op.size()-1] == ',') or (op[op.size()-1] == '?') or (op[op.size()-1] == '!') or (op[op.size()-1] == ';')){
                op.erase(op.size()-1,1); 
                
    	    }
            
    	    istringstream ass (expressio);
    	    ass >> ap;
    	    cout << op << "    ";
    	    cout << ap << endl;
    	    --aux;
    	    while ((op == ap) and (aux >= 0)){
                ++count;
                --aux;
                cout << count << endl;
    	        ass >> ap;
    	        iss >> op;

    	        if ((op[op.size()-1] == ':') or (op[op.size()-1] == '.') or (op[op.size()-1] == ',') or (op[op.size()-1] == '?') or (op[op.size()-1] == '!') or (op[op.size()-1] == ';')){
                    op.erase(op.size()-1,1);
    	        }
    	        cout << op << "    ";
    	        cout << ap << endl;
    	        if ((aux == 0) and (op == par)) ++count;
    	        if (count == cont) cout << i+1 << ' ' << paraules << endl;
    	    }
    	}
    }
}

