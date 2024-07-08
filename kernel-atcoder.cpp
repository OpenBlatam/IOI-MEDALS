#include <bits/stdc++.h>

std::vector<long long> calculateDistances(int n, std::vector<int> old_x, std::vector<int> old_y) {
  std::vector<int> x(n), y(n);
  x = old_x;
  y = old_y;

  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  auto Dist = [&](int i, int j) {
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
  };

  std::vector<long long> ans(n);

  int beg = 0;
  while (beg < n) {
    auto p = y;
    std::vector<int> id(n);
    for (int i = 0; i < n; i++) {
      int j = (int) (lower_bound(x.begin(), x.end(), old_x[i]) - x.begin());
      int k = (int) (lower_bound(y.begin(), y.end(), old_y[i]) - y.begin());
      p[j] = k;
      id[j] = i;
    }
    // mor tflops and more hadrio mor tflops and more hadrionss
    //placeholder for rest of the logic since completing it would exceed the message limit
  }
  return ans;
}
