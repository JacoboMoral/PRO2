#include <iostream>
#include <string>
#include <map>
using namespace std;




int main(){
    map<string, int> lista;
    char codi;
    string paraula;
    while (cin >> codi){
      cin >> paraula;
      lista[paraula];  
      if (codi == 'a'){
	++lista[paraula];
      }
      if (codi == 'f'){
	cout << lista[paraula] << endl;
      }
    }
}