#include <iostream>
#include <vector>
using namespace std;

bool par_sum(int k, vector <int> v, int sum = 0){
  if(v.empty()) return k == sum;

  int lst = v.back();
  v.pop_back();

  if(par_sum(k,v,sum+lst)) return true;

  if(par_sum(k,v,sum)) return true;

  return false;
}

int main()
{
  int n,k;
  vector <int> v;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int ele;
    cin >> ele;
    v.push_back(ele);
  }

  cin >> k;

  if(par_sum(k,v)) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}

