#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Partit{
    int local;
    int visit;
};

typedef vector < vector<Partit> > Matrix;
typedef vector < vector<int> > Matriu;

Matriu calculator(const Matrix &cal, int n){
    Matriu result(n,vector<int>(4,0));
    
    //numeració dels equips
    for (int i = 0; i < n; ++i){
        result[i][0] = i + 1;
    }
    
    //càlcul dels punts i gols de cada equip
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if (i != j){
                if (cal[i][j].local == cal[i][j].visit){
                    ++result[i][1];
                    ++result[j][1];
                }
                else if (cal[i][j].local > cal[i][j].visit){
                    result[i][1] += 3;
                }
                else result[j][1] +=3;
		
            result[i][2] += cal[i][j].local;
            result[j][2] += cal[i][j].visit;
            result[i][3] += cal[i][j].visit;
            result[j][3] += cal[i][j].local;
            }
        }
    }
    return result;
}

//lectura dels resultats
void llegeix(Matrix &entrada,int n){
     for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin >> entrada[i][j].local >> entrada[i][j].visit;
        }
    }
}

//escriptura de la classificació
void escriu (const Matriu &result, int n){
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < 4; ++j){
            if (j == 0) cout << result[i][j];
            else cout << ' ' << result[i][j];
        }
        cout << endl;
    }
}

//ordenació de la classificació
bool ordena(const vector<int> &a, const vector<int> &b){
    if (a[1] != b[1]) return a[1] > b[1];
    else if ((a[2]-a[3]) != (b[2]-b[3])) return (a[2]-a[3]) > (b[2]-b[3]);
    else return a[0] < b[0];
}

int main(){
    int n;
    cin >> n;
    Matrix cal(n,vector<Partit>(n));
    llegeix(cal,n);
    Matriu result = calculator(cal,n);
    sort(result.begin(),result.end(),ordena);
    escriu(result,n);
}

