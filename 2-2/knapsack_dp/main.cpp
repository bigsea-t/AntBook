/*
 *
 * Copyright(c) 2014 Taikai Takeda <297.1951@gmail.com> All rights reserved.
 *
 */
#include <iostream>

using namespace std;

const int MAX_W = 10000;
const int MAX_N = 100;
int N;
int W;
int w[MAX_N];
int v[MAX_N];

int dp[MAX_N+1][MAX_W+1];



int main()
{
  memset(dp,-1,sizeof(dp));
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> w[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }
  cin >> W;

  for (int i = 0; i < MAX_W; i++) {
    dp[N][MAX_W] = 0;
  }

  for (int i = N-1; i >=0 ; i--) {
    for (int j = 0; j < MAX_W; j++) {
      if(j>=w[i])
        dp[i][j] = v[i]+dp[i+1][j-w[i]];
      else
        dp[i][j] = dp[i+1][j];
    }
  }

  cout << dp[0][W] << endl;

  return 0;
}

