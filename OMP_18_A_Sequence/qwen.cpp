#include <iostream>
using namespace std;


//https://chat.qwen.ai/c/e6a37cb0-12e8-498e-a034-786da6ea63cc

int main() {
    int n;
    cin >> n;

    while (n--) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;

        // 1. Check Arithmetic: constant difference
        long long diff = b - a;
        if (b + diff == c && c + diff == d) {
            cout << d + diff << endl;
            continue;
        }

        // 2. Check "Add more": differences increase by 1
        long long d1 = b - a;
        long long d2 = c - b;
        long long d3 = d - c;
        if (d2 == d1 + 1 && d3 == d2 + 1) {
            long long next_diff = d3 + 1;
            cout << d + next_diff << endl;
            continue;
        }

        // 3. Check Geometric: multiply by constant (result must be integer)
        bool geo_valid = false;
        long long next_geo = 0;

        if (a == 0) {
            // If first term is 0, all must be 0
            if (b == 0 && c == 0 && d == 0) {
                geo_valid = true;
                next_geo = 0;
            }
        } else {
            // Check ratio consistency: b^2 == a*c and c^2 == b*d
            if (b * b == a * c && c * c == b * d) {
                if (c == 0) {
                    // If c is 0, d must be 0 to have valid next term
                    if (d == 0) {
                        geo_valid = true;
                        next_geo = 0;
                    }
                } else {
                    // Check if next term (d * d / c) is integer
                    if ((d * d) % c == 0) {
                        geo_valid = true;
                        next_geo = (d * d) / c;
                    }
                }
            }
        }

        if (geo_valid) {
            cout << next_geo << endl;
            continue;
        }

        // 4. Check Fibonacci: each term is sum of two previous
        if (c == a + b && d == b + c) {
            cout << c + d << endl;
            continue;
        }

        // 5. None of the patterns match
        cout << 42 << endl;
    }

    return 0;
}