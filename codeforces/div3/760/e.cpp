/* 
  Author: Skybytskyi.Nikita
  Time:   2021-12-14 16:35:04  
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0),cin.tie(0);

  int t; cin >> t; while (t--) {
    int n;
    cin >> n;

    vector<int> b(n);
    for (auto& bi : b) {
      cin >> bi;
    }

    vector<int64_t> c(n);
    for (int i = 0; i < n; ++i) {
      c[i] = b[i] - b[(i - 1 + n) % n];
    }

    int rem = ((c[0] % n) + n) % n;
    bool all = true;
    for (auto ci : c) {
      if (rem != ((ci % n) + n) % n) {
        all = false;
        break;
      }
    }

    if (all) {
      int64_t s = accumulate(b.begin(), b.end(), int64_t(0));
      int64_t den = ((n + 1) * 1ll * n) / 2;
      bool all = true;
      if (s % den) {
        all = false;
      } else {
        s /= den;
      }
      vector<int64_t> a(n);
      for (int i = 0; i < n && all; ++i) {
        if ((s - c[i]) % n) {
          all = false;
        } else {
          a[i] = (s - c[i]) / n;
        }
      }
      
      if (all &&  // sanity?
          accumulate(a.begin(), a.end(), int64_t(0)) == s &&
          0 < *min_element(a.begin(), a.end()) && 
          *max_element(a.begin(), a.end()) <= 1'000'000'000) {
        cout << "YES\n";
        for (auto ai : a) {
          cout << ai << " ";
        }
        cout << "\n";
      } else {
        cout << "NO\n";
      }
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}

