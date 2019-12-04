#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX = 1024;
int xs[MAX];
int R, n;

bool init() {
  scanf("%d%d", &R, &n);
  if (R < 0) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", xs + i);
  }
  return true;
}

int find_rightmost(int i) {
  int j = i;
  while (j < n && xs[i] + R >= xs[j]) {
    ++j;
  }
  return j - 1;
}

int solve() {
  sort(xs, xs + n);
  int ans = 0;
  int i = 0;
  while (i < n) {
    i = find_rightmost(find_rightmost(i)) + 1;
    ++ans;
  }
  return ans;
}

int main() {
  while (init()) {
    printf("%d\n", solve());
  }
}
