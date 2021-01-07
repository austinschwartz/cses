#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n, x;
vector<ll> a;

int main() { 
  cin >> n;
  a.resize(n);
  cin >> x;
  map<ll, int> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (m.count(x - a[i]) && m[x - a[i]] != i) {
      cout << m[x - a[i]] + 1 << " " << i + 1 << endl;
      return 0;
    }
    m[a[i]] = i;
  }
  cout << "IMPOSSIBLE" << endl;
}
