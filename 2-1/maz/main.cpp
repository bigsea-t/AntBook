#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> P;

int main()
{
  int M,N; // M: col N: row
  const int INF = 2^20;
  cin >> M >> N;
  vector <vector <char> > map(N,vector<char>(M));
  vector <vector <int> > dst(N,vector<int>(M,INF));
  
  int sx,sy,gx,gy;//start gaol

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> map[i][j];
      if (map[i][j] == 'S') {
        sx = i;
        sy = j;
      } else if (map[i][j] == 'G'){
        gx = i;
        gy = j;
      }
    }
  }

  int dx[4] = {-1,1,-1,1}, dy[4] = {-1,-1,1,1};


  queue<P> q;
  q.push(P(sx,sy));

  while (q.empty()) {
    P pos = q.front(); q.pop();
    int x,y;
    x = pos.first;
    y = pos.second;
    if (x == gx && y == gy)
      break;

    // 4 dist

    for (int i = 0; i < 4; i++) {
      if(x == gx && y == gy)
        break;

      int nx = x + dx[i];
      int ny = x + dy[i];

      if(map[nx][ny] != '#' && dst[nx][ny] == INF
          && nx >= 0 && nx < M && ny >= 0 && ny < M ){
        dst[nx][ny] = dst[x][y] + 1;
        q.push(P(nx,ny));
      }
    }
  }

  cout << dst[gx][gy] << endl;

  return 0;
}
