#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

#define Interval pair<double, double>
const int MAX = 1024;

Interval is[MAX];
int n, d;

bool init()
{
    bool flag = true;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (d >= y)
        {
            double r = sqrt(d * d - y * y);
            is[i] = make_pair(x - r, x + r);
        }
        else
        {
            flag = false;
        }
    }
    return flag;
}

int solve()
{
    double rightmost = -1e10;
    int ans = 0;
    sort(is, is + n);
    for (int i = 0; i < n; ++i)
    {
        if (rightmost < is[i].first)
        {
            ++ans;
            rightmost = is[i].second;
        }
        else
        {
            rightmost = min(rightmost, is[i].second);
        }
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    int case_id = 0;
    while (scanf("%d%d", &n, &d) && n > 0)
    {
        int ans = init() ? solve() : -1;
        printf("Case %d: %d\n", ++case_id, ans);
    }
}