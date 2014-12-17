/*
 *
 * Copyright(c) 2014 Taikai Takeda <297.1951@gmail.com> All rights reserved.
 *
 */
#include <iostream>
#include <vector>
using namespace std;


int main(){
  int N, R;
  vector<int> x;
  cin >> N >> R;
  for (int i = 0; i < N; i++) {
    int in;
    cin >> in;
    x.push_back(in);
  }


  int i = 0, ans = 0;
  while (i < N) {
    int left = x[i++];
    while(x[i] - left <= R && N > i)
      i++;
    // now i is dot's index
    ans++;
    left = x [i-1];
    while(x[i] - left <= R && N > i)
      i++;
  }

  cout << ans << endl;

  return 0;
}
