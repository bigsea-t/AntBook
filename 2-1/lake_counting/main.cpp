#include <iostream>
#include <vector>
using namespace std;

void unite(vector<vector <char> > &v, int i, int j){
  int M,N;
  N = v.size();
  M = v[0].size();

  int is[8] = {-1,0,1,-1,1,-1,0,1};
  int js[8] = {-1,-1,-1,0,0,1,1,1};

  if(i<0 || j < 0 || i >= N || i >= M)
    return;
  else if(v[i][j] == 'W') {
    v[i][j] = '.';
    for (int k = 0; k < 8; k++) {
      unite(v, i+is[k], j+js[k]);
    }
  }
  return;
}

int main()
{
  int N, M, count = 0;
  cin >> N >> M;


  vector <vector <char> > v(N, vector<char>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> v[i][j];
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if(v[i][j]=='W'){
        unite(v,i,j);
        count++;
      }
    }
  }
  cout << count << endl;
  return 0;
}
