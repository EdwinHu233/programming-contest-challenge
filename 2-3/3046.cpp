#include <algorithm>
#include <cstdio>
using namespace std;

const int TYPE = 1024;
const int NUM = 100010;
const int MOD = 1000000;

inline int add(int a, int b) { return (a + b) % MOD; }
inline int sub(int a, int b) { return (a - b + MOD) % MOD; }

int ns[TYPE];
int dp[2][NUM];
int T, A, S, B;

void init() {
  scanf("%d%d%d%d", &T, &A, &S, &B);
  for (int i = 0; i < A; ++i) {
    int tmp;
    scanf("%d", &tmp);
    ns[tmp - 1]++;
  }
}

int solve() {
  int *prev = dp[0], *cur = dp[1];
  prev[0] = 1;
  for (int i = 0; i < T; ++i) {
    cur[0] = 1;
    for (int j = 1; j <= B; ++j) {
      cur[j] = add(cur[j - 1], prev[j]);
      if (j > ns[i]) {
        cur[j] = sub(cur[j], prev[j - 1 - ns[i]]);
      }
    }
    swap(prev, cur);
  }
  int ans = 0;
  for (int j = S; j <= B; ++j) {
    ans = add(ans, prev[j]);
  }
  return ans;
}

int main() {
  init();
  printf("%d\n", solve());
}
