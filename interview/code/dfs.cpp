#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 110;
int g[N][N];
bool st[N][N];
int n, m;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

void dfs(int x, int y, int &sz) {
  st[x][y] = true;
  sz++;

  for (int i = 0; i < 4; i++) {
    int a = x + dx[i], b = y + dy[i];
    if (a < 0 || a >= n || b < 0 || b >= m || st[a][b] || g[a][b] == 0)
      continue;
    dfs(a, b, sz);
  }
}

int main() {
  cin >> n >> m;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> g[i][j];

  int res = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (g[i][j] == 1 && !st[i][j]) {
        int sz = 0;
        res++;
        dfs(i, j, sz);
        cout << sz << " ";
      }

  cout << endl << res << endl;

  return 0;
}
