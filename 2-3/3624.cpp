#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 3500, M = 13000;

int ws[N];
int vs[N];
int dp[M];
int n, m;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", ws + i, vs + i);
  }
  for (int i = 1; i <= n; ++i) {
    int w = ws[i - 1], v = vs[i - 1];
    for (int j = m; j >= w; --j) {
      dp[j] = max(dp[j], dp[j - w] + v);
    }
  }
  printf("%d\n", dp[m]);
}
