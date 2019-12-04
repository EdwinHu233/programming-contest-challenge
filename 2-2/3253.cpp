#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

const int MAX = 20010;
int n;
priority_queue<long long, vector<long long>, greater<long long> /**/> pq;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    pq.push(x);
  }
  long long ans = 0;
  for (int i = 0; i < n - 1; ++i) {
    int x = pq.top();
    pq.pop();
    int y = pq.top();
    pq.pop();
    ans += x + y;
    pq.push(x + y);
  }
  printf("%lld\n", ans);
}
