#include <cstdio>
using namespace std;

const int MAX = 1024;

// MOD must be less than (1 << 64) / 2 == 9223372036854775808,
// otherwise the add operation might overflow.
// To make printing easier, MOD should satisfy MOD % 10 == 0.
const unsigned long long MOD = 1000000000000000000u;

struct Int {
  unsigned long long high, low;
  void operator+=(const Int &rhs) {
    low += rhs.low;
    high += rhs.high + (low / MOD);
    low %= MOD;
  }
  void print() const {
    if (high != 0) {
      printf("%llu", high);
      printf("%018llu\n", low);
    } else {
      printf("%llu\n", low);
    }
  }
};

Int dp[MAX];
int N, K;

int main() {
  scanf("%d%d", &N, &K);
  dp[0].low = 1;
  for (int i = 1; i <= K; ++i) {
    for (int j = i; j <= N; ++j) {
      dp[j] += dp[j - i];
    }
  }
  dp[N].print();
}
