#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX = 25;
pair<int, int> cs[MAX];
int plan[MAX];
int n, c;

void init() {
  scanf("%d%d", &n, &c);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &cs[i].first, &cs[i].second);
  }
  sort(cs, cs + n);
}

bool get_plan() {
  int remain = c;
  // get a plan which is <= 'c' but as great as possible
  for (int i = n - 1; i >= 0; --i) {
    plan[i] = min(cs[i].second, remain / cs[i].first);
    remain -= plan[i] * cs[i].first;
  }
  // the plan is == 'c'
  if (remain == 0) {
    return true;
  }
  // the plan is < 'c'
  // try to fill the gap with a small coin
  for (int i = 0; i < n; ++i) {
    if (cs[i].second > plan[i]) {
      ++plan[i];
      return true;
    }
  }
  // failed to fill the gap (all remaining coins are insufficient)
  return false;
}

int use_plan() {
  int num_weeks = 0x7f7f7f7f;
  for (int i = 0; i < n; ++i) {
    if (plan[i] != 0) {
      num_weeks = min(num_weeks, cs[i].second / plan[i]);
    }
  }
  for (int i = 0; i < n; ++i) {
    cs[i].second -= num_weeks * plan[i];
  }
  return num_weeks;
}

int solve() {
  int ans = 0;
  while (get_plan()) {
    ans += use_plan();
  }
  return ans;
}

int main() {
  init();
  printf("%d\n", solve());
}
