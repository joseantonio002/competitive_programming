#include <bits/stdc++.h>
using namespace std;

long long sum_digits(long long n) {
  string ns = to_string(n);
  long long sum = 0;
  for(char d : ns) {
    sum += d - '0';
  }
  return sum;
}

bool is_square(long long n) {
  float sq = sqrt(n);
  return fmod(sq, 1.0f) == 0.0f;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<long long> seven{9, 10, 11, 12, 13, 14, 15};
  bool found = false;
  while(!found) {
    seven.push_back(seven.back() + 1);
    seven.erase(seven.begin());
    for(long long n : seven) {
      long long sd = sum_digits(pow(n, 2));
      //cout << sd << " " << is_square(sd) << endl;
      if(!is_square(sd)) {
        found = false;
        break;
      }
      found = true;
    }
  }

  for(int n : seven) {
    cout  << fixed << n << " " << long(pow(n, 2)) << endl;
  }

  return 0;
}