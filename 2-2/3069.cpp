#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1024;
int pos[MAX];
int R, N;

bool init()
{
    scanf("%d%d", &R, &N);
    if (R < 0)
    {
        return false;
    }
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", pos + i);
    }
    sort(pos, pos + N);
    return true;
}

int solve()
{
    int ans = 0;
    int start = 0;
    while (start < N)
    {
        int mid = start;
        while (mid < N && pos[mid] - pos[start] <= R)
        {
            ++mid;
        }
        --mid;
        int end = mid;
        while (end < N && pos[end] - pos[mid] <= R)
        {
            ++end;
        }
        start = end;
        ++ans;
    }
    return ans;
}

int main()
{
#define LOCAL
#ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    while (init())
    {
        printf("%d\n", solve());
    }
}