#include <bits/stdc++.h>
using namespace std;

// tags: implementation

int main() {
  ios::sync_with_stdio(0),cin.tie(0);

  string s;
  cin >> s;

  int first = stoi(s.substr(0, 2)),
      second = stoi(s.substr(2, 2));

  if (0 < first && first <= 12) {
    if (0 < second && second <= 12) {
      cout << "AMBIGUOUS\n";
    } else {
      cout << "MMYY\n";
    }
  } else {
    if (0 < second && second <= 12) {
      cout << "YYMM\n";
    } else {
      cout << "NA\n";
    }
  }

  return 0;
}
