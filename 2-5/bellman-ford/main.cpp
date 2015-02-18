/*
 *
 * Copyright(c) 2015 Taikai Takeda <297.1951@gmail.com> All rights reserved.
 *
 */
#include <iostream>
using namespace std;

const int V_MAX = 10000, E_MAX = 1000000, INF = 1000000000;

struct edge{
  int from, to, cost;
};

int V,E;

int d[V_MAX];
edge e[E_MAX];


void bellman_ford(int s){
  for (int v_i = 0; v_i < V; v_i++) {
    d[v_i] = INF;
  }
  d[s] = 0;

  while(true){
    bool update = false;
    for (int e_i = 0; e_i < E; e_i++) {
      int from = e[e_i].from;
      int cost = e[e_i].cost;
      int to   = e[e_i].to;

      if(d[from] != INF && d[from] + cost < d[to]){
        update = true;
        d[to] = d[from] + cost;
      }
    }
    if(update) break;
  }
}

int main(){
  cin >> V >> E;
  E = E * 2;
  for (int e_i = 0; e_i < E; e_i++) {
    int f,t,c;
    cin >> f >> t >> c;
    e[e_i].from = f;
    e[e_i].to   = t;
    e[e_i].cost = c;
    // reverse edge
    e_i++;
    e[e_i].from = t;
    e[e_i].to   = f;
    e[e_i].cost = c;
  }

  bellman_ford(0);

  cout << d[6] << endl;

  return 0;
}

