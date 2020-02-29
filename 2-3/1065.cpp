#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;

const int MAX = 5010;

pair<int, int> sticks[MAX];
typedef set<int, greater<int> /**/> ReversedSet;
ReversedSet st;
int n;

void init() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &sticks[i].first, &sticks[i].second);
  }
  sort(sticks, sticks + n);
}

int solve() {
  st.clear();
  for (int i = 0; i < n; ++i) {
    int x = sticks[i].second;
    ReversedSet::iterator it = st.lower_bound(x);
    if (it != st.end()) {
      st.erase(it);
    }
    st.insert(x);
  }
  return st.size();
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    init();
    printf("%d\n", solve());
  }
}
