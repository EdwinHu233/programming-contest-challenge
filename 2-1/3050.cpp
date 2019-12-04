#include <cstdio>
#include <set>
using namespace std;

const int SIZE = 5, STEP = 5;
const int di[] = {0, 1, 0, -1};
const int dj[] = {1, 0, -1, 0};

int map[SIZE][SIZE];
set<int> s;

void solve(int i, int j, int x, int remain_step) {
  x = x * 10 + map[i][j];
  if (remain_step == 0) {
    s.insert(x);
  } else {
    for (int k = 0; k < 4; ++k) {
      int ii = i + di[k];
      int jj = j + dj[k];
      if (ii >= 0 && ii < SIZE && jj >= 0 && jj < SIZE) {
        solve(ii, jj, x, remain_step - 1);
      }
    }
  }
}

int main() {
// #define LOCAL
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      scanf("%d", &(map[i][j]));
    }
  }
  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      solve(i, j, 0, STEP);
    }
  }
  printf("%d\n", s.size());
}