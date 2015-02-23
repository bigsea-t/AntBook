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

const int MAX_N = 100000;
int N , S, a[MAX_N], sum[MAX_N+1];

int main(){
  cin >> N >> S;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  int sum,s,t,ans;
  s = t = sum = 0;
  ans = N;
  while (1) {
    while (t<N && sum < S) {
      sum += a[t++];
    }
    if(sum < S) break;
    ans = min(ans,t-s);
    sum -= a[s++];
  }

  cout << ans << endl;

  return 0;
}

