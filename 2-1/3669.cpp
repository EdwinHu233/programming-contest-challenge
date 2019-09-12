#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 310;
const int di[] = {0, 1, 0, -1};
const int dj[] = {1, 0, -1, 0};

int time[MAX][MAX];
bool visit[MAX][MAX];

void init() {
  memset(time, 0x7f, sizeof(time));
  memset(visit, 0, sizeof(visit));
  int m, x, y, t;
  scanf("%d", &m);
  while (m--) {
    scanf("%d%d%d", &x, &y, &t);
    time[x][y] = min(time[x][y], t);
    for (int k = 0; k < 4; ++k) {
      int i = x + di[k], j = y + dj[k];
      if (i >= 0 && j >= 0) {
        time[i][j] = min(time[i][j], t);
      }
    }
  }
}

int solve() {
  queue<pair<int, int> > q;
  q.push(make_pair(0, 0));
  visit[0][0] = true;
  int t = 0;
  while (!q.empty()) {
    int n = q.size();
    while (n--) {
      pair<int, int> p = q.front();
      q.pop();
      int i = p.first, j = p.second;
      if (t >= time[i][j]) {
        continue;
      }
      if (time[i][j] == 0x7f7f7f7f) {
        return t;
      }
      for (int k = 0; k < 4; ++k) {
        int ni = i + di[k], nj = j + dj[k];
        if (ni >= 0 && nj >= 0 && !visit[ni][nj]) {
          q.push(make_pair(ni, nj));
          visit[ni][nj] = true;
        }
      }
      ++t;
    }
  }
  return -1;
}

int main() {
  init();
  printf("%d\n", solve());
  return 0;
}
