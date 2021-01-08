/*
ID: me80
TASK: test
LANG: C++14                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
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

void setIO(string name = "") { // name is nonempty for USACO file I/O
  ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
  // alternatively, cin.tie(0)->sync_with_stdio(0);
  if (sz(name)) {
    freopen((name+".in").c_str(), "r", stdin); // see Input & Output
    freopen((name+".out").c_str(), "w", stdout);
  }
}

const int mn = 1e5 + 5;
vi adj[mn];
bool vis[mn];

int n, m, rep[mn];

void dfs(int u) {
  vis[u] = true;
  for (int v : adj[u]) {
    if (!vis[v]) {
      dfs(v);
    }
  }
}

int components() {
  int ret = 0;
  memset(vis, false, sizeof(vis));
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      rep[ret] = i;
      ret += 1;
      dfs(i);
    }
  }
  return ret;
}

int main() {
  setIO();
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  int ans = components();
  cout << (ans - 1) << endl;
  for (int i = 1; i <= (ans - 1); i++) {
    cout << rep[i] << " " << rep[i - 1] << endl;
  }
}

