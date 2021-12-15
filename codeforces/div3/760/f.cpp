/* 
  Author: Skybytskyi.Nikita
  Time:   2021-12-14 16:35:04  
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0),cin.tie(0);

  int64_t x, y;
  cin >> x >> y;
  bool any = x == y;

  const int n = 5;

  vector<string> s(n);
  while (x) {
    s[0] += '0' + (x & 1);
    x >>= 1;
  }
  
  s[1] = string(s[0].rbegin(), s[0].rend());
  
  s[3] = "1" + s[0];

  s[4] = string(s[3].rbegin(), s[3].rend());

  while (s[1].length() > 1 && s[1].back() == '0') {
    s[1].pop_back();
  }

  s[2] = string(s[1].rbegin(), s[1].rend());

  string t;
  while (y) {
    t += '0' + (y & 1);
    y >>= 1;
  }
  reverse(t.begin(), t.end());
  
  for (int l = 0; l < n; ++l) {
    //cerr << "s[" << l << "] = " << stoll(s[l], 0, 2) << "\n";
    int k = 61 - s[l].length();
    for (int i = 0; i < k && !any; ++i) {
      for (int j = 0; i + j < k && !any; ++j) {
        string r = string(i, '1') + s[l] + string(j, '1');
        //cerr << stoll(r, 0, 2) << "\n";
        any |= r == t;
      }
    }
  }
  cout << (any ? "YES" : "NO") << "\n";

  return 0;
}

