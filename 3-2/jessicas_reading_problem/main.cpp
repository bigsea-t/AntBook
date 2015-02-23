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
#include <map>
using namespace std;

const int MAX_N = 1000000;
int N,a[MAX_N];

int main(){
  cin >> N;

  set<int> all;
  for (int i = 0; i < N; i++) {
    scanf("%d",&a[i]);
    all.insert(a[i]);
  }


  int s,t,sum,ans,all_vars,vars;
  s = t = sum = 0;
  ans = N;
  all_vars = all.size();
  vars = 0;
  map<int,int> counter;

  while (1) {
    while (vars < all_vars && t < N) {
      if(counter[a[t]]==0)
        vars++;
      counter[a[t]]++;
      t++;
    }
    if(vars < all_vars)
      break;
    ans = min(ans,t-s);
    if(--counter[a[s]]==0)
      vars--;
    s++;
  }

  cout << ans << endl;

  return 0;
}
