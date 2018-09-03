/**
Fibonacci series
F(0) = 0
F(1) = 1
F(n) = F(n-1) + F(n-2)
**/

#include<vector>
#include<cstdlib>
#include<iostream>

using std::cout;
using std::endl;
using std::vector;

long long FibonacciNaive(int n) {
  //Naive and slow implementation
  if (n <= 1) {
    return n;
  } else {
    return(FibonacciNaive(n-1) + FibonacciNaive(n-2));
  }
}

long long FibonacciFast(int n) {
  //Fast implementation
  vector<long long> v(n+1);

  v[0] = 0;
  v[1] = 1;

  for (int i = 2; i < n+1; i++) {
    v[i] = v[i-1] + v[i-2];
  }
  return v[n];
}

void stress_test(void) {
  //Stress test
  while(1) {
    int limit = 30;
    int n = rand() % limit + 1;
    long long fib_slow = FibonacciNaive(n);
    long long fib_fast = FibonacciFast(n);

    if (fib_slow == fib_fast) {
      cout << "Success: " << n << " " << fib_slow << " " << fib_fast << endl;
    } else {
      cout << "Error: " << n << " " << fib_slow << " " << fib_fast << endl;
      return;
    }
  }
  return;
}

int main(int argc, char** argv) {
  stress_test();
  return 0;
}
