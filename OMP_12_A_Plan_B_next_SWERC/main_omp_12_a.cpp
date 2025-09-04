#include <bits/stdc++.h>
using namespace std;

struct balloon {
  float x, y, r;
  balloon(float x, float y, float d): x(x), y(y), r(d/2.0) {}

};

void unique_vector(std::vector<int>& v) {
    std::unordered_set<int> seen;
    auto write = v.begin();                 // next unique slot
    for (int x : v)
        if (seen.insert(x).second)          // true if x was new
            *write++ = x;                   // keep it
    v.erase(write, v.end());                // shrink
}

void remove_indices(std::vector<balloon>& not_popped,
                    const std::vector<int>& idx_to_remove)
{
    // 1. sort the indices (largest → smallest)
    std::vector<int> idx = idx_to_remove;
    std::sort(idx.begin(), idx.end(), std::greater<int>());

    // 2. erase each position
    for (int i : idx)
    {
        if (i >= 0 && i < static_cast<int>(not_popped.size()))
            not_popped.erase(not_popped.begin() + i);
    }
}

inline bool float_eq(float a, float b, float epsilon = 1e-5f)
{
    float diff = std::fabs(a - b);
    float scale = std::max({std::fabs(a), std::fabs(b), 1.0f});
    return diff <= epsilon * scale;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int N;
  cin >> N;

  while (N--) {
    int ng;
    vector<balloon> not_popped;
    cin >> ng;
    while (ng--) {
      int xg, yg, dg;
      cin >> xg >> yg >> dg;
      not_popped.push_back(balloon(xg, yg, dg));
    }
    int n_popped = 0;
    vector<int> laser_fired;
    // every angle
    for(int i = 0; i <= 90; i += 10) {
      if(not_popped.empty()) break;
      float angle_r = (i * M_PI) / 180;
      vector<int> popped;
      // for each balloon
      for(int j = 0; j < int(not_popped.size()); j++) {
        balloon cb = not_popped[j];
        float xpos = cb.x, ypos = xpos * tan(angle_r);
        float dist = sqrt(pow(xpos - cb.x, 2) + pow(ypos - cb.y, 2));
        if (dist < cb.r || float_eq(dist, cb.r)) {
          laser_fired.push_back(i);
          popped.push_back(j);
        }
      }
      n_popped += int(popped.size());
      remove_indices(not_popped, popped);
    }
    unique_vector(laser_fired);
    for(int i = 0; i < int(laser_fired.size()); i++) cout << "Fire laser at " << laser_fired[i] << " degrees." << endl;
    if(n_popped == 0) cout << "No balloon burst." << endl;
    else if (n_popped == 1) cout << "1 burst balloon." << endl;
    else cout << n_popped << " burst balloons." << endl;
  }
  return 0;
}