#include <bits/stdc++.h>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

const int MOD = 100;
const int PERIOD = 300; // Pisano period for mod 100

vector<long long> fib(PERIOD);
vector<long long> prefixSum(PERIOD);

void precompute() {
    fib[0] = 1;
    fib[1] = 1;
    prefixSum[0] = fib[0];
    prefixSum[1] = prefixSum[0] + fib[1];

    for (int i = 2; i < PERIOD; i++) {
        fib[i] = (fib[i-1] + fib[i-2]) % MOD;
        prefixSum[i] = prefixSum[i-1] + fib[i];
    }
}

long long sumUpTo(long long n) {
    if(n == 0) return 0;
    long long numer_iterations = n / PERIOD;
    long long extra_it = n % PERIOD;
    long long last = prefixSum.at(int(prefixSum.size()) - 1);
    
    return (last * numer_iterations) + prefixSum[extra_it - 1]; // 0 indexed
}

int main() {
    precompute();

    int t;
    cin >> t;

    while (t--) {
        long long N, M;
        cin >> N >> M;

        long long result = sumUpTo(M) - sumUpTo(N - 1);
        cout << result << endl;
    }

    return 0;
}