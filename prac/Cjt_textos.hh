#ifndef Cjt_textos_hh
#define Cjt_textos_hh

/** @file Cjt_textos.hh
    @brief Especificació de la classe Cjt_textos
*/

#ifndef NO_DIAGRAM
#include <map>
#endif
#include "Text.hh"
using namespace std;
/** @class Cjt_textos
    @brief Representa un conjunt de textos.
    Es guardaran tots els textos afegits amb un titol, autor i el contingut.
 */

class Cjt_textos
{
  
private:
	bool existeix_text_triat; 
	map <string,map<string,Text> > text; //string = autor; map = titulo + contenido
	map<string,map<string,Text> >::iterator it_triat_autor; // apunta al map del autor del text triat
	map<string,Text>::iterator it_triat_titol_i_contingut;
    string autor_triat;
    string titol_triat;
	list <pair<string,int> >taulafreq;
	bool search(string palabra, string palabras);
	bool search_txt(string palabra, const Text& txt);
	
	
	
	string llegir_titol(string titol);
	//pre
	//post
	
	
	
	string llegir_autor();
	//pre
	//post
    
    
    Text llegir_textos();
    //pre
    //post
    
    
    
    void fer_taula_freq();

  
public:
    
    //Constructores

    /** @brief Creadora per defecte. S'executa automaticament en declarar un conjunt de textos.

        \pre <em>cert</em>
        \post El resultat és un conjunt de textos buit 
    */  
    Cjt_textos();
    
    
  
    //Modificadores
    
    void substituir_paraula_taula_freq(string &original, string &nova, int aparicions);

    void substitueix_paraula_triat(string &original, string &nova);

	void actualitzar_taula_freq();



    //Selectores
  
    /** @brief Tria un text.
     
        \pre El string paraules no ha d'estar buit i el conjunt d'aquestes no pot pertànyer
        a dos textos diferents 
        \post El iterador i s'actualitza amb la posició del text que s'ha triat
    */
    void triar_text(string paraules);



    //Consultores 
 
    /** @brief Mostra els textos d'un determinat autor.
     
        \pre <em>cert</em>
        \post Mostra una llista de titols corresponents al autor seleccionat com a paràmetre,
        si aquest es troba a un text del paràmetre implícit
    */
    void mostrar_textos_autor(string &autor);



    /** @brief Mostra tots els autors afegits, el nombre de textos de cadascun, el nombre de paraules i de frases del text.
     
        \pre <em>cert</em>
        \post Mostra una llista ordenada alfabèticament dels autors dels textos del paràmetre implícit,
        a més de del nombre de textos de cadascun, i del nombre de paraules i de frases del contingut dels
        textos
    */
    void tots_autors();
     
  	void mostrar_taula_freq();
  
  
    void info();

  
  

    /** @brief Mostra tots els textos afegits.
     
        \pre <em>cert</em> 
        \post El resultat és una llista ordenada dels autors i títols de tots els textos del paràmetre implícit,
        primer per autor i després per títol
    */
    void tots_textos();
  


    /** @brief Mostra informació de l'últim text triat.
   
        \pre Ha d'haver-se afegit un text anteriorment
        \post El resultat és l'autor, títol, nombre de frases, nombre de paraules i cites associades del paràmetre implícit
    */
   void mostrar_info();
 
 

    /** @brief Mostra l'autor de l'últim text triat.
   
        \pre Existeix un autor al paràmetre implícit 
        \post El resultat és l'autor de l'últim paràmetre implícit triat
    */
    void mostrar_autor();
  
  

    /** @brief Mostra el contingut de l'últim text triat.
   
        \pre S'ha triat un text anteriorment 
        \post El resultat és una llista enumerada de les frases que apareixen al contingut del parámetre implícit
    */
    void mostrar_contingut(string &ics, string &i_grega);
  


    /** @brief Mostra les frases entre la x-èsima i la y-èsima del contingut de l’últim text triat.
   
        \pre S'ha triat un text anteriorment
        \post El resultat és una llista enumerada de les frases número x fins la número y 
    */
    //void mostrar_frases_xy(int x,int y);
  
  	void frases_expressio_conjunt();
  	
  	void frases_paraules_consecutives_conjunt(string &paraules);
  	
  	string consultar_autor_triat();
  	//Pre
  	//Post
  	
  	string consultar_titol_triat();
  	//Pre
  	//Post
  	
  	vector<string> consultar_frases_cita(int x, int y);
  	//Pre
  	//Post
  	
  	
    /** @brief Elimina l'últim text triat.
   
        \pre El contigut del paràmetre implícit no ha de ser buit
        \post Elimina el contingut de l'últim paràmetre implícit que esta apuntat per it , i no hi ha cap text triat 
    */
    void eliminar_text();
  
  
    //Entrada i sortida
  
   
   
    /** @brief Afegeix un text.
     * 
        \pre El paràmetre implícit no conté cap text amb el mateix autor i títol 
        \post S'ha afegit el text txt al paràmetre implícit
    */
    void afegir_text(Text &txt,string &linia);
  
    
    //Destructora
  
    /** @brief Destructora per defecte.
   
        \pre <em>cert</em>
        \post Esborra els objectes automàticament en sortir d'un àmbit de visibilitat
    */ 
    ~Cjt_textos(); 

  
    //Error
    
    /** @brief Mostra error.
   
        \pre <em>cert</em> 
        \post Mostra pel canal estàndard de sortida l'error que s'ha produït
   
    */
    void mostra_error();
    
};

#endif
