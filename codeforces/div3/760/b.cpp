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

    vector<string> vs(n - 2);
    for (auto& s : vs) {
      cin >> s;
    }

    bool skip = false;
    string ans = vs[0];
    for (int i = 1; i < n - 2; ++i) {
      if (vs[i - 1][1] == vs[i][0]) {
        ans += vs[i][1];
      } else {
        assert(!skip);
        skip = true;
        ans += vs[i];
      }
    }
    if (!skip) {
      ans += "a";
    }
    cout << ans << "\n";
  }

  return 0;
}

