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

int n, m;
const int mn = 1e5 + 5;
vi adj[mn];

int main() {
  setIO();
  cin >> n >> m;
  for (int i = 0; i < m; i++) { 
    int a, b;
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }

  queue<int> q;
  vector<bool> vis(n);
  vi dist(n + 1);
  vi par(n + 1);

  q.push(1);
  vis[1] = true;
  par[1] = -1;
  while (!q.empty()) {
    int i = q.front(); q.pop();
    for (int j : adj[i]) {
      if (vis[j]) continue;
      vis[j] = true;
      q.push(j);
      dist[j] = dist[i] + 1;
      par[j] = i;
    }
  }
  if (vis[n]) {
    vi path;
    for (int v = n; v != -1; v = par[v]) {
      path.pb(v);
    }
    reverse(path.begin(),path.end());

    cout << path.size() << endl;
    for (int i = 0; i < path.size(); i++) {
      cout << path[i];
      if (i != path.size() - 1)
        cout << " ";
    }
    cout << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }

}

