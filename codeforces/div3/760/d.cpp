/* 
  Author: Skybytskyi.Nikita
  Time:   2021-12-14 16:35:04  
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0),cin.tie(0);

  int t; cin >> t; while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto& ai : a) {
      cin >> ai;
    }

    sort(a.begin(), a.end());

    int score = 0;
    int m = n - 2 * k;
    for (int i = 0; i < m; ++i) {
      score += a[i];
    }
    for (int i = m; i < m + k; ++i) {
      score += a[i] / a[i + k];
    }
    cout << score << "\n";
  }

  return 0;
}

