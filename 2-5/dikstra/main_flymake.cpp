/*
 *
 * Copyright(c) 2015 Taikai Takeda <297.1951@gmail.com> All rights reserved.
 *
 */
#include <iostream>
using namespace std;

const int V_MAX = 10000, E_MAX = 1000000, INF = 1000000000;

int V,E;
int d[V_MAX];
int cost[V_MAX][V_MAX];
bool used[V_MAX];


void dikstra(int s){

}


int main(){
  cin >> V >> E;
  fill((int*)cost,(int*)cost + V_MAX * V,INF);
  for (int e_i = 0; e_i < E; e_i++) {
    int f,t,c;
    cin >> f >> t >> c;
    cost[f][t] = c;
    // reverse edge
    cost[t][f] = c;
  }

  dikstra(0);
  cout << d[6] << endl;

  return 0;
}

