#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 512, W = 10010;
const int INF = 0x7f7f7f7f;

int target, n;
int ws[N], vs[N];
int dp[W];

void init() {
  int e, f;
  scanf("%d%d", &e, &f);
  target = f - e;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", vs + i, ws + i);
  }
  fill(dp, dp + W, INF);
  dp[0] = 0;
}

void solve() {
  for (int i = 1; i <= n; ++i) {
    int w = ws[i - 1], v = vs[i - 1];
    for (int j = w; j <= target; ++j) {
      dp[j] = min(dp[j], dp[j - w] + v);
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    init();
    solve();
    if (dp[target] == INF) {
      printf("This is impossible.\n");
    } else {
      printf("The minimum amount of money in the piggy-bank is %d.\n",
             dp[target]);
    }
  }
}
