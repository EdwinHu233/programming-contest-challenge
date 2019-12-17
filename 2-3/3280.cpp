#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 30, M = 2048;

int cost[N];
int dp[M][M];
char str[M];
int n, m;

void init() {
  scanf("%d %d\n", &n, &m);
  scanf("%s\n", str);
  for (int i = 0; i < n; ++i) {
    char c;
    int a, d;
    scanf("%c %d %d\n", &c, &a, &d);
    cost[c - 'a'] = min(a, d);
  }
}

int solve() {
  for (int i = m - 1; i >= 0; --i) {
    for (int j = i + 1; j < m; ++j) {
      if (str[i] == str[j]) {
        dp[i][j] = dp[i + 1][j - 1];
      } else {
        dp[i][j] = min(dp[i + 1][j] + cost[str[i] - 'a'],
                       dp[i][j - 1] + cost[str[j] - 'a']);
      }
    }
  }
  return dp[0][m - 1];
}

int main() {
  init();
  printf("%d\n", solve());
}
