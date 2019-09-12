// poj2386, p32
#include <cstdio>
#include <queue>
using namespace std;

constexpr int MAX = 110;

char water[MAX][MAX];
bool visit[MAX][MAX];
int N, M;
int ans;

void init() {
  scanf("%d%d\n", &N, &M);
  for (int i = 0; i < N; ++i) {
    fgets(water[i], MAX, stdin);
  }
}

void bfs(int i, int j) {
  visit[i][j] = true;
  ++ans;
  queue<pair<int, int>> q;
  q.push(make_pair(i, j));
  while (!q.empty()) {
    auto p = q.front();
    q.pop();
    for (int di = -1; di <= 1; ++di) {
      for (int dj = -1; dj <= 1; ++dj) {
        int i = p.first + di, j = p.second + dj;
        if (i >= 0 && i < N && j >= 0 && j < M && water[i][j] == 'W' &&
            !visit[i][j]) {
          visit[i][j] = true;
          q.push(make_pair(i, j));
        }
      }
    }
  }
}

int main() {
  init();
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (water[i][j] == 'W' && !visit[i][j]) {
        bfs(i, j);
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
