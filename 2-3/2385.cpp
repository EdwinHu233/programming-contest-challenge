#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1024;

const int T = 1024, W = 32;

int dp[W];
int t, w;

inline int tree(int j) { return j % 2 + 1; }

int main() {
  scanf("%d%d", &t, &w);
  for (int i = 0; i < t; ++i) {
    int apple;
    scanf("%d", &apple);
    for (int j = w; j >= 0; --j) {
      if (apple == tree(j)) {
        dp[j]++;
      } else if (j > 0) {
        dp[j] = max(dp[j], dp[j - 1] + 1);
      }
    }
  }
  int ans = -1;
  for (int j = 0; j <= w; ++j) {
    ans = max(dp[j], ans);
  }
  printf("%d\n", ans);
}
