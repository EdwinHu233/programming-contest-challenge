#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX = 25010;

pair<int, int> xs[MAX];
int N, T;

void init() {
  scanf("%d %d", &N, &T);
  for (int i = 0; i < N; ++i) {
    scanf("%d %d", &(xs[i].first), &(xs[i].second));
  }
}

int solve() {
  sort(xs, xs + N);
  int ans = 0, target = 1, i = 0;
  while (target <= T) {
    int rightmost = -1;
    while (i < N && xs[i].first <= target) {
      rightmost = max(rightmost, xs[i].second);
      ++i;
    }
    if (rightmost < 0) {
      return -1;
    }
    ++ans;
    target = rightmost + 1;
  }
  return ans;
}

int main() {
  init();
  printf("%d\n", solve());
}
