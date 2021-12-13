#include <bits/stdc++.h>
using namespace std;

// tags: constructive, math

int main() {
  ios::sync_with_stdio(0),cin.tie(0);

  int m, k;
  cin >> m >> k;

  if (((1 << m) - 1) < k || (m == 1 && k == 1)) {
    cout << -1 << "\n";
  } else if (m == 1 && k == 0) {
    cout << "0 0 1 1\n";
  } else {
    for (int i = 0; i < (1 << m); ++i) {
      if (i != k) {
        cout << i << " ";
      }
    }
    cout << k << " ";
    for (int i = (1 << m) - 1; i >= 0; --i) {
      if (i != k) {
        cout << i << " ";
      }
    }
    cout << k << "\n";
  }

  return 0;
}
