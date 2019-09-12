#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX = 25;
bool block[MAX][MAX];
int ROW, COL;
int si, sj, gi, gj;
int ans;
const int di[] = {0, 1, 0, -1};
const int dj[] = {-1, 0, 1, 0};

inline bool valid_pos(int i, int j) {
  return i >= 0 && i < ROW && j >= 0 && j < COL;
}

bool init() {
  scanf("%d%d", &COL, &ROW);
  if (COL == 0) {
    return false;
  }
  ans = 0x7f7f7f7f;
  int tmp;
  for (int i = 0; i < ROW; ++i) {
    for (int j = 0; j < COL; ++j) {
      scanf("%d", &tmp);
      block[i][j] = (tmp == 1);
      if (tmp == 2) {
        si = i, sj = j;
      } else if (tmp == 3) {
        gi = i, gj = j;
      }
    }
  }
  return true;
}

void backtrace(const int i, const int j, const int step) {
  if (step == 10) {
    return;
  }
  for (int k = 0; k < 4; ++k) {
    int ni = i + di[k], nj = j + dj[k];
    if (!valid_pos(ni, nj) || block[ni][nj]) {
      continue;
    }
    for (; valid_pos(ni, nj); ni += di[k], nj += dj[k]) {
      if (ni == gi && nj == gj) {
        ans = min(ans, step + 1);
        break;
      } else if (block[ni][nj]) {
        block[ni][nj] = false;
        backtrace(ni - di[k], nj - dj[k], step + 1);
        block[ni][nj] = true;
        break;
      }
    }
  }
}

int main() {
  while (init()) {
    backtrace(si, sj, 0);
    printf("%d\n", (ans == 0x7f7f7f7f ? -1 : ans));
  }
}
