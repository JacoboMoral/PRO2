#include <iostream>
#include <vector>
using namespace std;

void maxmin (const vector<int> &v, int &max, int &min){
  int n = v.size();
  max = v[0];
  min = max;
  int i = 1;
  while (i < n){
    if (max < v[i]) max = v[i];
    if (min > v[i]) min = v[i];
    ++i;
  }
}

int main(){
  int n,max,min;
  cin >> n;
  vector <int> v(n);
  for (int i = 0; i < n; ++i){
    cin >> v[i];
  }
  maxmin(v,max,min);
  cout << max << ' ' << min << endl;
}
