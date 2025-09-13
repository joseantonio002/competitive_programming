# Problem description:

[Problem](https://onlinejudge.inf.um.es/~mooshak/cgi-bin/execute/7866297516909566)

This is a combinatorial optimization problem, meaning, finding the best solution inside a finite set of possible solutions.

# What puzzled me

Give priority to pirates, but how?

# First instinct

Brute force and store results in a matrix, but the matrix can only store results of two objects, not various

Reduce cost of pirates by one (This is wrong because the refund is AFTER the purchase)
```
#include <bits/stdc++.h>
using namespace std;

struct minion {
  int a, c;
  minion(int at, int cs, int p) {
    a = at;
    if(p == 1) c = cs - 1;
    else c = cs;
  }
  bool operator<(const minion& o) const {
    return c < o.c;
  }
};

int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  while(N--) {
    int nm, g;
    vector<minion> minions;
    cin >> nm >> g;
    while(nm--) {
      int a, c, p;
      cin >> a >> c >> p;
      minions.push_back(minion(a, c, p));
    } 
    sort(minions.rbegin(), minions.rend());
    vector<vector<int>> results(nm, vector<int>(nm, -1));
    for(int i = 0; i < nm; i++) {
      for(int j = i + 1; j < nm; j++) {
        if(results[i][j] != -1) return results[i][j];
        
      }
    } 
  }

  return 0;
}

```

# Actual solution



# Miscellaneous