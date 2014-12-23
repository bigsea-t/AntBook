/*
 *
 * Copyright(c) 2014 Taikai Takeda <297.1951@gmail.com> All rights reserved.
 *
 */
#include <iostream>
using namespace std;

const int MAX_N = 1000, MAX_M = 1000;
int N,M;

char s[MAX_N+1],t[MAX_M+1];

int dp[MAX_N+1][MAX_M+1];


int main(){
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> s[i];
  }

  for (int i = 0; i < M; i++) {
    cin >> t[i];
  }


  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if(s[i]==t[j])
        dp[i+1][j+1] = dp[i][j] + 1;
      else
        dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
    }
  }

  cout << dp[N][M] << endl;





  return 0;
}
