/*
 *
 * Copyright(c) 2015 Taikai Takeda <297.1951@gmail.com> All rights reserved.
 *
 */
#include <iostream>
using namespace std;

int N,k;
const int MAX_N = 1000000;
int a[MAX_N];


int solve(){

  int up,lw,md;
  up = N - 1;
  lw = 0;

  if(a[up]<k)
    return N;

  while(up > lw){
    md = (up+lw)/2;
    if(a[md] < k)
      lw = md + 1;
    else if(a[md] >= k)
      up = md;
  }
  return up;
}

int main(){
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  cin >> k;

  cout << (solve()) << endl;
  return 0;
}
