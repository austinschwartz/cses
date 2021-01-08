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

const int ma = 10e5 + 5;

int n, m;
vi adj[ma][2];
bool vis[ma];

void dfs(int v, int x) {
  vis[v] = true;
  for (int u : adj[v][x]) {
    if (!vis[u]) {
      dfs(u, x);
    }
  }
}

int main() {
  setIO();
  cin >> n >> m;
  memset(vis, false, sizeof(vis));
  int a, b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    a--; b--;
    adj[a][0].pb(b);
    adj[b][1].pb(a);
  }
  dfs(0, 0);
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      cout << "NO" << endl;
      cout << 1 << " " << (i + 1) << endl;
      return 0;
    }
  }
  memset(vis, false, sizeof(vis));
  dfs(0, 1);
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      cout << "NO" << endl;
      cout << (i + 1) << " " << 1 << endl;
      return 0;
    }
  }
  cout << "YES" << endl;

}

