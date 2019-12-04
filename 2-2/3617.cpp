#include <cstdio>
using namespace std;

const int MAX = 2048;
int n;
char xs[MAX];

int main() {
  scanf("%d\n", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%c\n", xs + i);
  }
  int a = 0, b = n - 1;
  for (int i = 0; i < n; ++i) {
    char c;
    int aa = a, bb = b;
    while (aa < bb && xs[aa] == xs[bb]) {
      ++aa;
      --bb;
    }
    if (xs[aa] < xs[bb]) {
      c = xs[a++];
    } else {
      c = xs[b--];
    }
    putchar(c);
    if ((i + 1) % 80 == 0) {
      putchar('\n');
    }
  }
}
