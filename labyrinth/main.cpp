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
const int mn = 1005;
char grid[mn][mn];
bool vis[mn][mn];
int prevStep[1005][1005];

string stepDir = "DRUL";
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

int main() {
  setIO();
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> grid[i];
  }
  pi start, end;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 'A') {
        start = mp(i, j);
      } else if (grid[i][j] == 'B') {
        end = mp(i, j);
      }
    }
  }

  queue<pi> q;
  q.push(start);
  vis[start.f][start.s] = true;
  while (!q.empty()) {
    pi cur = q.front(); q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = cur.f + dx[i];
      int ny = cur.s + dy[i];
      if (nx >= 0 && nx < n && 
          ny >= 0 && ny < m &&
          !vis[nx][ny] &&
          grid[nx][ny] != '#') {
        pi next = mp(nx, ny);
        prevStep[nx][ny] = i;
        vis[nx][ny] = true;
        q.push(next);
      }
    }
  }

  if (vis[end.f][end.s]) {
    cout << "YES" << endl;
    vi steps;
    while (end != start) {
      int p = prevStep[end.f][end.s];
      steps.pb(p);
      end = mp(end.f - dx[p], end.s - dy[p]);
    }
    reverse(steps.begin(), steps.end());
    cout << steps.size() << endl;
    for (char c : steps) {
      cout << stepDir[c];
    }
    cout << endl;
  } else {
    cout << "NO" << endl;
  }

}

