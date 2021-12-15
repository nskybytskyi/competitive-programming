#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0),cin.tie(0);

  int n, k;
  cin >> n >> k;
  k *= 2;

  cout << 5ll * max(2, ((2 * n + k - 1) / k)) << "\n";

  return 0;
}
