#include <algorithm>
#include <cstdio>
using namespace std;

const int M = 1024;
int n, m, r;
struct Interval {
  int a, b, v;
  bool operator<(const Interval &rhs) const { return a < rhs.a; }
} is[M];
int dp[M];

void init() {
  scanf("%d%d%d", &n, &m, &r);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &is[i].a, &is[i].b, &is[i].v);
  }
  sort(is, is + m);
}

int solve() {
  dp[0] = is[0].v;
  int ans = dp[0];
  for (int i = 1; i < m; ++i) {
    for (int j = 0; j < i; ++j) {
      if (is[j].b + r <= is[i].a) {
        dp[i] = max(dp[i], dp[j]);
      }
    }
    dp[i] += is[i].v;
    ans = max(ans, dp[i]);
  }
  return ans;
}

int main() {
  init();
  printf("%d\n", solve());
}
