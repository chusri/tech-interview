//Maximum pairwise product

#include<vector>
#include<cstdlib>
#include<iostream>

using std::cout;
using std::vector;

long long MaxPairwiseProductFast(const vector<int>& v) {
  //Fast implementation: O(n)
  int max_index1 = -1;
  int max_index2 = -1;

  for (int i = 0; i < v.size(); i++) {
    if ((max_index1 == -1) || (v[i] > v[max_index1])) max_index1 = i;
  }

  for (int i = 0; i < v.size(); i++) {
    if ((i != max_index1) && ((max_index2 == -1) || (v[i] > v[max_index2])))
      max_index2 = i;
  }

  return(v[max_index1] * v[max_index2]);
}

long long MaxPairwiseProduct(const vector<int>& v) {
  //Naive implementation: O(n^2)
  int n = v.size();
  long long prod = 0;
  long long max_prod = 0;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      prod = v[i] * v[j];
      if (prod > max_prod) max_prod = prod;
    }
  }
  return max_prod;
}

int stress_test() {
  //Stress test suite
  int n = 10000;
  vector<int> v(n);
  long long max_prod1;
  long long max_prod2;

  while(1) {
    for (int i = 0; i < v.size(); i++) {
      v[i] = rand() % 40000 + 2;
    }

    max_prod1 = MaxPairwiseProduct(v);
    max_prod2 = MaxPairwiseProductFast(v);

    if (max_prod1 != max_prod2) {
      cout << "Error: "  << max_prod1 << " " << max_prod2 << std::endl;
      for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
      }
      cout << std::endl;
      return 1;
    } else {
      cout << "OK: "  << max_prod1 << " " << max_prod2 << std::endl;
    }
  }
}

int main() {
  stress_test();
  return 0;
}
