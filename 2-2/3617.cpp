#include <cstdio>

const int MAX = 2010;
char s[MAX];
char t[MAX];
int N;

int main()
{
// #define LOCAL
#ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    scanf("%d\n", &N);
    for (int i = 0; i < N; ++i)
    {
        scanf("%c\n", s + i);
    }
    s[N] = '\0';
    int a = 0, b = N - 1;
    int cnt = 0;
    while (a <= b)
    {
        bool left = true;
        for (int aa = a, bb = b; aa <= bb; ++aa, --bb)
        {
            if (s[aa] != s[bb])
            {
                left = s[aa] < s[bb];
                break;
            }
        }
        if (left)
        {
            t[cnt++] = s[a++];
        }
        else
        {
            t[cnt++] = s[b--];
        }
    }
    for (int i = 0; i < N; ++i)
    {
        putchar(t[i]);
        if ((i + 1) % 80 == 0 && i != N - 1)
        {
            putchar('\n');
        }
    }
}