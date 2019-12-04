#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX = 12;
int co[MAX], xs[MAX];
int N, target;

void generateCoefficient() {
  int x = 1;
  for (int i = 1; i < N; ++i) {
    x *= i;
  }
  for (int i = 0; i < N; ++i) {
    co[i] = x;
  }
  x = 1;
  for (int i = 0; i < N; ++i) {
    co[i] /= x;
    co[N - 1 - i] /= x;
    x *= i + 1;
  }
}

inline int getSum() {
  int sum = 0;
  for (int i = 0; i < N; ++i) {
    sum += co[i] * xs[i];
  }
  return sum;
}

void solve() {
  for (int i = 0; i < N; ++i) {
    xs[i] = i + 1;
  }
  do {
    if (getSum() == target) {
      return;
    }
  } while (next_permutation(xs, xs + N));
}

int main() {
  scanf("%d%d", &N, &target);
  generateCoefficient();
  solve();
  for (int i = 0; i < N; ++i) {
    if (i) {
      printf(" ");
    }
    printf("%d", xs[i]);
  }
  return 0;
}