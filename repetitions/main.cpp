#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

void setIO(string name = "") { // name is nonempty for USACO file I/O
  ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
  // alternatively, cin.tie(0)->sync_with_stdio(0);
  if (sz(name)) {
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    freopen((name+".out").c_str(), "w", stdout);
  }
}

string s;

int main() {
  setIO();
  cin >> s;
  int maxx = 1;
  int cur = 1;
  char prev = s[0];
  int n = sz(s);
  for (int i = 1; i < n; i++) {
    if (s[i] == prev) {
      cur += 1;
      maxx = max(maxx, cur); 
    } else {
      cur = 1;
      prev = s[i];
    }
  }
  cout << maxx << endl;
}

