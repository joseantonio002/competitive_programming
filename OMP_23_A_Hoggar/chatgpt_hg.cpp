#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll NEG = (ll)-4e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, g;
        cin >> n >> g;
        vector<pair<int,int>> pirates;   // (cost, attack)
        vector<pair<int,int>> others;    // non-pirates (cost, attack)
        for (int i = 0; i < n; ++i) {
            int a, c, p;
            cin >> a >> c >> p;
            if (p == 1) pirates.emplace_back(c, a);
            else others.emplace_back(c, a);
        }

        // sort pirates by cost ascending
        sort(pirates.begin(), pirates.end());

        // dp_p[m] = maximum attack obtainable from pirates alone leaving exactly m gold
        vector<ll> dp_p(g + 1, NEG);
        dp_p[g] = 0; // start with g gold and 0 attack

        for (auto &pr : pirates) {
            int c = pr.first;
            int a = pr.second;
            // next state: either skip this pirate or buy it (if affordable)
            vector<ll> nxt = dp_p; // skipping preserves existing states
            if (c <= g) {
                for (int money = c; money <= g; ++money) {
                    if (dp_p[money] != NEG) {
                        int nm = money - c + 1; // pay c then receive 1 back
                        if (nm >= 0 && nm <= g) {
                            nxt[nm] = max(nxt[nm], dp_p[money] + a);
                        }
                    }
                }
            }
            dp_p.swap(nxt);
        }

        // knapsack for non-pirates: dp_o[cap] = best attack achievable with capacity cap
        vector<ll> dp_o(g + 1, 0);
        for (auto &it : others) {
            int c = it.first;
            int a = it.second;
            if (c > g) continue;
            for (int cap = g; cap >= c; --cap) {
                dp_o[cap] = max(dp_o[cap], dp_o[cap - c] + a);
            }
        }

        // combine: for every possible leftover gold after pirates, add best non-pirate value
        ll ans = 0;
        for (int money = 0; money <= g; ++money) {
            if (dp_p[money] != NEG) {
                ans = max(ans, dp_p[money] + dp_o[money]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}