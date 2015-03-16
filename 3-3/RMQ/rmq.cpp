/*
 *
 * Copyright(c) 2015 Taikai Takeda <297.1951@gmail.com> All rights reserved.
 *
 */
#include <iostream>
#include <math.h>
using namespace std;
class RMQ
{
  static const int MAX_N = 1 << 20;
  int n, dat[2 * MAX_N - 1];

  void init(int _n){
    n = 1;
    while(n<_n) n*= 2;
    for (int i = 0; i < 2 * n - 1; i++) {
      dat[i] = INT_MAX;
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


public:
  RMQ(int n){
    init(n);
  };
  void show(){
    int k = n - 1;
    while(k < n * 2)
      cout << k << " ";
    cout << endl;
  }

  void update(int k, int a){
    k += n-1;
    dat[k] = a;
    while(k>0){
      k = (k-1)/2;
      dat[k] = min(dat[k*2+1], dat[k*2+2]);
    }
  }

  int query(int a, int b){
    return _query(a, b, 0 , 0, n);
  }
};


int main(){
  RMQ r(8);
  r.update(1,1);

  return 0;
}
