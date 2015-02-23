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
  // sum[i] = summation forall a[0,i)
  // *** sum[0] = 0***
  for (int i = 0; i <= N; i++) {
    sum[i+1]= sum[i] + a[i];
  }

  if(sum[N] < S){
    cout << "0" << endl;
    return 0;
  }

  int ans = N;
  for (int s = 1;  S <= sum[N] - sum[s]; s++) {
    int t = lower_bound(sum + s,sum+N, S + sum[s]) - sum;
    ans = min(ans,t-s);
  }

  cout << ans << endl;

  return 0;
}

