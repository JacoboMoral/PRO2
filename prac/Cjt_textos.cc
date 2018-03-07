#include "Cjt_textos.hh"
#include <sstream>
using namespace std;

  
  
Cjt_textos::Cjt_textos(){
    existeix_text_triat = 0;
}
  
Cjt_textos::~Cjt_textos(){
}


bool Cjt_textos::search(string palabra, string palabras){
    string op;
    istringstream iss(palabras);
    while (iss >> op){
    	if ((op[op.size()-1] == ':') or (op[op.size()-1] == '.') or (op[op.size()-1] == ',') or (op[op.size()-1] == '?') or (op[op.size()-1] == '!') or (op[op.size()-1] == ';')){
                op.erase(op.size()-1,1);
                if (op == palabra) return 1;
                
            }
            else {
                if (op == palabra) return 1;
            }
    }
    return 0;
}


bool Cjt_textos::search_txt(string palabra, const Text& txt){
	int n = txt.nombre_frases();
    vector<string> frases(n);
    string palabras;
    frases = txt.consultar_frases();
    for (int j = 0; j < frases.size(); ++j){
    	string op;
    	palabras = frases[j];
    	istringstream iss(palabras);
    	while (iss >> op){
    		if ((op[op.size()-1] == ':') or (op[op.size()-1] == '.') or (op[op.size()-1] == ',') or (op[op.size()-1] == '?') or (op[op.size()-1] == '!') or (op[op.size()-1] == ';')){
                op.erase(op.size()-1,1);
                if (op == palabra) return 1;
                
            }
            else {
                if (op == palabra) return 1;
            }
		}
    }
	return 0;
}
    

    
string Cjt_textos::llegir_autor(){
	string autor;
	getline(cin,autor);
	autor.erase(0,7);
	autor.erase(autor.size()-1,1);
	return autor;
}


string Cjt_textos::llegir_titol(string titol){
    titol.erase(0,13);
    titol.erase(titol.size()-1,1);
    return titol;
}


	
	
	
void Cjt_textos::afegir_text(Text &txt,string &linia){
	map <string,Text> titol_i_contingut;
    string titol = llegir_titol(linia);
    string autor = llegir_autor();
    txt.llegir_contingut();
    titol_i_contingut.insert(make_pair(titol,txt));
    map <string,map<string,Text> >::iterator it;
    map <string,Text>::iterator it3;
    it = text.find(autor);
    if (it == text.end()) text.insert(make_pair(autor,titol_i_contingut));
    else{
    	map<string,Text> t_i_c = it -> second;
    	it3 = titol_i_contingut.begin();
    	t_i_c.insert(make_pair(it3->first,it3->second));
     	text.erase(autor);
       	text.insert(make_pair(autor,titol_i_contingut));
    }
}
    
    
void Cjt_textos::triar_text(string paraules){
	string op;
    vector<string> v;
    paraules.erase(0,12);
    paraules.erase(paraules.size()-1,1);
    istringstream iss(paraules);
    while(iss >> op){
        v.push_back(op);
    }

    bool valid = 1;
    map <string,map<string,Text> >::iterator it;
	map <string,Text>::iterator it2;
    vector<int> apsaut(text.size(),0);
    int j = 0;
    int count = 0;

    for (it = text.begin(); it != text.end(); ++it){
        for (it2 = it->second.begin(); it2!=it->second.end(); ++it2) {
            for (int i = 0; i < v.size(); ++i){
                if (search(v[i],it2->first) or search_txt(v[i],it2->second) or search(v[i],it->first)){
                    ++apsaut[j];

               }
               if (apsaut[j] == v.size()){
                    ++count;
                    if(count == 1){
                       it_triat_autor = it;
                       it_triat_titol_i_contingut = it2;
                       existeix_text_triat = 1;
                    }
                    else valid = 0;
                }
            }
            ++j;
        }
    }
        if (valid == 0){
        	existeix_text_triat = 0;
            cout << "error" << endl;
        }
}
    
void Cjt_textos::eliminar_text(){   
 	map<string,map<string,Text> >::iterator it;
   	map<string,Text>::iterator it_triat_titol_i_contingut;
   	it = text.find(autor_triat);
   	if(it->second.size() > 1){
   		it->second.erase(titol_triat);
	}
	else text.erase(it->first);
}

    
void Cjt_textos::mostrar_textos_autor(string &autor){
	autor.erase(0,14);
	autor.erase(autor.size()-3,3);
	map<string,map<string,Text> >::iterator it;
	map<string,Text>::const_iterator it2;
	it = text.find(autor);
	if (it != text.end()){
		for (it2 = it->second.begin(); it2!=it->second.end(); ++it2) {
			cout << '"' << it2->first << '"' << endl;
		}
	}
}




void Cjt_textos::info(){
	if (not existeix_text_triat) cout << "error"<< endl;
	else {
		Text txt = it_triat_titol_i_contingut -> second;
		int nf = txt.nombre_frases();
    	int np = txt.nombre_paraules();
		cout << "nombre de frases: " << nf << endl;
		cout << "nombre de paraules: " << np << endl;
	}
}



