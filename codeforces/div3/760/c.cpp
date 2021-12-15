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

    vector<int64_t> a(n);
    for (auto& ai : a) {
      cin >> ai;
    }

    int64_t d = 0;
    for (int i = 0; i < 2; ++i) {
      int64_t g = 0;
      for (int j = i; j < n; j += 2) {
        g = gcd(g, a[j]);
      }
      bool any = false;
      for (int j = 1 - i; j < n && !any; j += 2) {
        if (a[j] % g == 0) {
          any = true;
        }
      }
      if (!any) {
        d = g;
      }
    }
    cout << d << "\n";
  }

  return 0;
}

