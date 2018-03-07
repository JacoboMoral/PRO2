#ifndef Text_hh
#define Text_hh


/** @file Text.hh
    @brief Especificació de la classe Text
*/


#ifndef NO_DIAGRAM
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <list>
#endif
using namespace std;
/** @class Text
    @brief Representa el contingut d'un text.
    Es guardarà tot el contingut de cada text que s'afegeixi, en frases.
 */


class Text
{
private:
	vector<string> contingut;
    
public:

    //constructores
    
    /** @brief Creadora per defecte. S'executa automàticament en declarar un text.
     
        \Pre <em>cert</em>
        \Post El resultat és text sense inicialitzar 
    */  
    Text();

    
    
    //modificadores
    
    /** @brief Substitueix una paraula per una altra en el text.
     
    	\pre <em>cert</em>
        \post Substitueix en el contingut del paràmetre implícit totes les aparicions de la paraula "original" per
        la paraula "nova" 
    */
    int substituir_paraula(string original, string nova);
    
    
    //lectura i escriptura
    
    /** @brief Llegueix un text.
     
        \pre Hi ha preparat al canal estàndard d'entrada un text que consta d'unes linies de contingut.
        \post El paràmetre implícit passa a ser el text
    */
    void llegir_contingut();
    
    //consultores
    
   
	//void escriure_contingut();
	
	void escriure_contingut(int x, int y);
    
    vector<string> consultar_frases() const;
    

    /** @brief Mostra el nombre de frases del contingut de l’´últim text triat.
   
    \pre S'ha triat un text anteriorment 
    \post El resultat és el nombre de frases del contingut del paràmetre implícit
    */
    int nombre_frases() const;
  
  
    /** @brief Mostra el nombre de paraules del contingut de l'últim text triat.
   
    \pre S'ha triat un text anteriorment 
    \post El resultat és el nombre de paraules del contingut del paràmetre implícit
    */
    int nombre_paraules() const;


    /** @brief Mostra totes les paraules del contingut del text ordenades decreixentment per freqüència.
   
    \pre S'ha triat un text anteriorment 
    \post Mostra pel canal estàndard de sortida la taula de freqüències
    */
    void escriu_taula_freq();
  

  /** @brief Mostra les frases del contingut de l’últim text triat que compleixen l’expressió
   
  \pre S'ha triat un text anteriorment 
  \post Es mostren les frases de l'últim text triat que compleix l'expressió del paràmetre 
  */
    void frases_expressio_text();



    /** @brief Mostra les frases on hi apareix la seqüència de paraules.
   
        \pre S'ha triat un text anteriorment 
        \post Es mostren les frases de l'últim text triat on hi apareixen les paraules del paràmetre en aquell mateix ordre,
         sense tenir en compte els signes de puntuació
    */
     void frases_paraules_consecutives_text(string &expressio);
    
    
    // destructora
    
    /** @brief Destructora per defecte.
   
        \pre <em>cert</em>
        \post Esborra els objectes automàticament en sortir d'un àmbit de visibilitat
    */ 
  ~Text();

};


#endif
