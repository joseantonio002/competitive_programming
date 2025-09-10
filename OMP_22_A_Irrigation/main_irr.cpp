#include <bits/stdc++.h>
using namespace std;

map<string, int> di{
  {"L", 0},
  {"M", 1},
  {"X", 2},
  {"J", 3},
  {"V", 4},
  {"S", 5},
  {"D", 6}
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<int> output(M, 0);
  while(N--) {
    string sd, st, ed, et;
    cin >> sd >> st >> ed >> et;
    string sh, sm, eh, em;
    int shour, smin, ehour, emin;
    int halfs = st.find(':'), halfe = et.find(':');
    shour = stoi(st.substr(0, halfs));
    smin = stoi(st.substr(halfs + 1, int(st.size()) - halfs));
    ehour = stoi(et.substr(0, halfe));
    emin = stoi(et.substr(halfe + 1, int(et.size()) - halfe));

    int spos = (di.at(sd) * 24 * 60) + (60 * shour) + (smin);
    int epos = ((di.at(ed) * 24 * 60) + (60 * ehour) + emin) - 1;
    if(spos >= M) continue;
    else if (epos >= M) {
      for(int i = spos; i < M; i++) output.at(i) = 1;
    }
    else {
      for(int i = spos; i <= epos; i++) output.at(i) = 1;
    }
  }
  for(int x : output) cout << x;
  cout << endl;
  return 0;
}