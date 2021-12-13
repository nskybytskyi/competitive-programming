#include <bits/stdc++.h>
using namespace std;

// tags: implementation

int main() {
  ios::sync_with_stdio(0),cin.tie(0);

  int n, k;
  cin >> n >> k;
  --k;

  string s;
  cin >> s;

  if (s[k] == 'A') {
    s[k] = 'a';
  } else if (s[k] == 'B') {
    s[k] = 'b';
  } else {  // s[k] == 'C'
    s[k] = 'c';
  }

  cout << s << "\n";

  return 0;
}
