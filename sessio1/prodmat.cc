#include <iostream>
#include <vector>
using namespace std;


typedef vector <vector<int> > matrix;

matrix suma (const matrix &m1, const matrix &m2){
    int f = m1.size();
    int c = m2[0].size();
    matrix s(f,vector<int>(c));
    for (int i=0;i<f;++i){
        for (int j=0;j<c;++j){
            for (int k=0;k<c;++k){
                s[i][j] = m1[i][k]*m2[k][j];
            }
        }
    }
}

int main(){
    int f,c;
    cin >> f >> c;
    matrix m1(f,vector<int>(c));
    for (int i=0;i<f;++i){
        for (int j=0;j<c;++j){
            cin >> m1[i][j];
        }
    }
    int f1,c1;
    cin >> f1 >> c1;
    matrix m2(f1,vector<int>(c1));
    for (int i=0;i<f1;++i){
        for (int j=0;j<c1;++j){
            cin >> m2[i][j];
        }
    }
    for (int i=0;i<f;++i){
        for (int j=0;j<c1;++j){
            cout << suma(m1,m2)[i][j];
        }
    }

}
