#include <bits/stdc++.h>

using namespace std;

long long mypow(int n, long long x) {
    if(x == 0) return 1;
    long long s = 1;
    for(int i = 0; i < x; i++) s *= n;
    return s;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  while(N--) {
    long long n;
    cin >> n;
    n = n * 1024 * 8;
    long long p = 1;
    cout << "Loops: " << (n / 63) << " Mob: "<< (n % 63) << endl;
    for(int i = 0; i < (n / 63); i++) {
        p *= (((unsigned long long)2 << 62) % 1000007);
        p %= 1000007;
        cout << p << "#" << endl;
    }
    p *= (((long long)2 << (n % 63)) % 1000007);
    cout << p<< endl;
  }


  return 0;
}