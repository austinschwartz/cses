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

int main() {
  setIO();
  ll n;
  cin >> n;
  vector<ll> nums;
  nums.pb(n);
  while (n != 1) {
    if (n % 2 == 0) {
      n = (n / 2);
    } else {
      n = n * 3 + 1;
    }
    nums.pb(n);
  }
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i];
    if (i != nums.size() - 1)
      cout << " ";
  }
  cout << endl;
}

