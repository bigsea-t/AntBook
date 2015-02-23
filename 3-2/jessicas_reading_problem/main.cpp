/*
 *
 * Copyright(c) 2015 Taikai Takeda <297.1951@gmail.com> All rights reserved.
 *
 */
#include <iostream>
#include <math.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int MAX_N = 1000000;
int N,a[MAX_N];

int main(){
  cin >> N;

  set<int> all;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    all.insert(a[i]);
  }


  int s,t,sum,ans;
  s = t = sum = 0;
  ans = N;

  // par .. [s,t)
  while (1) {
    set<int> par;
    while (!(par == all) && t < N) {
      par.insert(a[t++]);
    }
    if(!(par == all))
      break;
    ans = min(ans,t-s);
    s++;
  }

  cout << ans << endl;

  return 0;
}
