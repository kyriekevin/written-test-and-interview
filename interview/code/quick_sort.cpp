#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int g[N];

void quick_sort(int s, int e) {
  if (s >= e)
    return;

  int x = g[s + e >> 1], l = s - 1, r = e + 1;
  while (l < r) {
    while (g[++l] < x)
      ;
    while (g[--r] > x)
      ;
    if (l < r)
      swap(g[l], g[r]);
  }

  quick_sort(s, l);
  quick_sort(l + 1, e);
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> g[i];

  quick_sort(0, n - 1);

  for (int i = 0; i < n; i++)
    cout << g[i] << " ";

  return 0;
}
