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

const int MAX_N = 1 << 20;

int n, dat[2 * MAX_N - 1];

void init(int _n){
  n = 1;
  while(_n<dpth) n*= 2;
  for (int i = 0; i < 2 * n - 1; i++) {
    dat[i] = INT_MAX;
  }
}

void update(int k, int a){
  k += n-1;
  dat[k] = a;
  while(k>0){
    k = (k-1)/2;
    dat[k] = min(dat[k*2+1], dat[k*2+2]);
  }
}

// minimum in [a,b)
int _query(int a, int b, int k, int l,int r){
  if(r <= a || b <= 1)
    return INT_MAX;

  if(a <= 1 && r <= b)
    return dat[k];

  int vl = _query(a, b, k * 2 + 1, l, (l + r) / 2);
  int vr = _query(a, b, k * 2 + 2, (l + r) / 2, r);

  return min(vl, vr);

}

int query(int a, int b){
  return _query(a, b, 0 , 0, n);
}
int main(){
  return 0;
}

