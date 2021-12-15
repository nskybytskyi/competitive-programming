#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0),cin.tie(0);

  int n, p;
  cin >> n >> p;
  --p;

  vector<int> a(n - 1);
  for (auto& ai : a) {
    cin >> ai;
  }

  vector<int> b(n - 1);
  for (auto& bi : b) {
    cin >> bi;
    --bi;
  }

  vector<int> index(n);
  iota(index.begin(), index.end(), 0);

  vector<vector<bool>> dp(n, vector<bool>(n));
  dp[0][p] = true;

  for (int i = 0; i < n - 1; ++i) {
    const int k = index.size();
    a[i] %= k;
    for (int j = 0; j < k; ++j) {
      dp[i + 1][index[j]] = dp[i][index[(j + a[i]) % k]] \
                          | dp[i][index[(j - a[i] + k) % k]];
    }
    index.erase(find(index.begin(), index.end(), b[i]));
  }

  cout << (dp[n - 1][index[0]] ? "Yes" : "No") << "\n";

  return 0;
}
