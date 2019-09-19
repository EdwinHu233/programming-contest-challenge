#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 25010;
pair<int, int> cows[MAX];
int N, T;

void init()
{
    scanf("%d%d", &N, &T);
    for (int i = 0; i < N; ++i)
    {
        scanf("%d%d", &cows[i].first, &cows[i].second);
    }
    sort(cows, cows + N);
}

int solve()
{
    int ans = 0, start = 1, i = 0;
    while (start <= T)
    {
        int next = -1;
        while (i < N && cows[i].first <= start)
        {
            next = max(next, cows[i].second);
            ++i;
        }
        if (next < 0)
        {
            return -1;
        }
        start = next + 1;
        ++ans;
    }
    return ans;
}

int main()
{
    init();
    printf("%d", solve());
}