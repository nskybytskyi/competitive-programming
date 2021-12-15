/* 
  Author: Skybytskyi.Nikita
  Time:   2021-12-14 16:35:04  
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0),cin.tie(0);

  int n, m, q;
  cin >> n >> m >> q;

  vector<int> a(n), b(m);
  for (auto& ai : a) {
    cin >> ai;
  }
  for (auto& bj : b) {
    cin >> bj;
  }

  vector<pair<int, int>> offline(q);
  for (int i = 0; i < q; ++i) {
    int k;
    cin >> k;
    offline[i] = {k, i}; 
  }
  sort(offline.begin(), offline.end());

  vector<pair<int, bool>> c;
  for (int i = 0; i < n; ++i) {
    c.emplace_back(a[i], true);
  }
  for (int j = 0; j < m; ++j) {
    c.emplace_back(b[j], false);
  }
  sort(c.begin(), c.end());

  vector<int> ps = {0};
  for (auto [ci, _] : c) {
    ps.push_back(ps.back() + ci);
  }

  vector<int> L(n + m), R(n + m), cnt(n + m);
  for (int i = 0; i < n + m; ++i) {
    L[i] = R[i] = i;
    cnt[i] = c[i].second;
  }

  auto sum = [&] (int i) -> int64_t {
    return ps[i + 1] - ps[i + 1 - cnt[i]];
  };

  auto merge = [&] (int i) -> void {
    cnt[R[i + 1]] += cnt[i];
    cnt[i] = 0;
    L[R[i + 1]] = L[i];
    R[L[i]] = R[i + 1];
  };

  map<int, vector<int>> merges;
  for (int i = 1; i < n + m; ++i) {
    merges[c[i].first - c[i - 1].first].push_back(i - 1);
  }

  int64_t init = 0;
  for (int i = 0; i < n + m; ++i) {
    init += sum(i);
  }

  vector<int64_t> ans(q);
  for (auto [k, i] : offline) {
    while (!merges.empty() && merges.begin()->first <= k) {
      for (int i : merges.begin()->second) {
        init -= sum(i) + sum(R[i + 1]);
        merge(i);
        init += sum(R[i + 1]);
      }
      merges.erase(merges.begin());
    }
    ans[i] = init;
  }

  for (auto ansi : ans) {
    cout << ansi << "\n";
  }

  return 0;
}

