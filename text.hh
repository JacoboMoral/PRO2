#include <string>

class Cjt_Textos{
private:
  
public:
  //constructores
  
  Text();
  /* Pre: cert */
  /* Post: el resultat es un text */
  
  
  
  
  //modificadores
  
  afegir_text(string titol, string autor, string contingut);
  /* Pre: els strings titol, autor i contingut no son buits */
  /* Post: el titol del parametre implicit passa a ser "titol", el autor del parametre
   * implicit passa a ser "autor, el contingut del parametre implicit passa a ser "contingut" */
  
  
  substituir_paraula(string original, string nova);
  /* Pre: els parametres original i nova no han de ser buits */
  /* Post: substitueix totes les aparicions del parametre original per el parametre nova
   * al contingut de l'ultim parametre implicit */
  
  
  //consultores
  
  triar_text(string paraules);
  /* Pre: el string paraules no ha d'estar buits i el conjunt d'aquestes no pot pertanyer
   * a dos textos diferents */
  /*Post: el resultat es el titol del text que conte les paraules */
  
  
  mostrar_textos_autor(string autor);
  /* Pre: autor apareix al parametre implicit i el text no es buit */
  /* Post: el resultat son els titols del parametre implicit */
  
  
  mostrar_autors();
  /* Pre: cert */
  /* Post: el resultat es el conjunt d'autors i titols del parametre implicit */
  
  
  mostrar_textos();
  /* Pre: cert */
  /* Post: el resultat es el conjunt de continguts del parametre implicit */
  
  
  mostrar_info();
  /* Pre: ha d'haver-se afegit un text anteriorment */
  /* Post: el resultat es el autor, titol, nombre de frases, nombre de paraules
   * i cites associades del parametre implicit */
      
  
  mostrar_autor();
  /* Pre: Existeix un autor al parametre implicit */
  /* Post: el resultat es l'autor de l'ultim parametre implicit triat */
  
  
  mostrar_contingut();
  /* Pre: s'ha triat  un text anteriorment */
  /* Post: el resultat es una llista enumerada de les frases que apareixen al contingut */+
  
  
  mostrar_frases_xy(int x, int y);
  /* Pre: s'ha triat un text anteriorment */
  /* Post : el resultat es una llista enumerada de les frases numero x hasta la numero y */
  
  
  nombre_frases();
  /* Pre: s'ha triat un text anteriorment */
  /* Post: el resultat es el nombre de frases del contingut del parametre implicit */
  
  
  nombre_paraules();
  /* Pre: s'ha triat un text anteriorment */
  /* Post: el resultat es el nombre de paraules del contingut del parametre implicit */
  
  
  taula_freq();
  /* Pre: s'ha triat un text anteriorment */
  /* Post: el resultat es la llista de frequencies de cada paraula, ordenada decreixentment
   * per frequencia del contingut del parametre implicit. En cas d'empat, s'ordena creixentment,
   * primer per llargaria i despres alfabeticament */
  
  
  frases(string expressio);
  /* Pre: s'ha triat un text anteriorment */
  /* Post: el resultat es el contingut de l'ultim text triat que compleixen l'expressio */
  
  
 
  

    
  //destructores
  
  eliminar_text();
  /* Pre: el contigut del parametre implicit no ha de ser buits */
  /* Post: elimina el contingut de l'ultim parametre implicit */
 
  
