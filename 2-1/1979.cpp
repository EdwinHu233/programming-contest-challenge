#include <cstdio>
#include <queue>
using namespace std;

const int MAX = 25;
char map[MAX][MAX];
int W, H;
int start_i, start_j;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

bool init() {
  scanf("%d%d\n", &W, &H);
  if (W == 0) {
    return false;
  }
  for (int i = 0; i < H; ++i) {
    fgets(map[i], MAX, stdin);
    for (int j = 0; j < W; ++j) {
      if (map[i][j] == '@') {
        start_i = i;
        start_j = j;
        map[i][j] = '.';
      }
    }
  }
  return true;
}

int solve() {
  queue<pair<int, int>> q;
  q.push(make_pair(start_i, start_j));
  map[start_i][start_j] = '#';
  int ans = 1;
  while (!q.empty()) {
    auto p = q.front();
    q.pop();
    for (int k = 0; k < 4; ++k) {
      int i = p.first + di[k], j = p.second + dj[k];
      if (i >= 0 && i < H && j >= 0 && j < W && map[i][j] == '.') {
        ++ans;
        map[i][j] = '#';
        q.push(make_pair(i, j));
      }
    }
  }
  return ans;
}

int main() {
  while (init()) {
    printf("%d\n", solve());
  }
  return 0;
}
