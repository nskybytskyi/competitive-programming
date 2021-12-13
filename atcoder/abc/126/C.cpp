#include <bits/stdc++.h>
using namespace std;

// tags: math

int main() {
  ios::sync_with_stdio(0),cin.tie(0);
  cout << fixed << setprecision(10);

  int n, k;
  cin >> n >> k;

  long double sum = 0;
  for (int i = 0; i < n; ++i) {
    int score = i + 1;
    long double probability = 1. / n;
    while (score < k) {
      score *= 2;
      probability /= 2.;
    }
    sum += probability;
  }
  cout << sum << "\n";

  return 0;
}
