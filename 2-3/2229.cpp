#include <cstdio>
using namespace std;

const int N = 1000010;
const int MOD = 1000000000;

int dp[N];
int n;

int main() {
  scanf("%d", &n);
  dp[1] = 1;
  for (int i = 2; i <= n; ++i) {
    if (i % 2 == 0) {
      dp[i] = (dp[i - 1] + dp[i / 2]) % MOD;
    } else {
      dp[i] = dp[i - 1];
    }
  }
  printf("%d\n", dp[n]);
}
