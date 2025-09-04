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
    if (n == 0) return 0;
    long long fullCycles = n / PERIOD;
    long long remainder = n % PERIOD;

    long long sumFull = prefixSum[PERIOD - 1];
    long long sumRemainder = prefixSum[remainder - 1]; // prefixSum is 0-indexed

    return fullCycles * sumFull + sumRemainder;
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