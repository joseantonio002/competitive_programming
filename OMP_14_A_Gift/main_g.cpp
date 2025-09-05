#include <bits/stdc++.h>
using namespace std;

bool isprime(int n) {
  if (n <= 1) {return false;}   
  int c = 0;
  for(int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
        c++;
    }
    if (c == 1) {break;}
  }
  return c == 0;
} 

bool ispal(string n) {
    int s = int(n.size());
    if (s == 2) {return n[0] == n[1];}
    int half_i = s / 2;
    for(int i = 0; i < half_i; i++) {
        if (n[i] != n[s - i - 1]) {return false;}
    }
    return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while(true) {
    int n;
    cin >> n;

    string ns = to_string(n);

    cout << n * 2 << endl;

    if (ispal(ns) && isprime(n)) break;

  }


  return 0;
}