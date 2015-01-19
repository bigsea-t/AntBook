/*
 *
 * Copyright(c) 2015 Taikai Takeda <297.1951@gmail.com> All rights reserved.
 *
 */
#include <iostream>
#include <queue>
using namespace std;

int N,L,P, A[1000000], B[1000000];

int main(){
  cin >> N >> L >> P;



  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  for (int i = 0; i < N; i++) {
    cin >> B[i];
  }

  priority_queue <int> pq;


  int gass = P;
  int pos = 0;
  int st_passed = 0;
  int ans = -1;
  while(pos < L){
    pos += gass;
    gass = 0;

    while (A[st_passed] <= pos && st_passed < N) {
      pq.push(B[st_passed]);
      st_passed++;
    }

    if(pq.empty()){
      ans = -1;
      break;
    }

    gass += pq.top();
    pq.pop();
    ans++;
  }

  cout << ans << endl;

  return 0;
}

