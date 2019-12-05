#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
  int n, s;
  scanf("%d%d", &n, &s);

  long long ans = 0;
  int min_cost = 0x7f7f7f7f;
  int c, y;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &c, &y);
    min_cost = min(min_cost + s, c);
    ans += y * min_cost;
  }
  printf("%lld\n", ans);
}
