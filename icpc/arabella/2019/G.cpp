#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0),cin.tie(0);
  cout << fixed << setprecision(10);

  int n;
  cin >> n;

  long double expectation = 0.;
  for (int i = 0; i < n; ++i) {
    expectation += i * 1. * (i + 1) * 1. / n; 
  }
  cout << expectation << "\n";

  return 0;
}
