#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX = 100100;
struct Cow {
  int t, d;
  bool operator<(const Cow &rhs) const { return t * rhs.d < rhs.t * d; }
} cs[MAX];

int n;

void init() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &cs[i].t, &cs[i].d);
  }
  sort(cs, cs + n);
}

long long solve() {
  long long ans = 0;
  long long time = 0;
  for (int i = 0; i < n; ++i) {
    ans += time * cs[i].d;
    time += 2 * cs[i].t;
  }
  return ans;
}

int main() {
  init();
  printf("%lld\n", solve());
}
