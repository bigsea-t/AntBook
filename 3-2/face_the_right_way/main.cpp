/*
 *
 * Copyright(c) 2015 Taikai Takeda <297.1951@gmail.com> All rights reserved.
 *
 */
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 5000;
int N, dir[MAX_N], f[MAX_N]; // 0:F 1:B

// return m
// or -1 when no solution
int calc(int k){
  memset(f,0,sizeof(f));
  int m = 0;
  int sum = 0;
  for (int i = 0; i + k <= N; i++) {
    if((dir[i]+sum)%2 != 0){
      m++;
      f[i] = 1;
    }
    sum += f[i];
    if(i - k + 1 >=0){
      sum -= f[i - k + 1];
    }
  }

  for (int i = N - k + 1; i < N; i++) {
    if((dir[i] + sum) % 2 != 0)
      return -1;
    if(i - k + 1 >= 0){
      sum -= f[i -k + 1];
    }
  }

  return m;
}

void solve(){
  int K = 1, M = N;
  for (int k = 1; k <= N; k++) {
    int m = calc(k);
    if (m >= 0 && M > m){
      M = m;
      K = k;
    }

  }

  printf("%d %d\n", K, M);
}

int main(){
  scanf("%d",&N);
  char c;
  scanf("%c",&c);
  for (int i = 0; i < N; i++) {
    scanf("%c",&c);
    dir[i] = (c == 'F') ? 0 : 1;
  }

  solve();
  return 0;
}
