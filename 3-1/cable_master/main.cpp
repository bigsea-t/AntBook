/*
 *
 * Copyright(c) 2015 Taikai Takeda <297.1951@gmail.com> All rights reserved.
 *
 */
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

const int L_MAX = 100000;
const int N_MAX = 10000;
int N,K;
double L[N_MAX];

bool is_valid(double l){
  int k_count = 0;
  for (int i = 0; i < N; i++) {
    k_count += floor(L[i]/l);
  }
  return k_count >= K;
}

int main(){
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> L[i];
  }

  double up,lw,md;
  up = L_MAX/K;
  lw = 0;

  while((up-lw)>0.01){
    md = (lw+up)/2;
    if(is_valid(md))
      lw=md;
    else
      up=md;
  }
  double ans;
  if(is_valid(up))
    ans = up;
  else
    ans = lw;

  //  cout << fixed << setprecision(2) << ans << endl;
  printf("%.2f\n",ans);
  return 0;
}
