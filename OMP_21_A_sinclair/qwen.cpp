#include <iostream>
using namespace std;

const long long MOD = 1000007;

long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp = exp >> 1;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long exponent = n * 1024LL;
        cout << mod_exp(256, exponent, MOD) << '\n';
    }
    return 0;
}