#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

const int MAX = 1024;

pair<float, float> xs[MAX];

int n, d;
bool impossible;

bool init() {
  scanf("%d %d", &n, &d);
  if (n == 0) {
    return false;
  }
  impossible = false;
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    if (d >= y) {
      float half = sqrt(d * d - y * y);
      xs[i].first = x - half;
      xs[i].second = x + half;
    } else {
      impossible = true;
    }
  }
  return true;
}

int solve() {
  if (impossible) {
    return -1;
  }
  sort(xs, xs + n);
  int cnt = 1;
  float radar = xs[0].second;
  for (int i = 1; i < n; ++i) {
    if (radar < xs[i].first) {
      radar = xs[i].second;
      cnt += 1;
    } else {
      radar = min(radar, xs[i].second);
    }
  }
  return cnt;
}

int main() {
  int i = 0;
  while (init()) {
    printf("Case %d: %d\n", ++i, solve());
  }
  return 0;
}
