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
const int mn = 1005;
char grid[mn][mn];
bool vis[mn][mn];

void dfs(int i, int j) {
  vis[i][j] = true;
  for (int dir = 0; dir < 4; dir++) {
    int ii = dx[dir] + i;
    int jj = dy[dir] + j;
    if (ii >= 0 && ii < n &&
        jj >= 0 && jj < m &&
        !vis[ii][jj] &&
        grid[ii][jj] == '.') {
      dfs(ii, jj);
    }
  }
}

int main() {
  setIO();
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> grid[i];
  }

  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] != '#' &&
          !vis[i][j]) {
        count += 1;
        dfs(i, j);
      }
    }
  }
  cout << count << endl;
}