void Cjt_textos::tots_autors(){
    int numparaulestotal;
    int numfrasestotal;
    map<string,map<string,Text> >::const_iterator it;
	map<string,Text>::const_iterator it2;
	for (it = text.begin(); it != text.end(); ++it){
	    numfrasestotal = 0;
        numparaulestotal = 0;
        Text txt;
        for (it2 = it->second.begin(); it2!=it->second.end(); ++it2){
        	txt = it2->second;
            numfrasestotal = numfrasestotal + txt.nombre_frases();
            numparaulestotal = numparaulestotal + txt.nombre_paraules();
        }
        cout << it->first;
        cout << it->second.size() << " ";
        cout << numfrasestotal;
        cout << " ";
        cout << numparaulestotal;
        cout << endl;
    }
}


void Cjt_textos::tots_textos(){
	map<string,map<string,Text> >::const_iterator it;
	map<string,Text>::const_iterator it2;
	for (it = text.begin(); it != text.end(); ++it){
        for (it2 = it->second.begin(); it2!=it->second.end(); ++it2) {
        	//autor-text-texto?
        	//o autor texto
        	//  autor texto?
        	// si un autor tiene mas de uno
  	        cout << it->first << " " << '"' << it2->first << '"' << endl;  
            }
        }
}

void Cjt_textos::substitueix_paraula_triat(string &original, string &nova){
	nova.erase(0,1);
	nova.erase(nova.size()-1,1);
	original.erase(0,1);
    original.erase(original.size()-1,1);
    int aparicions = (it_triat_titol_i_contingut->second).substituir_paraula(original,nova);
    substituir_paraula_taula_freq(original,nova,aparicions);
	
}

/*void Cjt_textos::recursiva(line){
	Text txt = it_triat_titol_i_contingut;
	int i = 0;
	bool b = txt.expressio(line,i);
	***************************
}
*/
void Cjt_textos::mostrar_autor(){
    cout << it_triat_autor->first << endl;
}

string Cjt_textos::consultar_autor_triat(){
	return autor_triat;
}

string Cjt_textos::consultar_titol_triat(){
	return titol_triat;
}


void Cjt_textos::mostrar_contingut(string &ics, string &i_grega){
    int x,y;
    if ((ics == "tot") and (i_grega == "tot")){
        x = -1;
        y = -1;
    }
    else {
        x = atoi(ics.c_str());
        y = atoi(i_grega.c_str());
    }
    Text txt = it_triat_titol_i_contingut -> second;
    txt.escriure_contingut(x,y);
}
    
    
void Cjt_textos::frases_paraules_consecutives_conjunt(string &paraules){
	Text txt = it_triat_titol_i_contingut -> second;
	txt.frases_paraules_consecutives_text(paraules);
}

void Cjt_textos::mostra_error(){
	cout << "error" << endl;
}

vector<string> Cjt_textos::consultar_frases_cita(int x , int y){
	vector<string> t;
	vector<string> v = it_triat_titol_i_contingut->second.consultar_frases();
	if (y < v.size()){
		int i = 0;
		while (y >= i){
			if ( i >= x and i<= y) t.push_back(v[i]);
			++i;
		}
	}
    else{
        cout << "error" << endl;
    }
    return t;
}


void Cjt_textos::fer_taula_freq(){
    string op;
    pair<string,int> paraula;
    Text txt = it_triat_titol_i_contingut->second;
    vector<string> contingut = txt.consultar_frases();
	for(int i = 0; i < contingut.size(); ++i){
    	istringstream iss(contingut[i]);
    	while(iss >> op){
    		list<pair<string,int> >::iterator it = taulafreq.begin();
    		if(op[op.size()-1] == ',' or op[op.size()-1] == '.' or op[op.size()-1] == '?'
			or op[op.size()-1] == ';' or op[op.size()-1] == ':' or op[op.size()-1] == '!'){
				op.erase(op.size()-1,1);
			}
    		if (taulafreq.empty()){
    			paraula = make_pair(op , 1);
    			taulafreq.insert(it,paraula);
    		}
    		else{
    			bool trobat = false;
    			while(not trobat and it != taulafreq.end()){
    				if(it->first == op){
    					trobat = true;
					}
					else ++it;
    			}
    			if(trobat) it->second = it->second + 1;
				else{
					paraula = make_pair(op,1);
					taulafreq.insert(it,paraula);
				}
			}
		}
    	
	}
}


void Cjt_textos::substituir_paraula_taula_freq(string &original, string &nova, int aparicions){
	bool trobat_nova = 0;//se puede mejorar eficiencia
    list<pair<string,int> >::iterator it;
    for(it = taulafreq.begin(); it != taulafreq.end(); ++it){
		if (it->first == nova){
			it->second += aparicions;
            trobat_nova = 1;
		} 
        if (it->first == original) taulafreq.erase(it);
	}
    if (!trobat_nova) taulafreq.insert(it,make_pair(nova,aparicions));
}



void Cjt_textos::mostrar_taula_freq(){
    list<pair<string,int> >::iterator it;
    for(it = taulafreq.begin(); it != taulafreq.end(); ++it){
        cout << it->first << ' ' << it -> second << endl;
    }
}
