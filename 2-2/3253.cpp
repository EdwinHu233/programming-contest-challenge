#include <cstdio>
#include <queue>
using namespace std;

#define ULL unsigned long long

priority_queue<ULL, vector<ULL>, greater<ULL> > pq;
int N;

void init()
{
    scanf("%d", &N);
    int x;
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &x);
        pq.push(x);
    }
}

ULL solve()
{
    ULL ans = 0;
    for (int i = 0; i < N - 1; ++i)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        ans += a + b;
        pq.push(a + b);
    }
    return ans;
}

int main()
{
// #define LOCAL
#ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    init();
    printf("%llu", solve());
}