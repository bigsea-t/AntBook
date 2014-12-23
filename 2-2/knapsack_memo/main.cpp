/*
 *
 * Copyright(c) 2014 Taikai Takeda <297.1951@gmail.com> All rights reserved.
 *
 */
#include <iostream>

using namespace std;

const int MAX_W = 10000;
const int MAX_N = 100;
int N;
int W;
int w[MAX_N];
int v[MAX_N];

int memo[MAX_N+1][MAX_W+1];

// >=i, w = j
int rec(int i, int j){
  if(memo[i][j] != -1) return memo[i][j];
  if(i >= N || v[i]>j) return 0;
  else{
    return max(rec(i+1,j-w[i]) + v[i],rec(i+1,j));
  }
}

int main()
{
  memset(memo,-1,sizeof(memo));
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> w[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }
  cin >> W;

  cout << rec(0,W) << endl;
  return 0;
}

