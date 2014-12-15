#include <iostream>
#include <vector>
using namespace std;

int n;
vector <int> s;
vector <int> t;
const int MAX_N = 100000;

pair<int,int> p[MAX_N];

int main()
{
  int ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    s.push_back(tmp);
  }
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    t.push_back(tmp);
  }

  for (int i = 0; i < n; i++) {
    p[i].first = t[i];
    p[i].second = t[i];
  }

  sort(p, p+n);
  int now = 0;
  for (int i = 0; i < n; i++) {
    if(p[i].first > now){
      now = p[i].first;
      ans++;
    }
  }


  cout << ans << endl;


  return 0;
}
