#include <algorithm>
#include <cstdio>
using namespace std;

const int INF = 0x7f7f7f7f;
char line[30];
int xs[10];
int n;

void init() {
  n = 0;
  fgets(line, sizeof(line), stdin);
  for (int i = 0; line[i]; ++i) {
    if (i % 2 == 0) {
      xs[n++] = line[i] - '0';
    }
  }
}

inline int value(int i, int j) {
  if (xs[i] == 0 && j - i != 1) {
    return -1;
  }
  int ans = 0;
  for (; i < j; ++i) {
    ans = ans * 10 + xs[i];
  }
  return ans;
}

inline int solve() {
  int ans = INF;
  do {
    int a = value(0, n / 2), b = value(n / 2, n);
    if (a >= 0 && b >= 0) {
      ans = min(ans, abs(a - b));
    }
  } while (next_permutation(xs, xs + n));
  return ans;
}

int main() {
  int num_cases;
  scanf("%d\n", &num_cases);
  while (num_cases--) {
    init();
    printf("%d\n", solve());
  }
}
