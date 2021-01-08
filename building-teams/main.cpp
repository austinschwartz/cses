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

int m, n;
const int mn = 1e5 + 5;

vi adj[mn];
bool vis[mn];
int col[mn];
bool bad;

void dfs(int u = 1, int pc=0) {
  vis[u] = true;
  col[u] = pc;
  for (int v : adj[u]) {
    if (vis[v]) {
      if (col[v] == pc) {
        bad = 1;
      }
    }
    else {
      dfs(v, !pc);
    }
  }
}

int main() {
  setIO();
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  for (int i = 1; !bad && i <= n; i++)  {
    if (!vis[i]) {
      dfs(i);
    }
  }
  if (bad) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  for (int i = 1; i < n; i++)
    cout << col[i] + 1 << " ";
  cout << col[n] + 1 << endl;
}

