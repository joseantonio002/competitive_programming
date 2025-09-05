#include <bits/stdc++.h>
using namespace std;

int count_dist(string s) {
    vector<char> unique;
    int dist = 0;
    for(int i = 1; i < int(s.size()); i++) { //start at i = 1 because the first letter is the one we matched
        char c = s.at(i);
        if (find(unique.begin(), unique.end(), c) == unique.end()) {
            unique.push_back(c);
            dist++;
        }
    }
    return dist;
}



int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while(true) {
    string s;
    map<char, int> last_pos;
    cin >> s;
    if (s == "0") break;

    double avg = 0;
    int count_ref = 0;

    for(int i = 0; i < int(s.size()); i++) {
        char c = s.at(i);
        if(last_pos.find(c) == last_pos.end()) { // primera vez que encuentro la letra
            last_pos[c] = i;
        } else { 
            count_ref++;
            avg += count_dist(s.substr(last_pos[c], i - last_pos[c]));
            last_pos[c] = i;
        }
    }
    if (count_ref == 0) {
        cout << "NaN" << endl;
    } else {
        cout << fixed << setprecision(4) << avg / count_ref << endl;
    }
  }

  return 0;
}