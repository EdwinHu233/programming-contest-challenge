#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

const int MAX = 104;
int ns[MAX];
int n;

void init() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", ns + i);
  }
  sort(ns, ns + n);
}

float solve() {
  if (n == 1) {
    return ns[0];
  }
  float ans = 2 * sqrt(ns[n - 1] * ns[n - 2]);
  for (int i = n - 3; i >= 0; --i) {
    ans = 2 * sqrt(ans * ns[i]);
  }
  return ans;
}

int main() {
  init();
  printf("%.3f\n", solve());
}
