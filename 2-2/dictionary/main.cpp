#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector <char> s;
vector <char> t;

char judge(int acm = 0){
  char s_f = *(s.begin()+acm);
  char s_b = *(s.end()-1-acm);
  if(s_f == s_b)
    return judge(++acm);
  else{
    if(s_f>s_b){
      char ret = s.back();
      s.pop_back();
      return ret;
    }
    else{
      char ret = s.front();
      s.erase(s.begin());
      return ret;
    }
  }
}

int main()
{
  cin >> N;
  for (int i = 0; i < N; i++) {
    char tmp;
    cin >> tmp;
    s.push_back(tmp);
  }

  while(!s.empty()){
    char c = judge();
    t.push_back(c);
  }

  for (int i = 0; i < N; i++) {
    cout << t[i];
  }

  cout << endl;
  return 0;
}
