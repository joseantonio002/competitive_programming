#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int nc;
  cin >> nc;
  for(int j = 1; j <= nc; j++) {
    int nplanets;
    cin >> nplanets;
    vector<int> votes;
    float totalvotes = 0;
    for(int i = 0; i < nplanets; i++) {
        int v;
        cin >> v;
        votes.push_back(v);
        totalvotes += v;
    }
    sort(votes.rbegin(), votes.rend());

    double half = totalvotes / 2.0;
    int npla, sum = 0;
    for(int i = 0; i < nplanets; i++) {
        sum += votes.at(i);
        if (sum > half) {
            npla = i + 1;
            break;
        }
    };
    cout << "Case " << j << ": " << npla << " planets" << endl;


  }

  return 0;
}