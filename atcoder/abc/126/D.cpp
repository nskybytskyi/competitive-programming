#include <bits/stdc++.h>
using namespace std;

// tags: tree, dfs

int main() {
  ios::sync_with_stdio(0),cin.tie(0);

  int n;
  cin >> n;

  vector<vector<pair<int, int>>> g(n);
  for (int e = 1; e < n; ++e) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }

  vector<int> color(n, -1);
  function<void(int, int)> dfs = [&] (int v, int c) -> void {
    color[v] = c;
    for (auto [u, w] : g[v]) {
      if (color[u] == -1) {
        if (w & 1) {
          dfs(u, !c);
        } else {
          dfs(u, c);
        }
      }
    }
  };
  dfs(0, 0);

  for (int v = 0; v < n; ++v) {
    cout << color[v] << "\n";
  }

  return 0;
}
