/* 
  Author: Skybytskyi.Nikita
  Time:   2021-12-14 16:35:04  
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0),cin.tie(0);

  int t; cin >> t; while (t--) {
    vector<int64_t> b(7);
    for (auto& bi : b) {
      cin >> bi;
    }

    auto subset_sums = [&] (vector<int64_t> a) -> vector<int64_t> {
      int n = a.size();
      vector<int64_t> b;
      b.reserve((1 << n) - 1);
      for (int mask = 1; mask < (1 << n); ++mask) {
        int64_t sum = 0;
        for (int bit = 0; bit < n; ++bit) {
          if (mask & (1 << bit)) {
            sum += a[bit];
          }
        }
        b.push_back(sum);
      }
      sort(b.begin(), b.end());
      return b;
    };

    if (subset_sums(vector<int64_t>({b[0], b[1], b[2]})) == b) {
      cout << b[0] << " " << b[1] << " " << b[2] << "\n";
    } else {
      cout << b[0] << " " << b[1] << " " << b[3] << "\n";
    }
  }

  return 0;
}

