#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

// tags: dfs, dsu

int main() {
  ios::sync_with_stdio(0),cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<tuple<int, int, int>> xyz(m);
  for (auto& [x, y, z] : xyz) {
    cin >> x >> y >> z;
    --x, --y;
  }

  dsu cc(n);
  for (auto [x, y, _] : xyz) {
    cc.merge(x, y);
  }
  cout << cc.groups().size() << "\n";

  return 0;
}
