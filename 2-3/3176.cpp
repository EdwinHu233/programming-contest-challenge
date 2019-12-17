#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 355;
int xs[N][N];
int n;

void init() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      scanf("%d", &xs[i][j]);
    }
  }
}

int solve() {
  for (int i = n - 2; i >= 0; --i) {
    for (int j = 0; j <= i; ++j) {
      xs[i][j] = xs[i][j] + max(xs[i + 1][j], xs[i + 1][j + 1]);
    }
  }
  return xs[0][0];
}

int main() {
  init();
  printf("%d\n", solve());
}
