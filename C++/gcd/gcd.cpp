/**
GCD(a, b)
**/

#include<ctime>
#include<iostream>
#include<algorithm>

using namespace std;

//Naive GCD implementation
int GCDNaive(int a, int b) {
  int gcd = -1;

  for (int i = 1; i <= min(a, b); i++) {
    if (!(a%i) && !(b%i)) {
      //a and b are both divisible by i
      gcd = i;
    }
  }
  return gcd;
}

//Fast GCD implementation
int GCDFast(int a, int b) {
  if (a < b) {
    swap(a, b);
  }

  if (!b) {
    return a;
  } else {
    GCDFast(b, a%b);
  }
}

//Stress test
void stress_test(void) {
  srand(time(NULL));

  while(1) {
    int limit = 10000000;
    int a = rand() % limit + 1;
    int b = rand() % limit + 1;
    long long gcd_slow = GCDNaive(a, b);
    long long gcd_fast = GCDFast(a, b);

    if (gcd_slow == gcd_fast) {
      cout << "Success: " << a << " " << b << " " << gcd_slow << " " << gcd_fast << endl;
    } else {
      cout << "Error: " << a << " " << b << " " << gcd_slow << " " << gcd_fast << endl;
      return;
    }
  }
  return;
}

int main(int argc, char **argv) {
  stress_test();
  return 0;
}
