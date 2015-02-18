/*
 *
 * Copyright(c) 2015 Taikai Takeda <297.1951@gmail.com> All rights reserved.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

const int MAX_V=1000;
vector <int> g[MAX_V];
int N;
typedef vector<int>::iterator itr;
int color[MAX_V];// 1 or 2

/* wrong algorythm
int solve(){
  color[0]=1;

  // 1->2, 2->1 :  % 2 + 1
  for (int v_num = 1; v_num < N; v_num++) {
    for (int e_num = 0; e_num < (int)g[v_num].size(); e_num++) {
      if(color[e_num]==0)
        color[e_num] = color[v_num] % 2 + 1;
      else
        if(color[e_num] == color[v_num]){
          return 0;
        }
    }
  }

  return 1;
}
*/
// c = -1 or 1, initial value 0;
bool dfs(int c, int v){
  color[v]=c;

  for (int e_num = 0; e_num < (int)g[v].size(); e_num++) {
    if(color[g[v][e_num]]==c)
      return false;
    else if(color[g[v][e_num]]==0)
      return dfs(-c,g[v][e_num]);
  }
  return true;
}



int main(){
  cin >> N;
  for (int i = 0; i < N; i++) {
    int edges;
    cin >> edges;
    for (int j = 0; j < edges; j++) {
      int edge_input;
      cin >> edge_input;
      g[i].push_back(edge_input);
    }
  }

  bool result = dfs(1,0);
  if(result)
    cout << "OK" << endl;
  else
    cout << "NG" << endl;
  return 0;
}
