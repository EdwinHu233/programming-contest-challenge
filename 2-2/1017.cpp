#include <cstdio>
using namespace std;

int ns[7];

bool init() {
  bool non_zero = false;
  for (int i = 1; i <= 6; ++i) {
    scanf("%d", ns + i);
    if (ns[i] != 0) {
      non_zero = true;
    }
  }
  return non_zero;
}

int solve() {
  int ans = ns[6] + ns[5] + ns[4];
  int one = 11 * ns[5];
  int two = 5 * ns[4];
  ans += (ns[3] + 3) / 4;
  int mod = ns[3] % 4;
  if (mod == 1) {
    two += 5;
    one += 7;
  } else if (mod == 2) {
    two += 3;
    one += 6;
  } else if (mod == 3) {
    two += 1;
    one += 5;
  }
  if (ns[2] > two) {
    int new_parcels = (ns[2] - two + 8) / 9;
    ans += new_parcels;
    two = new_parcels * 9 - (ns[2] - two);
  } else {
    two -= ns[2];
  }
  one += 4 * two;
  if (ns[1] > one) {
    ans += (ns[1] - one + 35) / 36;
  }
  return ans;
}

int main() {
  while (init()) {
    printf("%d\n", solve());
  }
}
