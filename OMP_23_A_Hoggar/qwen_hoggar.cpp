#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, g;
        cin >> n >> g;
        vector<pair<int, int>> pirates;
        vector<pair<int, int>> non_pirates;

        for (int i = 0; i < n; i++) {
            int a, c, p;
            cin >> a >> c >> p;
            if (p == 1) {
                pirates.push_back({c, a});
            } else {
                non_pirates.push_back({c, a});
            }
        }

        sort(pirates.begin(), pirates.end());

        int num_pirates = pirates.size();
        vector<long long> prefix_cost(num_pirates + 1, 0);
        vector<long long> prefix_attack(num_pirates + 1, 0);
        vector<long long> min_gold_req(num_pirates + 1, 0);

        for (int i = 1; i <= num_pirates; i++) {
            prefix_cost[i] = prefix_cost[i - 1] + pirates[i - 1].first;
            prefix_attack[i] = prefix_attack[i - 1] + pirates[i - 1].second;
            min_gold_req[i] = max(min_gold_req[i - 1], prefix_cost[i] - (i - 1));
        }

        vector<int> dp(g + 1, 0);
        for (const auto& mp : non_pirates) {
            int cost = mp.first;
            int attack = mp.second;
            if (cost > g) continue;
            for (int j = g; j >= cost; j--) {
                dp[j] = max(dp[j], dp[j - cost] + attack);
            }
        }

        long long ans = 0;
        for (int i = 0; i <= num_pirates; i++) {
            if (g < min_gold_req[i]) continue;
            long long leftover = g - prefix_cost[i] + i;
            if (leftover < 0) continue;
            if (leftover > g) leftover = g;
            ans = max(ans, prefix_attack[i] + dp[leftover]);
        }

        cout << ans << '\n';
    }
    return 0;
}