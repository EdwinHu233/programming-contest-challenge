#include <cstdio>
#include <cstring>
using namespace std;

const int N = 105, M = 100010;
const int INF = 0x7f7f7f7f;

int dp[M];
int vs[N], cs[N];
int n, m;

bool init() {
  scanf("%d%d", &n, &m);
  if (n == 0) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", vs + i);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", cs + i);
  }
  return true;
}

int solve() {
  memset(dp, 0x7f, sizeof(dp));
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (dp[j] < INF) {
        dp[j] = 0;
      } else if (j >= vs[i] && dp[j - vs[i]] < cs[i]) {
        dp[j] = dp[j - vs[i]] + 1;
      } else {
        dp[j] = INF;
      }
    }
  }
  int ans = 0;
  for (int j = 1; j <= m; ++j) {
    if (dp[j] < INF) {
      ans++;
    }
  }
  return ans;
}

int main() {
  while (init()) {
    printf("%d\n", solve());
  }
}
